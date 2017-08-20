#ifndef _NORMALIZATION_LAYER
#define _NORMALIZATION_LAYER

#include <LayerContext.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

class Normalization
{
  public:
    void init(vector<LayerParams> layers);
    vector<LayerParams> m_layers;
};


#endif 
