// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "hoverboard_msgs/msg/detail/temp_msg__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace hoverboard_msgs
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _TempMsg_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TempMsg_type_support_ids_t;

static const _TempMsg_type_support_ids_t _TempMsg_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TempMsg_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TempMsg_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TempMsg_type_support_symbol_names_t _TempMsg_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, hoverboard_msgs, msg, TempMsg)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, hoverboard_msgs, msg, TempMsg)),
  }
};

typedef struct _TempMsg_type_support_data_t
{
  void * data[2];
} _TempMsg_type_support_data_t;

static _TempMsg_type_support_data_t _TempMsg_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TempMsg_message_typesupport_map = {
  2,
  "hoverboard_msgs",
  &_TempMsg_message_typesupport_ids.typesupport_identifier[0],
  &_TempMsg_message_typesupport_symbol_names.symbol_name[0],
  &_TempMsg_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TempMsg_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TempMsg_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace hoverboard_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<hoverboard_msgs::msg::TempMsg>()
{
  return &::hoverboard_msgs::msg::rosidl_typesupport_cpp::TempMsg_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, hoverboard_msgs, msg, TempMsg)() {
  return get_message_type_support_handle<hoverboard_msgs::msg::TempMsg>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp