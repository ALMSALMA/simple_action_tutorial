#!/usr/bin/env python

import rospy
import actionlib

from my_robot_msgs.msg import LineRobotAction
from my_robot_msgs.msg import LineRobotGoal
from my_robot_msgs.msg import LineRobotResult
from my_robot_msgs.msg import LineRobotFeedback

class LineRobotServer:


# Class/Server Initialization

    def __init__(self):
        self._as = actionlib.SimpleActionServer('/line_robot', 
                LineRobotAction, execute_cb=self.move_to, auto_start=False)
        self._as.start()
        
        self._current_position = 50

        rospy.loginfo("Simple Action Server has been started!")

#--------------

    def move_to(self, goal):
        
# Initialization Part        
        
        position = goal.position
        velocity = goal.velocity
        rospy.loginfo("Goal has been recieved.")
        rospy.loginfo("Goal position is: " + str(position))
        rospy.loginfo("Goal velocity is: " + str(velocity))
        result = LineRobotResult()

        preempted = False
        success = False
        aborted = False

#--------------

        while not rospy.is_shutdown():

            if self._as.is_preempt_requested():
                preempted = True
                break

            elif position > 100 or position < 0:
                aborted = True
                break
            
            elif position == self._current_position:
                success = True
                break
            
            elif position > self._current_position:
                #rospy.loginfo("Robot is moving forward!")
                rospy.sleep(1)
                if (position - self._current_position) > velocity:
                    self._current_position += velocity
                    #rospy.loginfo(self._current_position)
                else:
                    self._current_position += position - self._current_position
                   # rospy.loginfo(self._current_position)

            elif self._current_position > position:
                #rospy.loginfo("Robot is moving backward!")
                rospy.sleep(1)
                if (self._current_position - position) > velocity:
                    self._current_position -= velocity
                    #rospy.loginfo(self._current_position)
                else:
                    self._current_position -= self._current_position - position
                    #rospy.loginfo(self._current_position)

# Feedback Part

        feedback = LineRobotFeedback()
        feedback.current_position = self._current_position
        self._as.publish_feedback(feedback)

#--------------

# Result Part

        result.position = self._current_position
            
        if success:
            rospy.loginfo("Robot Reached the desired position.")
            rospy.loginfo(self._current_position)
            result.message = "Robot reached the desired position"
            self._as.set_succeeded(result)

        elif preempted:
            rospy.loginfo("Goal cancelled!")
            rospy.loginfo(self._current_position)
            result.message = "The current goal is cancelled!"
            self._as.set_preempted(result)

        elif aborted:
            rospy.loginfo("Process aborted!!")
            result.message = "The position entered is not in the range!!"
            self._as.set_aborted(result)

        else:
            rospy.loginfo("Process aborted bcz of unknown error!!")
            result.message = "Unknown error!!"
            self._as.set_aborted(result)

#--------------

if __name__=='__main__':
    rospy.init_node('line_robot_server')

    server = LineRobotServer()

    rospy.spin()
