#ifndef _POOL_LAYER_
#define _POOL_LAYER_

#include <LayerContext.h>
#include <vector>

using namespace std;
using namespace cv;

class Pooling 
{
  public:
    init(vector<LayerParams> layers);
    vector<LayerParams> m_layers;
}

#endif
