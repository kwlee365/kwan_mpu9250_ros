#include <sensor_msgs/Imu.h>
#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

void CallbackIMUdata(const sensor_msgs::Imu imu_msg)
{
    static tf2_ros::TransformBroadcaster br;
    geometry_msgs::TransformStamped tr;

    tr.header.stamp = ros::Time::now();
    tr.header.frame_id = "map";
    tr.child_frame_id = "imu_link";
    tr.transform.translation.x = 0.0;
    tr.transform.translation.y = 0.0;
    tr.transform.translation.z = 3.0;

    // tf2::Quaternion q;

    tr.transform.rotation.x = imu_msg.orientation.x;
    tr.transform.rotation.y = imu_msg.orientation.y;
    tr.transform.rotation.z = imu_msg.orientation.z;
    tr.transform.rotation.w = imu_msg.orientation.w;

    br.sendTransform(tr);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "imu_tf_broadcaster");
    ros::NodeHandle nh_;

    ros::Subscriber imu_sub = nh_.subscribe("/imu/data", 10, &CallbackIMUdata);

    ros::spin();
    return 0;
};
