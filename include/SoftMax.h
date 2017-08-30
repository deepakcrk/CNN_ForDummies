#include <iostream>
#include <math.h>
#include <vector>
#include "opencv2/opencv.hpp"
#include "LayerContext.h"

using namespace std;
using namespace cv;

class SoftMax
{
  public:
    vector<LayerParams> m_layers;
    void init(vector<LayerParams> layers);
    void softmax(vector<double> & src, vector<double> & dst);
    void softmax(Mat & src, Mat & dst);
    void softmax(vector<Mat> & src, vector<Mat> & dst);
};
