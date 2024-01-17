// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "hoverboard_msgs/msg/detail/temp_msg__rosidl_typesupport_introspection_c.h"
#include "hoverboard_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "hoverboard_msgs/msg/detail/temp_msg__functions.h"
#include "hoverboard_msgs/msg/detail/temp_msg__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TempMsg__rosidl_typesupport_introspection_c__TempMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  hoverboard_msgs__msg__TempMsg__init(message_memory);
}

void TempMsg__rosidl_typesupport_introspection_c__TempMsg_fini_function(void * message_memory)
{
  hoverboard_msgs__msg__TempMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_member_array[3] = {
  {
    "temp1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hoverboard_msgs__msg__TempMsg, temp1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hoverboard_msgs__msg__TempMsg, temp2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(hoverboard_msgs__msg__TempMsg, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_members = {
  "hoverboard_msgs__msg",  // message namespace
  "TempMsg",  // message name
  3,  // number of fields
  sizeof(hoverboard_msgs__msg__TempMsg),
  TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_member_array,  // message members
  TempMsg__rosidl_typesupport_introspection_c__TempMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  TempMsg__rosidl_typesupport_introspection_c__TempMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_type_support_handle = {
  0,
  &TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_hoverboard_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, hoverboard_msgs, msg, TempMsg)() {
  TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_type_support_handle.typesupport_identifier) {
    TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TempMsg__rosidl_typesupport_introspection_c__TempMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
