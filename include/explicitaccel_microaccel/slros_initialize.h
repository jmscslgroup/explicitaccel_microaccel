#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"
#include "explicitaccel_microaccel_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_599;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe4
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_624;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_562;

// For Block explicitaccel_microaccel/MicroAccel/Subscribe8
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Sub_explicitaccel_microaccel_559;

// For Block explicitaccel_microaccel/MicroAccel/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_explicitaccel_microaccel_geometry_msgs_Twist> Pub_explicitaccel_microaccel_592;

// For Block explicitaccel_microaccel/MicroAccel/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_609;

// For Block explicitaccel_microaccel/MicroAccel/Publish3
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_610;

// For Block explicitaccel_microaccel/MicroAccel/Publish4
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_611;

// For Block explicitaccel_microaccel/MicroAccel/Publish5
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_612;

// For Block explicitaccel_microaccel/MicroAccel/Publish6
extern SimulinkPublisher<std_msgs::Bool, SL_Bus_explicitaccel_microaccel_std_msgs_Bool> Pub_explicitaccel_microaccel_635;

// For Block explicitaccel_microaccel/MicroAccel/Publish7
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_654;

// For Block explicitaccel_microaccel/MicroAccel/Publish8
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_657;

// For Block explicitaccel_microaccel/MicroAccel/Publish9
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_explicitaccel_microaccel_std_msgs_Float64> Pub_explicitaccel_microaccel_660;

// For Block explicitaccel_microaccel/MicroAccel/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_explicitaccel_microaccel_585;

// For Block explicitaccel_microaccel/MicroAccel/Get Parameter1
extern SimulinkParameterGetter<boolean_T, bool> ParamGet_explicitaccel_microaccel_631;

void slros_node_init(int argc, char** argv);

#endif
