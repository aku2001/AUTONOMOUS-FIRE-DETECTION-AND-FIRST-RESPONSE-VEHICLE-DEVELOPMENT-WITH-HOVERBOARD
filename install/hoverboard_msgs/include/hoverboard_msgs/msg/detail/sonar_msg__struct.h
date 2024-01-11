// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hoverboard_msgs:msg/SonarMsg.idl
// generated code does not contain a copyright notice

#ifndef HOVERBOARD_MSGS__MSG__DETAIL__SONAR_MSG__STRUCT_H_
#define HOVERBOARD_MSGS__MSG__DETAIL__SONAR_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SonarMsg in the package hoverboard_msgs.
typedef struct hoverboard_msgs__msg__SonarMsg
{
  int64_t sonar1;
  int64_t sonar2;
  int64_t sonar3;
  int64_t sonar4;
  int64_t sonar5;
} hoverboard_msgs__msg__SonarMsg;

// Struct for a sequence of hoverboard_msgs__msg__SonarMsg.
typedef struct hoverboard_msgs__msg__SonarMsg__Sequence
{
  hoverboard_msgs__msg__SonarMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hoverboard_msgs__msg__SonarMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOVERBOARD_MSGS__MSG__DETAIL__SONAR_MSG__STRUCT_H_
