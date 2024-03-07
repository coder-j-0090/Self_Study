import cv2 as cv 

#img = cv.imread('/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/images/bae.png')
img = cv.imread('/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/images/soccer_practice.jpg')

#classNames start from 0, not 1. So we have to subtract 1.
classNames = []
classFile = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/5. Murtaza/coco.names'
with open(classFile, 'rt') as f:
    classNames = f.read().rstrip('\n').split('\n')

configPath = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/5. Murtaza/Murtaza_Setting/ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
weightsPath = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/5. Murtaza/Murtaza_Setting/frozen_inference_graph.pb'

net = cv.dnn_DetectionModel(weightsPath, configPath)
net.setInputSize(320,320)
net.setInputScale(1.0 / 127.5)
net.setInputMean((127.5, 127.5, 127.5))
net.setInputSwapRB(True)

#If the similarity is less than 50%, ignore.
classIds, confs, bbox = net.detect(img, confThreshold = 0.5)
print(classIds, bbox)

for classId, confidence, box in zip(classIds.flatten(), confs.flatten(), bbox):
    cv.rectangle(img, box, color = (0,255,0), thickness=3)
    cv.putText(img, classNames[classId-1].upper(), (box[0]+10, box[1]+30), 
                cv.FONT_HERSHEY_COMPLEX, 1, (0,255,0), thickness = 2)

cv.imshow("Output", img)
cv.waitKey(0) 