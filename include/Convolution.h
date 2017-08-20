#ifndef _CONV_LAYER_
#define _CONV_LAYER_

#include <iostream>
#include <LayerContext.h>

class Convolution
{
  public:
    void init(vector<layerParams> layers);
    bool convolve(Mat src, int i);
    vector<layerParams> m_layers;
    Weights wts;
};

#endif
