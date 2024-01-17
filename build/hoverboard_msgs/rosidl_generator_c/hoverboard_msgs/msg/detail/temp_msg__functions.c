// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hoverboard_msgs:msg/TempMsg.idl
// generated code does not contain a copyright notice
#include "hoverboard_msgs/msg/detail/temp_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
hoverboard_msgs__msg__TempMsg__init(hoverboard_msgs__msg__TempMsg * msg)
{
  if (!msg) {
    return false;
  }
  // temp1
  // temp2
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    hoverboard_msgs__msg__TempMsg__fini(msg);
    return false;
  }
  return true;
}

void
hoverboard_msgs__msg__TempMsg__fini(hoverboard_msgs__msg__TempMsg * msg)
{
  if (!msg) {
    return;
  }
  // temp1
  // temp2
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
hoverboard_msgs__msg__TempMsg__are_equal(const hoverboard_msgs__msg__TempMsg * lhs, const hoverboard_msgs__msg__TempMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // temp1
  if (lhs->temp1 != rhs->temp1) {
    return false;
  }
  // temp2
  if (lhs->temp2 != rhs->temp2) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
hoverboard_msgs__msg__TempMsg__copy(
  const hoverboard_msgs__msg__TempMsg * input,
  hoverboard_msgs__msg__TempMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // temp1
  output->temp1 = input->temp1;
  // temp2
  output->temp2 = input->temp2;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

hoverboard_msgs__msg__TempMsg *
hoverboard_msgs__msg__TempMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hoverboard_msgs__msg__TempMsg * msg = (hoverboard_msgs__msg__TempMsg *)allocator.allocate(sizeof(hoverboard_msgs__msg__TempMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hoverboard_msgs__msg__TempMsg));
  bool success = hoverboard_msgs__msg__TempMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hoverboard_msgs__msg__TempMsg__destroy(hoverboard_msgs__msg__TempMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hoverboard_msgs__msg__TempMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hoverboard_msgs__msg__TempMsg__Sequence__init(hoverboard_msgs__msg__TempMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hoverboard_msgs__msg__TempMsg * data = NULL;

  if (size) {
    data = (hoverboard_msgs__msg__TempMsg *)allocator.zero_allocate(size, sizeof(hoverboard_msgs__msg__TempMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hoverboard_msgs__msg__TempMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hoverboard_msgs__msg__TempMsg__fini(&data[i - 1]);
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
hoverboard_msgs__msg__TempMsg__Sequence__fini(hoverboard_msgs__msg__TempMsg__Sequence * array)
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
      hoverboard_msgs__msg__TempMsg__fini(&array->data[i]);
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

hoverboard_msgs__msg__TempMsg__Sequence *
hoverboard_msgs__msg__TempMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hoverboard_msgs__msg__TempMsg__Sequence * array = (hoverboard_msgs__msg__TempMsg__Sequence *)allocator.allocate(sizeof(hoverboard_msgs__msg__TempMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hoverboard_msgs__msg__TempMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hoverboard_msgs__msg__TempMsg__Sequence__destroy(hoverboard_msgs__msg__TempMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hoverboard_msgs__msg__TempMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hoverboard_msgs__msg__TempMsg__Sequence__are_equal(const hoverboard_msgs__msg__TempMsg__Sequence * lhs, const hoverboard_msgs__msg__TempMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hoverboard_msgs__msg__TempMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hoverboard_msgs__msg__TempMsg__Sequence__copy(
  const hoverboard_msgs__msg__TempMsg__Sequence * input,
  hoverboard_msgs__msg__TempMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hoverboard_msgs__msg__TempMsg);
    hoverboard_msgs__msg__TempMsg * data =
      (hoverboard_msgs__msg__TempMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hoverboard_msgs__msg__TempMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          hoverboard_msgs__msg__TempMsg__fini(&data[i]);
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
    if (!hoverboard_msgs__msg__TempMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
