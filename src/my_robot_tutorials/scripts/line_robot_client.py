#!/usr/bin/env python

import rospy
import actionlib

from my_robot_msgs.msg import LineRobotAction
from my_robot_msgs.msg import LineRobotGoal
from std_msgs.msg import Empty

class LineRobotClient:

    def __init__(self):
        self._ac = actionlib.SimpleActionClient('/line_robot',
                LineRobotAction)
        self._ac.wait_for_server()
        rospy.loginfo("Action server is up, you can send goals!")

	self.sub = rospy.Subscriber("/cancel_goal", Empty, self.cancel_callback)

    def move_to_goal(self):
        goal = LineRobotGoal(position=20, velocity=3)
        self._ac.send_goal(goal, done_cb = self.done_callback,
                feedback_cb = self.feedback_callback)
        rospy.loginfo("Goal has been sent.")

        #rospy.sleep(5)
        #self._ac.cancel_goal()
        #rospy.loginfo("Cancel order is sent!")

    def done_callback(self, status, result):
        rospy.loginfo("Status is: " + str(status))
        rospy.loginfo("Result is: " + str(result))

    def feedback_callback(self, feedback):
        rospy.loginfo("Feedback is: " + str(feedback))

    def cancel_callback(self, req):
        self._ac.cancel_goal()
        rospy.loginfo("Cancel order is sent!")

if __name__=='__main__':
    rospy.init_node('line_robot_client')
    
    client = LineRobotClient()
    
    client.move_to_goal()

    rospy.spin()

