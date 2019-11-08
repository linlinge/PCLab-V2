#pragma once
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/octree/octree.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <omp.h>
#include <qdebug.h>

#ifndef PointType
#define PointType pcl::PointXYZRGB
#endif
using namespace std;
class OutlierRemoval{
public:
    pcl::PointCloud<PointType>::Ptr cloud_filtered_;
    pcl::PointCloud<PointType>::Ptr cloud_outlier_;
    void StatisticOutlierRemoval(pcl::PointCloud<PointType>::Ptr cloud,int k=4, float multi=2.0f);
};
