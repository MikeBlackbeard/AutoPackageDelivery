# AutoPackageDelivery

This repository contains all the information to develop the first version of an autonomous package delivery robot.
The project is based on 5 main topics:

* Design
* Indoor localization system
* SLAM (Simultaneous Localization and Mapping)
* Obstacle avoidance
* Autonomous parking

The core of the robot is managed by a [Raspberry Pi 3](https://www.raspberrypi.com/products/raspberry-pi-3-model-b/), running [Ubuntu 64-bit Server 20.04 LTS OS](https://ubuntu.com/download/raspberry-pi). 

# Requirements

* [Raspberry Pi 3B](https://www.raspberrypi.com/products/) or newer
* PC runnun Ubuntu (On Windows or Mac you can use a virtual machine with Ubuntu)
* [Arduino Uno](http://store.arduino.cc/collections/arduino/products/arduino-uno-rev3)
* [RPLidar A1](https://www.slamtec.com/en/Lidar/A1)


# Conection Instruction

1. Download and install Raspberry Pi OS from [Raspberry Pi website](https://www.raspberrypi.com/software/)
2. Insert a MicroSD in your computer, and install [Ubuntu Server 20.04 LTS OS](https://ubuntu.com/download/raspberry-pi). If your Raspberry Pi 3 allows you to install 64-bit OS select the 64-bit installation. Otherwise install the 32-bit OS.
3. Set up your Network conection \*\*\*\**Pendient*\*\*\*\*

From this point it will be possible to access the Raspberry Pi 3 from your Ubuntu system

1. Get the IP address of both your Raspberry Pi and your Ubuntu PC.
   - To get your PC address you can use `hostname -I` on your terminal
2. On your Ubunto PC terminal write the next command to connect with your Raspberry Pi:

    sudo hello
   
3. Run
