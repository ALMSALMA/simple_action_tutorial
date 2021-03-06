// Generated by gencpp from file my_robot_msgs/LineRobotFeedback.msg
// DO NOT EDIT!


#ifndef MY_ROBOT_MSGS_MESSAGE_LINEROBOTFEEDBACK_H
#define MY_ROBOT_MSGS_MESSAGE_LINEROBOTFEEDBACK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace my_robot_msgs
{
template <class ContainerAllocator>
struct LineRobotFeedback_
{
  typedef LineRobotFeedback_<ContainerAllocator> Type;

  LineRobotFeedback_()
    : current_position(0)  {
    }
  LineRobotFeedback_(const ContainerAllocator& _alloc)
    : current_position(0)  {
  (void)_alloc;
    }



   typedef int64_t _current_position_type;
  _current_position_type current_position;





  typedef boost::shared_ptr< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct LineRobotFeedback_

typedef ::my_robot_msgs::LineRobotFeedback_<std::allocator<void> > LineRobotFeedback;

typedef boost::shared_ptr< ::my_robot_msgs::LineRobotFeedback > LineRobotFeedbackPtr;
typedef boost::shared_ptr< ::my_robot_msgs::LineRobotFeedback const> LineRobotFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator1> & lhs, const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator2> & rhs)
{
  return lhs.current_position == rhs.current_position;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator1> & lhs, const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace my_robot_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ce06827e612a0991667c0287cf6c3f6f";
  }

  static const char* value(const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xce06827e612a0991ULL;
  static const uint64_t static_value2 = 0x667c0287cf6c3f6fULL;
};

template<class ContainerAllocator>
struct DataType< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_robot_msgs/LineRobotFeedback";
  }

  static const char* value(const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#feedback\n"
"int64 current_position\n"
"\n"
"\n"
;
  }

  static const char* value(const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.current_position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LineRobotFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_robot_msgs::LineRobotFeedback_<ContainerAllocator>& v)
  {
    s << indent << "current_position: ";
    Printer<int64_t>::stream(s, indent + "  ", v.current_position);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_ROBOT_MSGS_MESSAGE_LINEROBOTFEEDBACK_H
