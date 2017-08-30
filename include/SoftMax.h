#include <iostream>
#include <math.h>
#include <vector>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class SoftMax
{
  public:
    void softmax(vector<double> & src, vector<double> & dst);
    void softmax(Mat & src, Mat & dst);
};
