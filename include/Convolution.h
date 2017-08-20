#ifndef _CONV_LAYER_
#define _CONV_LAYER_

#include <iostream>
#include <LayerContext.h>

class Convolution
{
  public:
    void init(vector<LayerParams> layers);
    bool convolve(Mat src, int i);
    vector<LayerParams> m_layers;
};

#endif
