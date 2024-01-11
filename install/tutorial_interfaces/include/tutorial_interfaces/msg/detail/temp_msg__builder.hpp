// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/TempMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/temp_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_TempMsg_temp2
{
public:
  explicit Init_TempMsg_temp2(::tutorial_interfaces::msg::TempMsg & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::TempMsg temp2(::tutorial_interfaces::msg::TempMsg::_temp2_type arg)
  {
    msg_.temp2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::TempMsg msg_;
};

class Init_TempMsg_temp1
{
public:
  Init_TempMsg_temp1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TempMsg_temp2 temp1(::tutorial_interfaces::msg::TempMsg::_temp1_type arg)
  {
    msg_.temp1 = std::move(arg);
    return Init_TempMsg_temp2(msg_);
  }

private:
  ::tutorial_interfaces::msg::TempMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::TempMsg>()
{
  return tutorial_interfaces::msg::builder::Init_TempMsg_temp1();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__BUILDER_HPP_
