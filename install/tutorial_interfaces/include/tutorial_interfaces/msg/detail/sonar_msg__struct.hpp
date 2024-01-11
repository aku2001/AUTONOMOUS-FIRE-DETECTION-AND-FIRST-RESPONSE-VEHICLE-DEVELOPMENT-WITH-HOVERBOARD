// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/SonarMsg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__SONAR_MSG__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__SONAR_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__SonarMsg __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__SonarMsg __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SonarMsg_
{
  using Type = SonarMsg_<ContainerAllocator>;

  explicit SonarMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sonar1 = 0ll;
      this->sonar2 = 0ll;
      this->sonar3 = 0ll;
      this->sonar4 = 0ll;
      this->sonar5 = 0ll;
    }
  }

  explicit SonarMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sonar1 = 0ll;
      this->sonar2 = 0ll;
      this->sonar3 = 0ll;
      this->sonar4 = 0ll;
      this->sonar5 = 0ll;
    }
  }

  // field types and members
  using _sonar1_type =
    int64_t;
  _sonar1_type sonar1;
  using _sonar2_type =
    int64_t;
  _sonar2_type sonar2;
  using _sonar3_type =
    int64_t;
  _sonar3_type sonar3;
  using _sonar4_type =
    int64_t;
  _sonar4_type sonar4;
  using _sonar5_type =
    int64_t;
  _sonar5_type sonar5;

  // setters for named parameter idiom
  Type & set__sonar1(
    const int64_t & _arg)
  {
    this->sonar1 = _arg;
    return *this;
  }
  Type & set__sonar2(
    const int64_t & _arg)
  {
    this->sonar2 = _arg;
    return *this;
  }
  Type & set__sonar3(
    const int64_t & _arg)
  {
    this->sonar3 = _arg;
    return *this;
  }
  Type & set__sonar4(
    const int64_t & _arg)
  {
    this->sonar4 = _arg;
    return *this;
  }
  Type & set__sonar5(
    const int64_t & _arg)
  {
    this->sonar5 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::SonarMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::SonarMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::SonarMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::SonarMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__SonarMsg
    std::shared_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__SonarMsg
    std::shared_ptr<tutorial_interfaces::msg::SonarMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SonarMsg_ & other) const
  {
    if (this->sonar1 != other.sonar1) {
      return false;
    }
    if (this->sonar2 != other.sonar2) {
      return false;
    }
    if (this->sonar3 != other.sonar3) {
      return false;
    }
    if (this->sonar4 != other.sonar4) {
      return false;
    }
    if (this->sonar5 != other.sonar5) {
      return false;
    }
    return true;
  }
  bool operator!=(const SonarMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SonarMsg_

// alias to use template instance with default allocator
using SonarMsg =
  tutorial_interfaces::msg::SonarMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__SONAR_MSG__STRUCT_HPP_
