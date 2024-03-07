import cv2 as cv 
import matplotlib.pyplot as plt 

config_file = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Files_Simplilearn/drive-download-20240228T110508Z-001/ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt' 
frozen_model = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Files_Simplilearn/drive-download-20240228T110508Z-001/frozen_inference_graph.pb'

#Coco : Common Object in COntext

model = cv.dnn_DetectionModel(frozen_model, config_file)

classLabels = []
file_name = '/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/Files_Simplilearn/drive-download-20240228T110508Z-001/labels.txt'

with open(file_name, 'rt') as fpt:
    classLabels = fpt.read().rstrip('\n').split('\n')

#print(classLabels)
print(len(classLabels))

model.setInputSize(320,320)
model.setInputScale(1.0/127.5)
model.setInputMean((127.5, 127.5, 127.5))
model.setInputSwapRB(True)

img = cv.imread('/Users/junyoungkim/Desktop/CodeClause(강의)/2. Object Detection System/images/soccer_practice.jpg')
# cv.imshow('boy',img)
# k = cv.waitKey(0)

# font_scale = 3
# font = cv.FONT_HERSHEY_PLAIN 
# for ClassInd, conf, boxes in zip(ClassIndex.flatten(), confidence.flatten(), bbox):
#     cv.rectangle(img, boxes, (225, 0, 0), 2)
#     cv.putText(img, classLabels[ClassInd-1], (boxes[0]+10, boxes[1]+40), font, fontScale = font_scale, color = (0,255,0), thickness=5)

# plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))

class_ids, confidences, bbox = model.detect(img, confThreshold=0.5)

if len(class_ids)>0:
    for class_id, confidence, box in zip(class_ids.flatten(), confidences.flatten(), bbox):
        cv.rectangle(img, box, color = (255,0,0), thickness=2)
        cv.putText(img, classLabels[class_id-1], (box[0], box[1]-10), cv.FONT_HERSHEY_SIMPLEX, 2, (0,255,0), thickness=8)

plt.imshow(cv.cvtColor(img, cv.COLOR_BGR2RGB))
plt.axis('off')
plt.show()

#--------------------------------------------------------------------------------------------
#Video Start

