#ifndef _FCONNECT_LAYER
#define _FCONNECT_LAYER

#include <LayerContext.h>
#include "Weights.h"
#include <vector>

using namespace std;

class FConnect
{
  public:
    void init(vector<LayerParams> & layers);
    vector<LayerParams> m_layers;
    void fullyConnect(vector<Mat> & blob, Weights & wts, const int layerIdx);
};


#endif 
