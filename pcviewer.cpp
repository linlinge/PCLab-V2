#include "pcviewer.h"
#include "ui_pcviewer.h"
#include "QMessageBox"
#include "denoisingmodule.h"

PCViewer::PCViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCViewer)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    // add progress bar
    progress_bar_=new QProgressBar();
    progress_bar_->setTextVisible(false);
    progress_bar_->setRange(0,100);
    ui->statusBar->addWidget(progress_bar_);



    // load config file
    config = new QSettings("config.ini",QSettings::IniFormat);

    /*config->beginGroup("config");
    config->setValue("filename", "/home/henry/");
    config->endGroup();*/

    QString str=config->value("config/filename").toString();

    // progress bar
    progress_bar_->setValue(0);

    // Set up the QVTK window
    viewer_.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    viewer_->setBackgroundColor (0.1, 0.1, 0.1);
    ui->widget->SetRenderWindow (viewer_->getRenderWindow ());
    viewer_->setupInteractor (ui->widget->GetInteractor (), ui->widget->GetRenderWindow ());

    //
    cloud_=NULL;


    //

}

PCViewer::~PCViewer()
{
    delete ui;
}

void PCViewer::on_actionColor_changed()
{
   if(ui->actionColor->isChecked()==true)
       colorCloudDistances(1);
   else
       colorCloudDistances(0);

   viewer_->updatePointCloud (cloud_, "cloud");
   ui->widget->update ();
}


void PCViewer::colorCloudDistances (int color_mode)
{
    if(color_mode==0)
    {
        pcl::visualization::PointCloudColorHandlerCustom<PointType> single_color(cloud_, 255, 255, 255);
        viewer_->addPointCloud (cloud_,single_color, "cloud");
        ui->widget->update ();
        return;
    }
  // Find the minimum and maximum values along the selected axis
  double min, max;
  min = cloud_->points[0].x;
  max = cloud_->points[0].x;

  // Search for the minimum/maximum
  for (pcl::PointCloud<PointType>::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
        if (min > cloud_it->x)
          min = cloud_it->x;

        if (max < cloud_it->x)
          max = cloud_it->x;
  }

  // Compute LUT scaling to fit the full histogram spectrum
  double lut_scale = 255.0 / (max - min);  // max is 255, min is 0

  if (min == max)  // In case the cloud is flat on the chosen direction (x,y or z)
    lut_scale = 1.0;  // Avoid rounding error in boost




  for (pcl::PointCloud<PointType>::iterator cloud_it = cloud_->begin (); cloud_it != cloud_->end (); ++cloud_it)
  {
    if(color_mode==1)
    {
        int value = std::lround ( (cloud_it->x - min) * lut_scale);  // Round the number to the closest integer
        // Apply color to the cloud
        // Blue -> Green -> Red (~ rainbow)
        cloud_it->r = value > 128 ? (value - 128) * 2 : 0;  // r[128] = 0, r[255] = 255
        cloud_it->g = value < 128 ? 2 * value : 255 - ( (value - 128) * 2);  // g[0] = 0, g[128] = 255, g[255] = 0
        cloud_it->b = value < 128 ? 255 - (2 * value) : 0;  // b[0] = 255, b[128] = 0
    }
    else
    {
        cloud_it->r = 255;
        cloud_it->g = 255;
        cloud_it->b = 255;
    }

  }
}

void PCViewer::on_actionOpen_triggered()
{
   LoadFile();
}

void PCViewer::LoadFile()
{
    cloud_=pcl::PointCloud<PointType>::Ptr(new pcl::PointCloud<PointType>);
    // You might want to change "/home/" if you're not on an *nix platform
    QString filename = QFileDialog::getOpenFileName (this, tr ("Open point cloud"), "/home/", tr ("Point cloud data (*.pcd *.ply)"));
    progress_bar_->setValue(10);

    PCL_INFO("File chosen: %s\n", filename.toStdString ().c_str ());
    pcl::PointCloud<PointType>::Ptr cloud_tmp (new pcl::PointCloud<PointType>);

    if (filename.isEmpty ())
      return;

    int return_status;
    if (filename.endsWith (".pcd", Qt::CaseInsensitive))
      return_status = pcl::io::loadPCDFile (filename.toStdString (), *cloud_tmp);
    else if(filename.endsWith (".ply", Qt::CaseInsensitive))
      return_status = pcl::io::loadPLYFile (filename.toStdString (), *cloud_tmp);
    else{
        QMessageBox::warning(this,"Error","Load File Format Error!");
        return;
    }


    progress_bar_->setValue(20);

    if (return_status != 0)
    {
      PCL_ERROR("Error reading point cloud %s\n", filename.toStdString ().c_str ());
      return;
    }

    progress_bar_->setValue(30);
    // If point cloud contains NaN values, remove them before updating the visualizer point cloud
    if (cloud_tmp->is_dense)
      pcl::copyPointCloud (*cloud_tmp, *cloud_);
    else
    {
      PCL_WARN("Cloud is not dense! Non finite points will be removed\n");
      std::vector<int> vec;
      pcl::removeNaNFromPointCloud (*cloud_tmp, *cloud_, vec);
    }

    colorCloudDistances (1);
    viewer_->addPointCloud (cloud_, "cloud");
    viewer_->updatePointCloud (cloud_, "cloud");
    viewer_->resetCamera ();
    ui->widget->update();
    progress_bar_->setValue(100);
}

void PCViewer::on_actionReload_triggered()
{

}

void PCViewer::on_actionStatistical_Removal_triggered()
{
    gOutlierRemoval.setWindowTitle("Outlier Removal");
    gOutlierRemoval.show();
    connect(&gOutlierRemoval,SIGNAL(SendStatisticalParameter(int,float)),this,SLOT(remove_outlier(int,float)));
}

void PCViewer::on_actionAbout_triggered()
{
    pAbout=new About(this);
    pAbout->setWindowTitle("About PCLab");
    pAbout->show();
}

void PCViewer::remove_outlier(int k, float nSigma)
{
    if(cloud_!=NULL){
        OutlierRemoval sor;
        sor.StatisticOutlierRemoval(cloud_,k,nSigma);

        qDebug("%d",sor.cloud_filtered_->points.size());
        updateViewer(sor.cloud_filtered_);
    }
    else{
         QMessageBox::warning(this,"Warning","No cloud Available");
    }
}

void PCViewer::updateViewer(pcl::PointCloud<PointType>::Ptr cloud)
{

    viewer_->addPointCloud (cloud, "cloud");
    viewer_->updatePointCloud (cloud, "cloud");
    //viewer_->resetCamera ();
    ui->widget->update();
}
