#ifndef _POOL_LAYER_
#define _POOL_LAYER_

#include <LayerContext.h>
#include <vector>

using namespace std;
using namespace cv;

class Pooling 
{
  public:
    void init(vector<LayerParams> & layers);
    void pooler(vector<Mat> & blob, const int & layerIdx);
    vector<LayerParams> m_layers;
};

#endif
