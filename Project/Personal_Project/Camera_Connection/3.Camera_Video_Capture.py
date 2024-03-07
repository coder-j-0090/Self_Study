import cv2 as cv 
import numpy as np 


'''
# Show what camera sees
cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    cv.imshow('frame', frame)
    if cv.waitKey(1)==ord('q'):
        break

cap.release()
cap.destoryAllWIndows()
'''

#Default(Laptop Camera)
cap = cv.VideoCapture(0)

#Video from the given data_path
#cap = cv.VideoCapture('/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Videos/sheep_-_57647 (1080p).mp4')

while True:
    ret, frame = cap.read()

    #cap.get(3) gives u the width property of your frame or your video cpature
    width = int(cap.get(3))
    height = int(cap.get(4))

    #Create empty numpy array to use this array as an image
    #Pass the shape of the array. Shape should be identical to the shape of my frame
    #Define the type of this array, np.unit8, which means unsigned integer 8 bits
    image = np.zeros(frame.shape, np.uint8)

    #Put 4 quadrants, and all of them with my default camera(laptop camera)
    #Make 4 screens in one frame and make each smaller 
    smaller_frame = cv.resize(frame, (0,0), fx=0.5, fy=0.5)

    #If you put the value 'smaller_frame' to top left and top right, it will all look normal(Before the rotation).
    #Top left
    image[:height//2, :width//2] = cv.rotate(smaller_frame, cv.ROTATE_180)
    #Bottom left and rotate
    image[height//2:, :width//2] = smaller_frame
    #Top Right
    image[:height//2, width//2:] = cv.rotate(smaller_frame, cv.ROTATE_180)
    #Bottom Right
    image[height//2:, width//2:] = smaller_frame


    cv.imshow('frame', image)

    if cv.waitKey(1) == ord('q'):
        break

