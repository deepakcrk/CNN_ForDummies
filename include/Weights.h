#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Weights
{
  public:
    Weights( /******NEED to PASS STRUCT OF PROTOTX *******/);
    initWeights( /******NEED to PASS STRUCT OF PROTOTX *******/);
    vector<vector<vector<cv::Mat> > > m_convWts;
    vector<cv::Mat> fcWts;
}


