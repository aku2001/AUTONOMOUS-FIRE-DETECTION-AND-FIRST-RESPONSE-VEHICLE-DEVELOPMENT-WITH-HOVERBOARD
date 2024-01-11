// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/TempMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TempMsg in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__TempMsg
{
  int64_t temp1;
  int64_t temp2;
} tutorial_interfaces__msg__TempMsg;

// Struct for a sequence of tutorial_interfaces__msg__TempMsg.
typedef struct tutorial_interfaces__msg__TempMsg__Sequence
{
  tutorial_interfaces__msg__TempMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__TempMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__STRUCT_H_
