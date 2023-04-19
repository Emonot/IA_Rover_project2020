#include "rectGrid.h"
#include "treatment.h"
#include "lisseurs.h"

//void function receive a frame, a RectGrid, and Weights for a foward propagation using the Cascade model 
void detect(Mat frame,RectGrid rectGrid,CascadeClassifier cible_cascade)
{
	Mat frame_gray;
	cvtColor(frame ,frame_gray, COLOR_BGR2GRAY); //tranform into black and white
	equalizeHist(frame_gray, frame_gray); //adjust the contrast
	
	std::vector<Rect> targets; // List of Rectangle detected by the IA
	std::vector<Rect> bestRect; // List containing the most probable rectangle containing the target in the image
 	
	//Once we reiceived 10 images
	if ( rectGrid.isBigEnough() )
	{
		printf("Display");
		bestRect = monoRectSmoothing(rectGrid);
		rectGrid.clean();
		monoDisplay(rectGrid, bestRect);
	}
	
	cible_cascade.detectMultiScale(frame_gray, targets, 1.1,98 ,0,Size(2,2), Size(250,250)); //forward propagation, returns a list of targets(rectangles). Parameters are define in openCV documentation
	rectGrid.addNewLigne(targets); //adding IA detections
	rectGrid.addImg(frame); //adding the image
}

//Display function is used to draw rectangles on the image and show it
void display(Mat frame, std::vector<Rect> targets)
{
	for (size_t i = 0; i < targets.size();i++) // drawing the rectangle
	{
		Point bottom_left(targets[i].x,targets[i].y);
		Point upper_right(targets[i].x + targets[i].width, targets[i].y + targets[i].height);
		
		rectangle(frame,bottom_left,upper_right,Scalar(255,0,0),4);
		
	}
	//show the rectangle on the frame
	imshow("output camera",frame);
}

//Display function is used to draw rectangles on the image and show it
void monoDisplay(RectGrid rectGrid,std::vector<Rect> targets)
{
	std::vector<Mat> imgTab = rectGrid.getImgTab();
		
	for (size_t i = 0 ; i < imgTab.size() ; i++)
	{
		Point bottom_left(targets[i].x,targets[i].y);
		Point upper_right(targets[i].x + targets[i].width, targets[i].y + targets[i].height);
		rectangle(imgTab[i],bottom_left,upper_right,Scalar(255,0,0),4);
		imshow("output camera",imgTab[i]);
	}

}