#ifndef DEF_RECTGRID
#define DEF_RECTGRID

using namespace cv;

//Class defining a grid of Rectangle to place them in an image
//A rectangle object contains a origin coordonate (x,y) then height and witdh

class RectGrid
{
	public :
		bool isBigEnough();
		void addNewLigne(std::vector<Rect> targets);
		void clean();
		void addImg(Mat frame);
		std::vector<std::vector<Rect>> getGrid();
		std::vector<Mat> getImgTab();
		
	private :
		std::vector<std::vector<Rect>> grid;
		std::vector<Mat> imgTab;
};

#endif