#include "OutlierRemoval.h"
void OutlierRemoval::StatisticOutlierRemoval(pcl::PointCloud<PointType>::Ptr cloud, int k, float threshould)
{
    pcl::PointCloud<PointType>::Ptr cloud_filtered (new pcl::PointCloud<PointType>);
    pcl::PointCloud<PointType>::Ptr cloud_outlier (new pcl::PointCloud<PointType>);

    // Create the filtering object
    pcl::StatisticalOutlierRemoval<PointType> sor;
    sor.setInputCloud (cloud);
    sor.setMeanK (30);
    sor.setStddevMulThresh (10.0);
    sor.filter(*cloud_filtered);

    sor.setNegative (true);
    sor.filter(*cloud_outlier);
}
