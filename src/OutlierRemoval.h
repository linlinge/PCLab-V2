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
#ifndef PointType
#define PointType pcl::PointXYZRGB
#endif
using namespace std;
class OutlierRemoval{
public:
    void StatisticOutlierRemoval(pcl::PointCloud<PointType>::Ptr cloud,int k, float threshould);
};
