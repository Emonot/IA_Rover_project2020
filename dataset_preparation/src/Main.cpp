#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <sys/types.h>
#include <opencv2/dirent.h>
//#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    /* This piece of code go over all images of a folder, put them in black and white,resize them (here it's 200 by 200 and put them in a new folder called negDir COMMENT OR UNCOMMENT TO USE IT*/
    /*

    Mat image1, gray_image1, resize_gray1;

    struct dirent* lecture;
    String nom_du_fichier;
    DIR* rep;
    rep = opendir("D:/Folder/with_original_img/");
    lecture = readdir(rep);
    lecture = readdir(rep);
    while ((lecture = readdir(rep)))
    {
        cout << "nom du fichier: ";
        cout << lecture->d_name <<"\n" ;
        nom_du_fichier = lecture->d_name;
        image1 = imread("D:/Folder/with/original/img/"+nom_du_fichier, 1);
        cvtColor(image1, gray_image1, COLOR_RGB2GRAY);
        resize(gray_image1, resize_gray1, Size(200, 200), 0, 0, INTER_AREA);
        imwrite("D:/output/dir/"+ nom_du_fichier, resize_gray1);

    }
    closedir(rep);

    */

    /* This piece of code allows to rename all files to a growing numbers COMMENT OR UNCOMMENT TO USE IT*/

    struct dirent* lecture1;
    DIR* rep1;

    rep1 = opendir("D:/Put/Your/Own/Dir/With/BlackAndWhiteImg");

    lecture1 = readdir(rep1);
    lecture1 = readdir(rep1);

    int increment = 0;
    char tampon[256];
    //char* nom_du_fichier1 = lecture1->d_name;
    sprintf_s(tampon, "%d", increment);

    while ((lecture1 = readdir(rep1)))
    {

        increment += 1;
        sprintf_s(tampon, "%d.jpg", increment);
        cout << "file name: ";
        cout << lecture1->d_name << "\n" << "converted into " << tampon << "\n";
        //nom_du_fichier1 = lecture1->d_name;

        if (rename(lecture1->d_name, tampon) != 0)
        {
            perror("Error renaming file");
            cout << "can't rename file\n";
        }
        else
            cout << "File renamed successfully";

    }
    closedir(rep1);

    waitKey(0);

    return 0;
}
