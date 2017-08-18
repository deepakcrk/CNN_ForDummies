#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Weights
{
  vector<vector<cv::Mat> > convWts;
  vector<cv::Mat> fcWts;
}
