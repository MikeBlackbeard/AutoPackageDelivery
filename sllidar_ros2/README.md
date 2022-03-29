# SLLIDAR ROS2 Package

This package is based on [Slamtec SLLIDAR ROS2 Package](https://github.com/Slamtec/sllidar_ros2).

Some modifications have been done on the original package in order to work with this project. The first change
is regarding the launch package. This node will be running on a Raspberry Pi 3. The Raspberry Pi 3 does not have a
desktop interface. Hence, the visualisation part of this package has been removed and will be accessed through a 
computer connected via Wi-Fi to the Raspberry Pi 3.

https://roboticsbackend.com/ros2-multiple-machines-including-raspberry-pi/

To get more information about this node please visit [Slamtec](https://github.com/Slamtec/sllidar_ros2)
