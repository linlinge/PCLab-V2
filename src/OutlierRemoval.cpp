#include "OutlierRemoval.h"
void OutlierRemoval::StatisticOutlierRemoval(pcl::PointCloud<PointType>::Ptr cloud, int k, float multi)
{
    // new cloud
    cloud_filtered_=pcl::PointCloud<PointType>::Ptr(new pcl::PointCloud<PointType>);
    cloud_outlier_=pcl::PointCloud<PointType>::Ptr(new pcl::PointCloud<PointType>);

    // Create the filtering object
    pcl::StatisticalOutlierRemoval<PointType> sor;
    sor.setInputCloud (cloud);
    sor.setMeanK (k);
    sor.setStddevMulThresh (multi);
    sor.filter(*cloud_filtered_);
    sor.setNegative (true);
    sor.filter(*cloud_outlier_);
    qDebug("%d",cloud->points.size());
}
