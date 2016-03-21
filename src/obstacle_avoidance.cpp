#include<ros/ros.h>
#include <std_msgs/Float32.h>
#include<geometry_msgs/Twist.h>

ros::Publisher pub_Sonar;
geometry_msgs::Twist vel;

void callback(const std_msgs::Float32ConstPtr &msg)
{
    if(msg->data != 0)
    {
        vel.linear.x = 0;
        vel.angular.z = 1;
        pub_Sonar.publish(vel);
    }
    else
    {
        vel.linear.x = 0.4;
        vel.angular.z = 0;
        pub_Sonar.publish(vel);
    }
    
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"obstAvd");
    
    ros::NodeHandle node;
    
    pub_Sonar = node.advertise<geometry_msgs::Twist>("ros_Sonar",1);
    
    ros::Subscriber sub = node.subscribe("/vrep/vehicle/frontSonar",1,callback);
    
    ros::spin();
}