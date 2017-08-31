#ifndef _SOFTMAX_
#define _SOFTMAX_
#include <iostream>
#include <math.h>
#include <vector>
#include "opencv2/opencv.hpp"
#include "LayerContext.h"
#include "Weights.h"

using namespace std;
using namespace cv;

class SoftMax
{
  public:
    vector<LayerParams> m_layers;
    void init(vector<LayerParams> & layers);
    void softmax(Weights & wts, const int & layerIdx);
    void softmax(vector<double> & src, vector<double> & dst);
    void softmax(Mat & src, Mat & dst);
    void softmax(vector<Mat> & src, vector<Mat> & dst);
};

#endif
