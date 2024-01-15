# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tutorial_interfaces:msg/SonarMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SonarMsg(type):
    """Metaclass of message 'SonarMsg'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tutorial_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tutorial_interfaces.msg.SonarMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sonar_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sonar_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sonar_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sonar_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sonar_msg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SonarMsg(metaclass=Metaclass_SonarMsg):
    """Message class 'SonarMsg'."""

    __slots__ = [
        '_sonar1',
        '_sonar2',
        '_sonar3',
        '_sonar4',
        '_sonar5',
    ]

    _fields_and_field_types = {
        'sonar1': 'int64',
        'sonar2': 'int64',
        'sonar3': 'int64',
        'sonar4': 'int64',
        'sonar5': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sonar1 = kwargs.get('sonar1', int())
        self.sonar2 = kwargs.get('sonar2', int())
        self.sonar3 = kwargs.get('sonar3', int())
        self.sonar4 = kwargs.get('sonar4', int())
        self.sonar5 = kwargs.get('sonar5', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.sonar1 != other.sonar1:
            return False
        if self.sonar2 != other.sonar2:
            return False
        if self.sonar3 != other.sonar3:
            return False
        if self.sonar4 != other.sonar4:
            return False
        if self.sonar5 != other.sonar5:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def sonar1(self):
        """Message field 'sonar1'."""
        return self._sonar1

    @sonar1.setter
    def sonar1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sonar1' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'sonar1' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._sonar1 = value

    @property
    def sonar2(self):
        """Message field 'sonar2'."""
        return self._sonar2

    @sonar2.setter
    def sonar2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sonar2' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'sonar2' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._sonar2 = value

    @property
    def sonar3(self):
        """Message field 'sonar3'."""
        return self._sonar3

    @sonar3.setter
    def sonar3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sonar3' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'sonar3' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._sonar3 = value

    @property
    def sonar4(self):
        """Message field 'sonar4'."""
        return self._sonar4

    @sonar4.setter
    def sonar4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sonar4' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'sonar4' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._sonar4 = value

    @property
    def sonar5(self):
        """Message field 'sonar5'."""
        return self._sonar5

    @sonar5.setter
    def sonar5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sonar5' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'sonar5' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._sonar5 = value