#ifndef _CONV_LAYER_
#define _CONV_LAYER_

#include <iostream>
#include <LayerContext.h>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Convolution
{
  public:
    void init(vector<LayerParams> layers);
    void convolve(vector<Mat> src, int i);
    vector<LayerParams> m_layers;
};

#endif
