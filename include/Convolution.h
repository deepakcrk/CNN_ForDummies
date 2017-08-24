/**
 * @author: Deepak C R
 *
 */
#ifndef _CONV_LAYER_
#define _CONV_LAYER_

#include <iostream>
#include <LayerContext.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include "Weights.h"

using namespace std;
using namespace cv;

class Convolution
{
  public:
    void init(vector<LayerParams> layers);
    void convolve(Weights & wts, const int layerIdx);
    vector<LayerParams> m_layers;
};

#endif
