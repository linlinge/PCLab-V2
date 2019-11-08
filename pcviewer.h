#ifndef PCVIEWER_H
#define PCVIEWER_H

#include <QMainWindow>
#include <QFileDialog>
#include "global.h"
#include "QProgressBar"
#include "about.h"
#include "gui_outlier_removal.h"
#include "src/OutlierRemoval.h"


namespace Ui {
class PCViewer;
}

class PCViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCViewer(QWidget *parent = 0);
    void colorCloudDistances (int color_mode);
    void LoadFile();
    ~PCViewer();

private:
    Ui::PCViewer *ui;
    QString filename_;
    QProgressBar* progress_bar_;
    About* pAbout;
    gui_outlier_removal gOutlierRemoval;

protected:
  /** @brief The PCL visualizer object */
  pcl::visualization::PCLVisualizer::Ptr viewer_;

  /** @brief The point cloud displayed */
  pcl::PointCloud<PointType>::Ptr cloud_;

private slots:
  void on_actionColor_changed();
  void on_actionOpen_triggered();
  void on_actionReload_triggered();
  void on_actionStatistical_Removal_triggered();
  void on_actionAbout_triggered();

  void remove_outlier(int k,float nSigma);

  void updateViewer(pcl::PointCloud<PointType>::Ptr cloud);
};

#endif // PCVIEWER_H
