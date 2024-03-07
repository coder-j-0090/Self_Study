#Capture Video from Camera(카메라로부터 비디오 캡쳐)

#Use the laptop camera and show what laptop camera sees
import numpy as np 
import cv2 as cv

#Initialize a video capture object 'cap' to capture video from the default camera(idx 0)
cap = cv.VideoCapture(0)

#If cap is not opened(camera is not connected, it prints out it can't open)
if not cap.isOpened():
    print('Cannot open camera')
    exit()

#Begins infinite loop to continuously capture frames from camera until break statement
while True:
    #captures a frame from camera and store in variable frame. Retur nvalue ret indicates whether the frame is captured successfully
    #ret is boolean variable that indicatees wehter a freame is successfully read from video capture object. Return true if the frame is successfully. Return false otherwise
    #frame is numpy array that represent image data of captured frame. It contains pixel values representing the colors of image in BGT format.
    ret, frame = cap.read()
    #if it's not captured successfully
    if not ret:
        #print this and break
        print("Can't receive frame(stream end?). Exiting ...")
        break

    #gray converts the captured frame from color(BGR) to gray scale using cv.cvtColor function
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

    #it shows grayscale frame in a window with the title 'frame' using cv.imshow()
    cv.imshow('frame', gray) #If the code that defines gray is removed and gray in this line turns to frame, it will be orignial color
    #if you press q(ASCII value of q is printed)
    if cv.waitKey(1)==ord('q'):
        break
#Release video capture object, release the camera resources
cap.release()
#Close all OpenCV windows created during the program execution
cv.destoryAllWindows()