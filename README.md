# Future_EngineersBD
This repository contains the code that was used for creating the autonomous vehicle for the competition

# Modules used:
In the code the main module used is OpenCV (and numpy for Opencv). It is a well known module used in reputed computer vision programs. It is used in the Raspberry Pi to process the information from the camera to detect the traffic signals as well as the colour of the signals. It is also used for the wall detection program as well as the lap detection programs.

The other modules used include:

1. Serial For raspberry pi to arduino serial communication 
2. servo.h for servo
3. New ping for ultrasonic sensor

# Car electromechanical parts:

The car contains the following parts:

1. Raspberry Pi 3A - The Brains of the car which recieves the frames from the camera, processes it and then gives the commands to the Arduino.
2. Web camera
3. Two DC motors
4. L289N Motor controller
5. Servo motor
6. Two ultrasonic sensor
7. plastic board chasis as well as some plastic parts for stablilising the components

# Program function:

The program consists of three parts:

1. Signal Detection
2. Wall detection
3. Lap detection
