#include <LayerContext.h>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "Weights.h"

using namespace std;

class Activation
{
  public:
    void init(vector<LayerParams> & layers);
    vector<LayerParams> m_layers;
    void activate(Weights & wts, const int & layerIdx);
};
