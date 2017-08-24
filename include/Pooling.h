#ifndef _POOL_LAYER_
#define _POOL_LAYER_

#include <LayerContext.h>
#include <vector>
#include "Weights.h"

using namespace std;
using namespace cv;


class Pooling 
{
  public:
    void init(vector<LayerParams> & layers);
    void pooler(Weights & w, const int & layerIdx);
    vector<LayerParams> m_layers;
};

#endif
