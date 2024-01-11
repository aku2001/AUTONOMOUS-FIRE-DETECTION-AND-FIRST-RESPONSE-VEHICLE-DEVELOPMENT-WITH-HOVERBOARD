// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hoverboard_msgs:msg/SonarMsg.idl
// generated code does not contain a copyright notice
#include "hoverboard_msgs/msg/detail/sonar_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hoverboard_msgs__msg__SonarMsg__init(hoverboard_msgs__msg__SonarMsg * msg)
{
  if (!msg) {
    return false;
  }
  // sonar1
  // sonar2
  // sonar3
  // sonar4
  // sonar5
  return true;
}

void
hoverboard_msgs__msg__SonarMsg__fini(hoverboard_msgs__msg__SonarMsg * msg)
{
  if (!msg) {
    return;
  }
  // sonar1
  // sonar2
  // sonar3
  // sonar4
  // sonar5
}

bool
hoverboard_msgs__msg__SonarMsg__are_equal(const hoverboard_msgs__msg__SonarMsg * lhs, const hoverboard_msgs__msg__SonarMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sonar1
  if (lhs->sonar1 != rhs->sonar1) {
    return false;
  }
  // sonar2
  if (lhs->sonar2 != rhs->sonar2) {
    return false;
  }
  // sonar3
  if (lhs->sonar3 != rhs->sonar3) {
    return false;
  }
  // sonar4
  if (lhs->sonar4 != rhs->sonar4) {
    return false;
  }
  // sonar5
  if (lhs->sonar5 != rhs->sonar5) {
    return false;
  }
  return true;
}

bool
hoverboard_msgs__msg__SonarMsg__copy(
  const hoverboard_msgs__msg__SonarMsg * input,
  hoverboard_msgs__msg__SonarMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // sonar1
  output->sonar1 = input->sonar1;
  // sonar2
  output->sonar2 = input->sonar2;
  // sonar3
  output->sonar3 = input->sonar3;
  // sonar4
  output->sonar4 = input->sonar4;
  // sonar5
  output->sonar5 = input->sonar5;
  return true;
}

hoverboard_msgs__msg__SonarMsg *
hoverboard_msgs__msg__SonarMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hoverboard_msgs__msg__SonarMsg * msg = (hoverboard_msgs__msg__SonarMsg *)allocator.allocate(sizeof(hoverboard_msgs__msg__SonarMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hoverboard_msgs__msg__SonarMsg));
  bool success = hoverboard_msgs__msg__SonarMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hoverboard_msgs__msg__SonarMsg__destroy(hoverboard_msgs__msg__SonarMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hoverboard_msgs__msg__SonarMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hoverboard_msgs__msg__SonarMsg__Sequence__init(hoverboard_msgs__msg__SonarMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hoverboard_msgs__msg__SonarMsg * data = NULL;

  if (size) {
    data = (hoverboard_msgs__msg__SonarMsg *)allocator.zero_allocate(size, sizeof(hoverboard_msgs__msg__SonarMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hoverboard_msgs__msg__SonarMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hoverboard_msgs__msg__SonarMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hoverboard_msgs__msg__SonarMsg__Sequence__fini(hoverboard_msgs__msg__SonarMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hoverboard_msgs__msg__SonarMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hoverboard_msgs__msg__SonarMsg__Sequence *
hoverboard_msgs__msg__SonarMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hoverboard_msgs__msg__SonarMsg__Sequence * array = (hoverboard_msgs__msg__SonarMsg__Sequence *)allocator.allocate(sizeof(hoverboard_msgs__msg__SonarMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hoverboard_msgs__msg__SonarMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hoverboard_msgs__msg__SonarMsg__Sequence__destroy(hoverboard_msgs__msg__SonarMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hoverboard_msgs__msg__SonarMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hoverboard_msgs__msg__SonarMsg__Sequence__are_equal(const hoverboard_msgs__msg__SonarMsg__Sequence * lhs, const hoverboard_msgs__msg__SonarMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hoverboard_msgs__msg__SonarMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hoverboard_msgs__msg__SonarMsg__Sequence__copy(
  const hoverboard_msgs__msg__SonarMsg__Sequence * input,
  hoverboard_msgs__msg__SonarMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hoverboard_msgs__msg__SonarMsg);
    hoverboard_msgs__msg__SonarMsg * data =
      (hoverboard_msgs__msg__SonarMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hoverboard_msgs__msg__SonarMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hoverboard_msgs__msg__SonarMsg__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hoverboard_msgs__msg__SonarMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
