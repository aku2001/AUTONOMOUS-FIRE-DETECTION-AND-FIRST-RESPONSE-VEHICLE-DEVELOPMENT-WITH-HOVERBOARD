// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "hoverboard_msgs/msg/detail/temp_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace hoverboard_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TempMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) hoverboard_msgs::msg::TempMsg(_init);
}

void TempMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<hoverboard_msgs::msg::TempMsg *>(message_memory);
  typed_message->~TempMsg();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TempMsg_message_member_array[3] = {
  {
    "temp1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hoverboard_msgs::msg::TempMsg, temp1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "temp2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hoverboard_msgs::msg::TempMsg, temp2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hoverboard_msgs::msg::TempMsg, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TempMsg_message_members = {
  "hoverboard_msgs::msg",  // message namespace
  "TempMsg",  // message name
  3,  // number of fields
  sizeof(hoverboard_msgs::msg::TempMsg),
  TempMsg_message_member_array,  // message members
  TempMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  TempMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TempMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TempMsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace hoverboard_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hoverboard_msgs::msg::TempMsg>()
{
  return &::hoverboard_msgs::msg::rosidl_typesupport_introspection_cpp::TempMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hoverboard_msgs, msg, TempMsg)() {
  return &::hoverboard_msgs::msg::rosidl_typesupport_introspection_cpp::TempMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
