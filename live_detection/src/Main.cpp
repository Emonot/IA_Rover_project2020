#include "Main.h"

using namespace cv;

void detectAndDisplay(Mat frame);

CascadeClassifier cible_cascade; //Declaring the classifier being train previously
RectGrid rectGrid; //Declaring RectGrid object

int main(int argc, char** argv )
{
    printf("start");
    
	//loading parameters
	if( !cible_cascade.load("data/cascade_cible1_5050.xml"))
	{
		printf("error loading parameters(weights) for the forward propagation");
		return -1;
	}
	
	//Turn on camera
	VideoCapture capture;
	capture.open(0);
	if ( ! capture.isOpened())
	{
		printf("Error occured while opening the camera");
		return -1;
	}

	//reading camera frame
	Mat frame;
	while (capture.read(frame))
	{
		if(frame.empty())
		{
			printf("No frame is given by the camera");
			break;
		}

		//this was put for debug or secondary method
		//detectAndDisplay(frame);
		
		//detect targets and display rectangle on an image with coordonate to visualise
		detect(frame,rectGrid,cible_cascade);
		if (waitKey(10)==27)
		{
			break;
		}
	}
    return 0;
}

void detectAndDisplay(Mat frame)
{
	Mat frame_gray;
	cvtColor(frame ,frame_gray, COLOR_BGR2GRAY); //transform in black and white
	equalizeHist(frame_gray, frame_gray); //change contrast
	
	//detect with IA
	std::vector<Rect> targets;
	cible_cascade.detectMultiScale(frame_gray, targets, 1.1,98 ,0,Size(2,2), Size(250,250));
	
	printf("Displaying");
	//targets = monoRectSmoothing(frame_gray);
	
	for (size_t i = 0; i < targets.size();i++) // rectangle drawing
	{
		Point bottom_left(targets[i].x,targets[i].y);
		Point upper_right(targets[i].x + targets[i].width, targets[i].y + targets[i].height);
		
		rectangle(frame,bottom_left,upper_right,Scalar(255,0,0),4);
		
	}
	imshow("output camera",frame);
}


	 

