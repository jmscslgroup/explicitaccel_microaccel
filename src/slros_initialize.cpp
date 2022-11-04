#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "explicitaccel_microaccel";

// For Block explicitaccel_microaccel/MicroAccel/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_599;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe4
SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_624;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_562;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe8
SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_559;

// For Block explicitaccel_microaccel/MicroAccel/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist> Pub_explicitaccel_microaccel_592;

// For Block explicitaccel_microaccel/MicroAccel/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_609;

// For Block explicitaccel_microaccel/MicroAccel/Publish3
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_610;

// For Block explicitaccel_microaccel/MicroAccel/Publish4
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_611;

// For Block explicitaccel_microaccel/MicroAccel/Publish5
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_612;

// For Block explicitaccel_microaccel/MicroAccel/Publish6
SimulinkPublisher<std_msgs::Bool, SL_Bus_explicitaccel_microaccel_std_msgs_Bool> Pub_explicitaccel_microaccel_635;

// For Block explicitaccel_microaccel/MicroAccel/Publish7
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_654;

// For Block explicitaccel_microaccel/MicroAccel/Publish8
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_657;

// For Block explicitaccel_microaccel/MicroAccel/Publish9
SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_660;

// For Block explicitaccel_microaccel/MicroAccel/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_explicitaccel_microaccel_585;

// For Block explicitaccel_microaccel/MicroAccel/Get Parameter1
SimulinkParameterGetter<boolean_T, bool> ParamGet_explicitaccel_microaccel_631;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

