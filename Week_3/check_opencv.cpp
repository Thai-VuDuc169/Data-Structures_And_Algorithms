#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
  cout << "OpenCV version : " << CV_VERSION << endl;
  cout << "Major version : " << CV_MAJOR_VERSION << endl;
  cout << "Minor version : " << CV_MINOR_VERSION << endl;
  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
   return 0;
//   if ( CV_MAJOR_VERSION < 3)
//   {
//       // Old OpenCV 2 code goes here.
//   } else
//   {
//       // New OpenCV 3 code goes here.
//   }
}
