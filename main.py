import picamera as PiCamera
import cv2 as cv
import numpy as np
import time
import utlis
from picamera.array import PiRGBArray
import serial

lap_number = 0

# Certain constants
Px = 0.0264583333  # Pixel to cm conversion
Focal_distance = 3  # Approx
Signal_size = 10  # in cm
Weight = 5
Object_size = int(100 * 0.3)

l = 110
b = 80
camera = PiCamera.PiCamera()
camera.resolution = (l, b)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(l, b))
order = 0
time.sleep(0.1)

for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    ser = serial.Serial('/dev/ttyACMC0', 9600, timeout=1.0)
    ser.flush()
    start = time.time()
    if lap_number != 3:
        image = frame.array

        if order == 0:
            # ------------- Detects the signals and determines the direction to turn ----------------
            Signal_img, Signal_data = utlis.signal_detection(image, Signal_size, Weight, Object_size, Focal_distance, Px, l)
            cv.imshow("Signal Image", Signal_img)
            # Processes the signal detection data
            data = Signal_data
            print(data)
            if data[0] == 1:
                if data[1] == 0:
                    if data[4] < 15:
                        print("LEFT")
                        ser.write(b"LEFT\n")


                else:
                    if data[4] < 15:
                        print("left")
                        ser.write(b"LEFT\n")

                    else:
                        print("Centered")
                        ser.write(b"Centered\n")

            elif data[0] == 0:
                if data[1] == 0:
                    if data[4] < 15:
                        print("RIGHT")
                        ser.write(b"RIGHT\n")
                else:
                    if data[4] < 15:
                        print("RIGHT")
                        ser.write(b"RIGHT\n")
                    else:
                        print("Centered")
                        ser.write(b"Centered\n")
            else:
                ser.write(b"Centered\n")
                order += 1

        elif order == 1:
            # -------------- Detects the lanes and determines the angle to turn -------------
            Wall_img, Wall_data, Wall_angle = utlis.wall_detection(image, l, b, 6)
            cv.imshow("Lane Image", image)
            # Processes the lane detection data
            data = Wall_data
            #angle = Wall_angle
            #angle += 10
            print(data, angle)
            if data == "R":
                print("RIGHT")
                ser.write(b"RIGHT\n")

            elif data == "L":
                print("LEFT")
                ser.write(b"LEFT\n")

            elif data == "F":
                print("Wall")
                ser.write(b"LEFT\n")

            elif data == "N":
                print("Nothing")
                ser.write(b"Nothing\n")
                order -= 1

            # --------------- All the processing is over ------------------
        end = time.time()
        print("FPS :", 1 / (end - start))
        cv.waitKey(1)
    else:
        break
    rawCapture.truncate(0)
