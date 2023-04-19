#include "rectGrid.h" 
#include <vector>

//method contained inside 
bool isBigEnough()
{
	if (grid.size() >= 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//adding rectangles to the grid
void addNewLigne(std::vector<Rect> targets);
{
	grid.push_back(targets);
}

//adding the image for the grid
void addImg(Mat frame)
{
	imgTab.push_back(frame)
}

//clear the grid
void clean()
{
	grid.clear();
	imgTab.clear();
}

std::vector<std::vector<Rect>> getGrid()
{
	return grid;
}

std::vector<Mat> getImgTab()
{
	return imgTab;
}


