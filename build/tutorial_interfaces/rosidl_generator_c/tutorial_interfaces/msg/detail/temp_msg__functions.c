// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:msg/TempMsg.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/msg/detail/temp_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tutorial_interfaces__msg__TempMsg__init(tutorial_interfaces__msg__TempMsg * msg)
{
  if (!msg) {
    return false;
  }
  // temp1
  // temp2
  return true;
}

void
tutorial_interfaces__msg__TempMsg__fini(tutorial_interfaces__msg__TempMsg * msg)
{
  if (!msg) {
    return;
  }
  // temp1
  // temp2
}

bool
tutorial_interfaces__msg__TempMsg__are_equal(const tutorial_interfaces__msg__TempMsg * lhs, const tutorial_interfaces__msg__TempMsg * rhs)
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
  return true;
}

bool
tutorial_interfaces__msg__TempMsg__copy(
  const tutorial_interfaces__msg__TempMsg * input,
  tutorial_interfaces__msg__TempMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // temp1
  output->temp1 = input->temp1;
  // temp2
  output->temp2 = input->temp2;
  return true;
}

tutorial_interfaces__msg__TempMsg *
tutorial_interfaces__msg__TempMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__msg__TempMsg * msg = (tutorial_interfaces__msg__TempMsg *)allocator.allocate(sizeof(tutorial_interfaces__msg__TempMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__msg__TempMsg));
  bool success = tutorial_interfaces__msg__TempMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__msg__TempMsg__destroy(tutorial_interfaces__msg__TempMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__msg__TempMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__msg__TempMsg__Sequence__init(tutorial_interfaces__msg__TempMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__msg__TempMsg * data = NULL;

  if (size) {
    data = (tutorial_interfaces__msg__TempMsg *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__msg__TempMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__msg__TempMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__msg__TempMsg__fini(&data[i - 1]);
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
tutorial_interfaces__msg__TempMsg__Sequence__fini(tutorial_interfaces__msg__TempMsg__Sequence * array)
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
      tutorial_interfaces__msg__TempMsg__fini(&array->data[i]);
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

tutorial_interfaces__msg__TempMsg__Sequence *
tutorial_interfaces__msg__TempMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__msg__TempMsg__Sequence * array = (tutorial_interfaces__msg__TempMsg__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__msg__TempMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__msg__TempMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__msg__TempMsg__Sequence__destroy(tutorial_interfaces__msg__TempMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__msg__TempMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__msg__TempMsg__Sequence__are_equal(const tutorial_interfaces__msg__TempMsg__Sequence * lhs, const tutorial_interfaces__msg__TempMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__msg__TempMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__msg__TempMsg__Sequence__copy(
  const tutorial_interfaces__msg__TempMsg__Sequence * input,
  tutorial_interfaces__msg__TempMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__msg__TempMsg);
    tutorial_interfaces__msg__TempMsg * data =
      (tutorial_interfaces__msg__TempMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__msg__TempMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__msg__TempMsg__fini(&data[i]);
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
    if (!tutorial_interfaces__msg__TempMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}