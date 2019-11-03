#ifndef DENOISINGMODULE_H
#define DENOISINGMODULE_H
#include "global.h"

//#include <CGAL/Simple_cartesian.h>
//#include <CGAL/wlop_simplify_and_regularize_point_set.h>
//#include <CGAL/IO/read_ply_points.h>


using namespace pcl;

class DenoisingModule
{
private:
    PointCloud<PointXYZRGBA>::Ptr cloud_;

public:
    DenoisingModule();
    void SetInputCloud(PointCloud<PointXYZRGBA>::Ptr cloud);
    void pass_through_filter(PointCloud<PointXYZRGBA>::Ptr cloud);
};

#endif // DENOISINGMODULE_H
