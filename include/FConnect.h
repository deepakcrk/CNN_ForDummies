#ifndef _FCONNECT_LAYER
#define _FCONNECT_LAYER

#include <LayerContext.h>
#include <vector>

using namespace std;
using namespace cv;

class FConnect
{
  public:
    init(vector<LayerParams> layers);
    vector<LayerParams> m_layers;
};


#endif 
