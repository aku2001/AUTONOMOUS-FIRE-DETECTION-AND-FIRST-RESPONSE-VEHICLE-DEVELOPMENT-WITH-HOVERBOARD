// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice

#ifndef HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__STRUCT_H_
#define HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TempMsg in the package hoverboard_msgs.
typedef struct hoverboard_msgs__msg__TempMsg
{
  int64_t temp1;
  int64_t temp2;
} hoverboard_msgs__msg__TempMsg;

// Struct for a sequence of hoverboard_msgs__msg__TempMsg.
typedef struct hoverboard_msgs__msg__TempMsg__Sequence
{
  hoverboard_msgs__msg__TempMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hoverboard_msgs__msg__TempMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOVERBOARD_MSGS__MSG__DETAIL__TEMP_MSG__STRUCT_H_
