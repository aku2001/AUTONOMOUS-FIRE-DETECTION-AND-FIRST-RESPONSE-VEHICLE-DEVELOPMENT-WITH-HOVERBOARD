// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from slam_toolbox:srv/DeserializePoseGraph.idl
// generated code does not contain a copyright notice
#include "slam_toolbox/srv/detail/deserialize_pose_graph__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"
// Member `initial_pose`
#include "geometry_msgs/msg/detail/pose2_d__functions.h"

bool
slam_toolbox__srv__DeserializePoseGraph_Request__init(slam_toolbox__srv__DeserializePoseGraph_Request * msg)
{
  if (!msg) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__init(&msg->filename)) {
    slam_toolbox__srv__DeserializePoseGraph_Request__fini(msg);
    return false;
  }
  // match_type
  // initial_pose
  if (!geometry_msgs__msg__Pose2D__init(&msg->initial_pose)) {
    slam_toolbox__srv__DeserializePoseGraph_Request__fini(msg);
    return false;
  }
  return true;
}

void
slam_toolbox__srv__DeserializePoseGraph_Request__fini(slam_toolbox__srv__DeserializePoseGraph_Request * msg)
{
  if (!msg) {
    return;
  }
  // filename
  rosidl_runtime_c__String__fini(&msg->filename);
  // match_type
  // initial_pose
  geometry_msgs__msg__Pose2D__fini(&msg->initial_pose);
}

bool
slam_toolbox__srv__DeserializePoseGraph_Request__are_equal(const slam_toolbox__srv__DeserializePoseGraph_Request * lhs, const slam_toolbox__srv__DeserializePoseGraph_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->filename), &(rhs->filename)))
  {
    return false;
  }
  // match_type
  if (lhs->match_type != rhs->match_type) {
    return false;
  }
  // initial_pose
  if (!geometry_msgs__msg__Pose2D__are_equal(
      &(lhs->initial_pose), &(rhs->initial_pose)))
  {
    return false;
  }
  return true;
}

bool
slam_toolbox__srv__DeserializePoseGraph_Request__copy(
  const slam_toolbox__srv__DeserializePoseGraph_Request * input,
  slam_toolbox__srv__DeserializePoseGraph_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__copy(
      &(input->filename), &(output->filename)))
  {
    return false;
  }
  // match_type
  output->match_type = input->match_type;
  // initial_pose
  if (!geometry_msgs__msg__Pose2D__copy(
      &(input->initial_pose), &(output->initial_pose)))
  {
    return false;
  }
  return true;
}

slam_toolbox__srv__DeserializePoseGraph_Request *
slam_toolbox__srv__DeserializePoseGraph_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_toolbox__srv__DeserializePoseGraph_Request * msg = (slam_toolbox__srv__DeserializePoseGraph_Request *)allocator.allocate(sizeof(slam_toolbox__srv__DeserializePoseGraph_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_toolbox__srv__DeserializePoseGraph_Request));
  bool success = slam_toolbox__srv__DeserializePoseGraph_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_toolbox__srv__DeserializePoseGraph_Request__destroy(slam_toolbox__srv__DeserializePoseGraph_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_toolbox__srv__DeserializePoseGraph_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__init(slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_toolbox__srv__DeserializePoseGraph_Request * data = NULL;

  if (size) {
    data = (slam_toolbox__srv__DeserializePoseGraph_Request *)allocator.zero_allocate(size, sizeof(slam_toolbox__srv__DeserializePoseGraph_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_toolbox__srv__DeserializePoseGraph_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_toolbox__srv__DeserializePoseGraph_Request__fini(&data[i - 1]);
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
slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__fini(slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * array)
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
      slam_toolbox__srv__DeserializePoseGraph_Request__fini(&array->data[i]);
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

slam_toolbox__srv__DeserializePoseGraph_Request__Sequence *
slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * array = (slam_toolbox__srv__DeserializePoseGraph_Request__Sequence *)allocator.allocate(sizeof(slam_toolbox__srv__DeserializePoseGraph_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__destroy(slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__are_equal(const slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * lhs, const slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_toolbox__srv__DeserializePoseGraph_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_toolbox__srv__DeserializePoseGraph_Request__Sequence__copy(
  const slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * input,
  slam_toolbox__srv__DeserializePoseGraph_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_toolbox__srv__DeserializePoseGraph_Request);
    slam_toolbox__srv__DeserializePoseGraph_Request * data =
      (slam_toolbox__srv__DeserializePoseGraph_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_toolbox__srv__DeserializePoseGraph_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          slam_toolbox__srv__DeserializePoseGraph_Request__fini(&data[i]);
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
    if (!slam_toolbox__srv__DeserializePoseGraph_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
slam_toolbox__srv__DeserializePoseGraph_Response__init(slam_toolbox__srv__DeserializePoseGraph_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
slam_toolbox__srv__DeserializePoseGraph_Response__fini(slam_toolbox__srv__DeserializePoseGraph_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
slam_toolbox__srv__DeserializePoseGraph_Response__are_equal(const slam_toolbox__srv__DeserializePoseGraph_Response * lhs, const slam_toolbox__srv__DeserializePoseGraph_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
slam_toolbox__srv__DeserializePoseGraph_Response__copy(
  const slam_toolbox__srv__DeserializePoseGraph_Response * input,
  slam_toolbox__srv__DeserializePoseGraph_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

slam_toolbox__srv__DeserializePoseGraph_Response *
slam_toolbox__srv__DeserializePoseGraph_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_toolbox__srv__DeserializePoseGraph_Response * msg = (slam_toolbox__srv__DeserializePoseGraph_Response *)allocator.allocate(sizeof(slam_toolbox__srv__DeserializePoseGraph_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(slam_toolbox__srv__DeserializePoseGraph_Response));
  bool success = slam_toolbox__srv__DeserializePoseGraph_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
slam_toolbox__srv__DeserializePoseGraph_Response__destroy(slam_toolbox__srv__DeserializePoseGraph_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    slam_toolbox__srv__DeserializePoseGraph_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__init(slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_toolbox__srv__DeserializePoseGraph_Response * data = NULL;

  if (size) {
    data = (slam_toolbox__srv__DeserializePoseGraph_Response *)allocator.zero_allocate(size, sizeof(slam_toolbox__srv__DeserializePoseGraph_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = slam_toolbox__srv__DeserializePoseGraph_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        slam_toolbox__srv__DeserializePoseGraph_Response__fini(&data[i - 1]);
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
slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__fini(slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * array)
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
      slam_toolbox__srv__DeserializePoseGraph_Response__fini(&array->data[i]);
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

slam_toolbox__srv__DeserializePoseGraph_Response__Sequence *
slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * array = (slam_toolbox__srv__DeserializePoseGraph_Response__Sequence *)allocator.allocate(sizeof(slam_toolbox__srv__DeserializePoseGraph_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__destroy(slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__are_equal(const slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * lhs, const slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!slam_toolbox__srv__DeserializePoseGraph_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
slam_toolbox__srv__DeserializePoseGraph_Response__Sequence__copy(
  const slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * input,
  slam_toolbox__srv__DeserializePoseGraph_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(slam_toolbox__srv__DeserializePoseGraph_Response);
    slam_toolbox__srv__DeserializePoseGraph_Response * data =
      (slam_toolbox__srv__DeserializePoseGraph_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!slam_toolbox__srv__DeserializePoseGraph_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          slam_toolbox__srv__DeserializePoseGraph_Response__fini(&data[i]);
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
    if (!slam_toolbox__srv__DeserializePoseGraph_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
