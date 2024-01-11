// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice
#include "hoverboard_msgs/msg/detail/temp_msg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "hoverboard_msgs/msg/detail/temp_msg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace hoverboard_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hoverboard_msgs
cdr_serialize(
  const hoverboard_msgs::msg::TempMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: temp1
  cdr << ros_message.temp1;
  // Member: temp2
  cdr << ros_message.temp2;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hoverboard_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  hoverboard_msgs::msg::TempMsg & ros_message)
{
  // Member: temp1
  cdr >> ros_message.temp1;

  // Member: temp2
  cdr >> ros_message.temp2;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hoverboard_msgs
get_serialized_size(
  const hoverboard_msgs::msg::TempMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: temp1
  {
    size_t item_size = sizeof(ros_message.temp1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp2
  {
    size_t item_size = sizeof(ros_message.temp2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_hoverboard_msgs
max_serialized_size_TempMsg(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: temp1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: temp2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TempMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const hoverboard_msgs::msg::TempMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TempMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<hoverboard_msgs::msg::TempMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TempMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const hoverboard_msgs::msg::TempMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TempMsg__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_TempMsg(full_bounded, 0);
}

static message_type_support_callbacks_t _TempMsg__callbacks = {
  "hoverboard_msgs::msg",
  "TempMsg",
  _TempMsg__cdr_serialize,
  _TempMsg__cdr_deserialize,
  _TempMsg__get_serialized_size,
  _TempMsg__max_serialized_size
};

static rosidl_message_type_support_t _TempMsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TempMsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace hoverboard_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_hoverboard_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<hoverboard_msgs::msg::TempMsg>()
{
  return &hoverboard_msgs::msg::typesupport_fastrtps_cpp::_TempMsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hoverboard_msgs, msg, TempMsg)() {
  return &hoverboard_msgs::msg::typesupport_fastrtps_cpp::_TempMsg__handle;
}

#ifdef __cplusplus
}
#endif
