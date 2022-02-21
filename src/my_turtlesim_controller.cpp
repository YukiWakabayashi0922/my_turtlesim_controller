#include "my_tuetlesim_controller/my_turtle_control.h"

MyTurtlesimController::MyTurtlesimController():private_nh_("~"), nh_("")
{
    private_nh_.param("hz", hz_, {10});

    pub_cmd_vel_ = nh_.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
    sub_pose_ = nh_.subscribe("/turtle1/pose", 10, &MyTurtlesimController::pose_callback, this);
}

void MyTurtlesimController::pose_callback(const turtlesim::Pose::ConstPtr &msg)
{
    current_pose_ = *msg;
}

void MyTurtlesimController::straight()
{
    cmd_vel_.linear.x = 0.5;
}

void MyTurtlesimController::turn()
{
    cmd_vel_.angular.z = 0.5;
}

void MyTurtlesimController::process()
{
    ros::Rate loop_rate(hz_);
    while(ros::ok)
    {
        straight();

        pub_cmd_vel_.publish(cmd_vel_);

        ros::spinOnce();
        loop_rate.sleep();
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_tuetlesim_controller");
    MyTurtlesimController kame;
    kame.process();
    return 0;
}
