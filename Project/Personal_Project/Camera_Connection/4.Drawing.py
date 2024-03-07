import cv2 as cv 
import numpy as np

cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    width = int(cap.get(3))
    height = int(cap.get(4))

    #Draw X

    #Draw Line left top to the right bottom(new line var img)
    #cv.line(frame(source image), starting point, ending point, color, thickness) Increasing x goes right, increasing y goes further down
    img = cv.line(frame, (0,0), (width,height), (255, 0, 0), 10) 

    #Draw Line right top to the left bottom(new line var img)
    #cv.line(frame(source image), starting point, ending point, color, thickness) Increasing x goes right, increasing y goes further down
    img = cv.line(img, (0,height), (width,0), (0, 255, 0), 5) 

    #Draw Rectangle(Give top left and bottom right coordinate, then it will )
    img = cv.rectangle(img, (100, 100), (200,200), (128,128,128), 5)

    #Draw Circle(Source Image, Center Position, Radius, Color,-1 to fill this in)
    img = cv.circle(img, (300,300), 60, (0,0,255), -1)

    #Text
    font = cv.FONT_HERSHEY_SIMPLEX
    #cv.putText(image source, text, center position coordinate(Start from bottom left), font, font scale, color, line thickness, Linetype : cv.LINE_AA(Makes the text look better)
    img = cv.putText(img, 'Show Text Here', (200, height - 10), font, 4, (0,0,0), 5, cv.LINE_AA)

    cv.imshow('frame', frame)

    if cv.waitKey(1) == ord('q'):
        break

cap.release()
cap.destroyAllWindows()