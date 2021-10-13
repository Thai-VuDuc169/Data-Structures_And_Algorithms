/*
1)	Compute Gradient of an image  
Note: For the first exercise, you can use lib as OpenCV for reading and writing an image. 
To compute Gradient of an image, please study what is the gradient of image 
and implement the filter to compute the Gradient according to x and y axis.  
Gradient of an image: https://en.wikipedia.org/wiki/Image_gradient 
Convolution: https://en.wikipedia.org/wiki/Kernel_(image_processing)#Convolution
*/
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <vector>

#define PATH_INPUT_IMAGE "/home/thaivu/Projects/Data-Structures_And_Algorithms/Photo/atiso.png"

using namespace std;
using namespace cv;

void computeGradient(const cv::Mat &input, cv::Mat &output) {
   std::vector<int> kernel_x({1,2,1,0,0,0,-1,-2,-1});
   std::vector<int> kernel_y({1,0,-1,2,0,-2,1,0,-1});
   int kernel_size = 3;


   unsigned char *data_in = (unsigned char*)(input.data);
   unsigned char *data_out = (unsigned char*)(output.data);

   for (int row = 0; row < input.rows; ++row) {
      for (int col = 0; col < input.cols ; col += 1) {

         if (row <= kernel_size/2 || row >= input.rows-kernel_size/2 ||
               col <= kernel_size/2 || col >= input.cols-kernel_size/2){
               data_out[output.step*row+col] = 0;
               continue;
         }
         
         int sum_x = 0, sum_y = 0;
         int k_ind = 0;
         for (int k_row = -kernel_size/2; k_row <= kernel_size/2; ++k_row) {
            for (int k_col = -kernel_size/2; k_col <= kernel_size/2; ++k_col) {
               sum_x += kernel_x[k_ind]*data_in[input.step*(row+k_row)+col+k_col];
               sum_y += kernel_y[k_ind]*data_in[input.step*(row+k_row)+col+k_col];
               k_ind++;
            }
         }
         int G = unsigned(std::sqrt(sum_x*sum_x+sum_y*sum_y));
         data_out[output.step*row+col] = std::min(G,255);
      }
   }
}

int main()
{
   cv::Mat input_img = cv::imread(PATH_INPUT_IMAGE, 0); // gray image
   cv::Mat output_img(input_img.rows, input_img.cols, input_img.type());
   computeGradient(input_img, output_img);
   cv::imshow("adfs", output_img);
   cv::waitKey(0);
   return 0;
}

