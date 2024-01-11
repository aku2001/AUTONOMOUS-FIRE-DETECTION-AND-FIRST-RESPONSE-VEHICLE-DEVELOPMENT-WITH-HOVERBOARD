// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:msg/SonarMsg.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "tutorial_interfaces/msg/detail/sonar_msg__struct.h"
#include "tutorial_interfaces/msg/detail/sonar_msg__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__msg__sonar_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tutorial_interfaces.msg._sonar_msg.SonarMsg", full_classname_dest, 43) == 0);
  }
  tutorial_interfaces__msg__SonarMsg * ros_message = _ros_message;
  {  // sonar1
    PyObject * field = PyObject_GetAttrString(_pymsg, "sonar1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sonar1 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // sonar2
    PyObject * field = PyObject_GetAttrString(_pymsg, "sonar2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sonar2 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // sonar3
    PyObject * field = PyObject_GetAttrString(_pymsg, "sonar3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sonar3 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // sonar4
    PyObject * field = PyObject_GetAttrString(_pymsg, "sonar4");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sonar4 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // sonar5
    PyObject * field = PyObject_GetAttrString(_pymsg, "sonar5");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sonar5 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__msg__sonar_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SonarMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.msg._sonar_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SonarMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__msg__SonarMsg * ros_message = (tutorial_interfaces__msg__SonarMsg *)raw_ros_message;
  {  // sonar1
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->sonar1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sonar1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sonar2
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->sonar2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sonar2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sonar3
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->sonar3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sonar3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sonar4
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->sonar4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sonar4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sonar5
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->sonar5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sonar5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
