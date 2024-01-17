// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice

#ifndef HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__TRAITS_HPP_
#define HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__TRAITS_HPP_

#include "hoverboard_msgs/msg/detail/temp_msg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hoverboard_msgs::msg::TempMsg>()
{
  return "hoverboard_msgs::msg::TempMsg";
}

template<>
inline const char * name<hoverboard_msgs::msg::TempMsg>()
{
  return "hoverboard_msgs/msg/TempMsg";
}

template<>
struct has_fixed_size<hoverboard_msgs::msg::TempMsg>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<hoverboard_msgs::msg::TempMsg>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<hoverboard_msgs::msg::TempMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__TRAITS_HPP_
