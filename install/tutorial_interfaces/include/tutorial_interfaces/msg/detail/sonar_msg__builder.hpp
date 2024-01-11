// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/SonarMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__SONAR_MSG__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__SONAR_MSG__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/sonar_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_SonarMsg_sonar5
{
public:
  explicit Init_SonarMsg_sonar5(::tutorial_interfaces::msg::SonarMsg & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::SonarMsg sonar5(::tutorial_interfaces::msg::SonarMsg::_sonar5_type arg)
  {
    msg_.sonar5 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::SonarMsg msg_;
};

class Init_SonarMsg_sonar4
{
public:
  explicit Init_SonarMsg_sonar4(::tutorial_interfaces::msg::SonarMsg & msg)
  : msg_(msg)
  {}
  Init_SonarMsg_sonar5 sonar4(::tutorial_interfaces::msg::SonarMsg::_sonar4_type arg)
  {
    msg_.sonar4 = std::move(arg);
    return Init_SonarMsg_sonar5(msg_);
  }

private:
  ::tutorial_interfaces::msg::SonarMsg msg_;
};

class Init_SonarMsg_sonar3
{
public:
  explicit Init_SonarMsg_sonar3(::tutorial_interfaces::msg::SonarMsg & msg)
  : msg_(msg)
  {}
  Init_SonarMsg_sonar4 sonar3(::tutorial_interfaces::msg::SonarMsg::_sonar3_type arg)
  {
    msg_.sonar3 = std::move(arg);
    return Init_SonarMsg_sonar4(msg_);
  }

private:
  ::tutorial_interfaces::msg::SonarMsg msg_;
};

class Init_SonarMsg_sonar2
{
public:
  explicit Init_SonarMsg_sonar2(::tutorial_interfaces::msg::SonarMsg & msg)
  : msg_(msg)
  {}
  Init_SonarMsg_sonar3 sonar2(::tutorial_interfaces::msg::SonarMsg::_sonar2_type arg)
  {
    msg_.sonar2 = std::move(arg);
    return Init_SonarMsg_sonar3(msg_);
  }

private:
  ::tutorial_interfaces::msg::SonarMsg msg_;
};

class Init_SonarMsg_sonar1
{
public:
  Init_SonarMsg_sonar1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SonarMsg_sonar2 sonar1(::tutorial_interfaces::msg::SonarMsg::_sonar1_type arg)
  {
    msg_.sonar1 = std::move(arg);
    return Init_SonarMsg_sonar2(msg_);
  }

private:
  ::tutorial_interfaces::msg::SonarMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::SonarMsg>()
{
  return tutorial_interfaces::msg::builder::Init_SonarMsg_sonar1();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__SONAR_MSG__BUILDER_HPP_
