import numpy as np 
import cv2 as cv 

cap = cv.VideoCapture(0)
#Load HAAR Cascade Classifier
#cv.data.haarcascade is the path to where these are stored on our system, and xml file is pre-trained model
face_cascade = cv.CascadeClassifier(cv.data.haarcascades + "haarcascade_frontalface_default.xml")
eye_cascade = cv.CascadeClassifier(cv.data.haarcascades + "haarcascade_eye.xml")


while True:
    ret, frame = cap.read()

    #convert to gray scale(just like other algorithms in openCV, it requires a gray scale)
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    '''
    https://stackoverflow.com/questions/20801015/recommended-values-for-opencv-detectmultiscale-parameters 
    scale factor : Parameter specifying how much the image size is reduced at each image scale
    minNeighbors : Parameter specifying how many neighbors each candidate rectangle should have to retain it.
    minsize - Min. possible object size. Smaller than this will be ignored. Ex) [30,30]
    maxsize - Max. possible object size. Bigger than this will be ignored
    '''
    faces = face_cascade.detectMultiScale(gray, 1.3, 5) #No min or max, so it will give all of the faces
    
    
    #give (x,y,w,h) for rectangle and draw it on my image
    for(x, y, w, h) in faces:
        #Rectangle(image, (top left corner x,y), (bottom right corner (x+w, y+h), thickness )
        cv.rectangle(frame, (x,y), (x+w, y+h), (255,0,0), 5)
        #Figure out the area in my image, that is the face. Find face, then it's easier to detect eye with eye detector or classifier
        roi_gray = gray[y:y+w, x:x+w]
        #Reference to original frame. If I modify this, it will modify the original frame. 
        roi_color = frame[y:y+h, x:x+w]
        #Detect Eye
        '''
        Want to find eyes only on the face. It will tell me the location of eyes on roi_gray
        If cv.rectangle's first argument is frame, program will detect the eyes on the wrong spot.
        Because (ex, ey, ew, eh) will tell us the location of eyes on our ROI gray image.
        ROI color is same size as image that we detected the eyes from
        '''
        eye = eye_cascade.detectMultiScale(roi_gray, 1.3, 5)
        for(ex, ey, ew, eh) in eye:
            cv.rectangle(roi_color, (ex,ey), (ex+ew, ey+eh), (0,255,0), 5)

    cv.imshow('frame', frame)

    if cv.waitKey(1) == ord('q'):
        break 

cap.release()
cv.destroyAllWindows()
