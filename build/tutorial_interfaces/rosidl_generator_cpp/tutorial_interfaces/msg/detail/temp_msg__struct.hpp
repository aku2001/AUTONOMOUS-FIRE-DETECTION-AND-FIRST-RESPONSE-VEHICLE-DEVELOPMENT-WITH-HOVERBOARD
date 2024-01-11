// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/TempMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__TempMsg __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__TempMsg __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TempMsg_
{
  using Type = TempMsg_<ContainerAllocator>;

  explicit TempMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp1 = 0ll;
      this->temp2 = 0ll;
    }
  }

  explicit TempMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp1 = 0ll;
      this->temp2 = 0ll;
    }
  }

  // field types and members
  using _temp1_type =
    int64_t;
  _temp1_type temp1;
  using _temp2_type =
    int64_t;
  _temp2_type temp2;

  // setters for named parameter idiom
  Type & set__temp1(
    const int64_t & _arg)
  {
    this->temp1 = _arg;
    return *this;
  }
  Type & set__temp2(
    const int64_t & _arg)
  {
    this->temp2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::TempMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::TempMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::TempMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::TempMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__TempMsg
    std::shared_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__TempMsg
    std::shared_ptr<tutorial_interfaces::msg::TempMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TempMsg_ & other) const
  {
    if (this->temp1 != other.temp1) {
      return false;
    }
    if (this->temp2 != other.temp2) {
      return false;
    }
    return true;
  }
  bool operator!=(const TempMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TempMsg_

// alias to use template instance with default allocator
using TempMsg =
  tutorial_interfaces::msg::TempMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__TEMP_MSG__STRUCT_HPP_
