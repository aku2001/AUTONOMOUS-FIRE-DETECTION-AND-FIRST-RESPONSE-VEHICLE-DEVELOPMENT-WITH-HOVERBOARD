// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from hoverboard_msgs:msg/SonarMsg.idl
// generated code does not contain a copyright notice
#include "hoverboard_msgs/msg/detail/sonar_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "hoverboard_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "hoverboard_msgs/msg/detail/sonar_msg__struct.h"
#include "hoverboard_msgs/msg/detail/sonar_msg__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SonarMsg__ros_msg_type = hoverboard_msgs__msg__SonarMsg;

static bool _SonarMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SonarMsg__ros_msg_type * ros_message = static_cast<const _SonarMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: sonar1
  {
    cdr << ros_message->sonar1;
  }

  // Field name: sonar2
  {
    cdr << ros_message->sonar2;
  }

  // Field name: sonar3
  {
    cdr << ros_message->sonar3;
  }

  // Field name: sonar4
  {
    cdr << ros_message->sonar4;
  }

  // Field name: sonar5
  {
    cdr << ros_message->sonar5;
  }

  return true;
}

static bool _SonarMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SonarMsg__ros_msg_type * ros_message = static_cast<_SonarMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: sonar1
  {
    cdr >> ros_message->sonar1;
  }

  // Field name: sonar2
  {
    cdr >> ros_message->sonar2;
  }

  // Field name: sonar3
  {
    cdr >> ros_message->sonar3;
  }

  // Field name: sonar4
  {
    cdr >> ros_message->sonar4;
  }

  // Field name: sonar5
  {
    cdr >> ros_message->sonar5;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hoverboard_msgs
size_t get_serialized_size_hoverboard_msgs__msg__SonarMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SonarMsg__ros_msg_type * ros_message = static_cast<const _SonarMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name sonar1
  {
    size_t item_size = sizeof(ros_message->sonar1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sonar2
  {
    size_t item_size = sizeof(ros_message->sonar2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sonar3
  {
    size_t item_size = sizeof(ros_message->sonar3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sonar4
  {
    size_t item_size = sizeof(ros_message->sonar4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sonar5
  {
    size_t item_size = sizeof(ros_message->sonar5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SonarMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_hoverboard_msgs__msg__SonarMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_hoverboard_msgs
size_t max_serialized_size_hoverboard_msgs__msg__SonarMsg(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: sonar1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sonar2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sonar3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sonar4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: sonar5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _SonarMsg__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_hoverboard_msgs__msg__SonarMsg(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SonarMsg = {
  "hoverboard_msgs::msg",
  "SonarMsg",
  _SonarMsg__cdr_serialize,
  _SonarMsg__cdr_deserialize,
  _SonarMsg__get_serialized_size,
  _SonarMsg__max_serialized_size
};

static rosidl_message_type_support_t _SonarMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SonarMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, hoverboard_msgs, msg, SonarMsg)() {
  return &_SonarMsg__type_support;
}

#if defined(__cplusplus)
}
#endif