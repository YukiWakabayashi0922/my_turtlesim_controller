#ifndef MY_TURTLESIM_CONTROLLER_H
#define MY_TURTLESIM_CONTROLLER_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

class MyTurtlesimController
{
    public:
        MyTurtlesimController();
        void process();

    private:
        void pose_callback(const turtlesim::Pose::ConstPtr &msg);

        void straight();
        void turn();

        int hz_;

        ros::NodeHandle nh_;
        ros::NodeHandle private_nh_;
        ros::Publisher pub_cmd_vel_;
        ros::Subscriber sub_pose_;

        turtlesim::Pose current_pose_;
        geometry_msgs::Twist cmd_vel_;
};

#endif
