#ifndef GLOBAL_H
#define GLOBAL_H

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/filter.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>

// Boost
#include <boost/math/special_functions/round.hpp>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

#include <QString>
#include <QSettings>

#ifndef PointType
#define PointType pcl::PointXYZRGB
#endif

// Variables
extern QSettings* config;

enum MethodsType{Outlier_Statistical,Outlier_Radius};
#endif // GLOBAL_H
