#ifndef  TREATMENT_H_INCLUDED
#define  TREATMENT_H_INCLUDED

//Header file for treatment functions
#include "rectGrid.h"


using namespace cv;

void detect(Mat frame,RectGrid rectGrid,CascadeClassifier cible_cascade);
void diplay(Mat frame,std::vector<Rect> targets);
void monoDisplay(RectGrid rectGrid,std::vector<Rect> targets); 
void rectStorage(std::vector<Rect> targets);

#endif // TREATMENT_H_INCLUDED