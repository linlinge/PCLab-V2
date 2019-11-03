#include "denoisingmodule.h"
#include <pcl/filters/passthrough.h>

DenoisingModule::DenoisingModule()
{
    // cloud_filterd_.reset(new PointCloud<PointXYZRGBA>);
}

void DenoisingModule::SetInputCloud(PointCloud<PointXYZRGBA>::Ptr cloud)
{
    cloud_=cloud;
}

 void DenoisingModule::pass_through_filter(PointCloud<PointXYZRGBA>::Ptr cloud_filterd_)
 {
    // create the filtering object
     pcl::PassThrough<PointXYZRGBA> pass;
     pass.setInputCloud(cloud_);
     pass.setFilterFieldName("z");
     pass.setFilterLimits(0.0,1.0);
     pass.filter(*cloud_filterd_);
 }
