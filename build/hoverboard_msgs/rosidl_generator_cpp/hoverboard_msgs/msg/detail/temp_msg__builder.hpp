// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice

#ifndef HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__BUILDER_HPP_
#define HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__BUILDER_HPP_

#include "hoverboard_msgs/msg/detail/temp_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace hoverboard_msgs
{

namespace msg
{

namespace builder
{

class Init_TempMsg_stamp
{
public:
  explicit Init_TempMsg_stamp(::hoverboard_msgs::msg::TempMsg & msg)
  : msg_(msg)
  {}
  ::hoverboard_msgs::msg::TempMsg stamp(::hoverboard_msgs::msg::TempMsg::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hoverboard_msgs::msg::TempMsg msg_;
};

class Init_TempMsg_temp2
{
public:
  explicit Init_TempMsg_temp2(::hoverboard_msgs::msg::TempMsg & msg)
  : msg_(msg)
  {}
  Init_TempMsg_stamp temp2(::hoverboard_msgs::msg::TempMsg::_temp2_type arg)
  {
    msg_.temp2 = std::move(arg);
    return Init_TempMsg_stamp(msg_);
  }

private:
  ::hoverboard_msgs::msg::TempMsg msg_;
};

class Init_TempMsg_temp1
{
public:
  Init_TempMsg_temp1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TempMsg_temp2 temp1(::hoverboard_msgs::msg::TempMsg::_temp1_type arg)
  {
    msg_.temp1 = std::move(arg);
    return Init_TempMsg_temp2(msg_);
  }

private:
  ::hoverboard_msgs::msg::TempMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::hoverboard_msgs::msg::TempMsg>()
{
  return hoverboard_msgs::msg::builder::Init_TempMsg_temp1();
}

}  // namespace hoverboard_msgs

#endif  // HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__BUILDER_HPP_
