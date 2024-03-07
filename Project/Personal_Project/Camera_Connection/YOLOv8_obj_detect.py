'''
1. Load YOLOv8 model we need in order to detect and track objects
2. Load the video we will use for the test
3. Read frames from the video
4. Apply object detections
5. Track objects
6. Plot the results
7. Visualize.
'''

#1. Load YOLOv8 model
from ultralytics import YOLO 
model = YOLO('yolov8n.pt')      

#2. Load Video
import cv2 as cv 
video_path = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Videos/Soccer.mp4'
#video_path = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Videos/test.mp4'
#video_path = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Videos/sheep_-_57647 (1080p).mp4' 
cap = cv.VideoCapture(video_path)

#3. Read Frame
ret = True
while ret:
    ret, frame = cap.read()

    
    if ret:
    
        #4. Apply object detection    
        #5. Track Objects
        result = model.track(frame, persist = True)  #persist exists because we want yolo to be able to remember all the objects it has seen through all the frames in the video

        #6. Plot the result
        #Take frame and going to draw a bounding box in all the objects we have detected
        #We are going to draw all the results we got from the object tracking 

        #Plot result : cv.rectangle, cv.putText
        #We are detecting all the objects and we are doing all the object tracking in only one frame, so we will access the first element from the results and then call plot.
        frame_ = result[0].plot()

        #7. Visualize
        cv.imshow('frame', frame_)
        if cv.waitKey(25) == ord('q'):
            break 
