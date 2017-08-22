//Test program to check RELU is working or not
#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
#include <stdio.h>
using namespace std;
using namespace cv;
int main(int argc, const char** argv)
{
  Mat A = (Mat_<double>(3,3) << -3.5,-2.4,-1,  0,1.4,2.5,   3,4,5);
  imshow("aa", A);
  waitKey(0);
  cout << "A = " << endl << " " << A << endl << endl;
  Mat B;
  threshold(A, B, 0, 0, THRESH_TOZERO);
  cout << "B = " << endl << " " << B << endl << endl;
}




