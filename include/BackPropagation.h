#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
#include <LayerContext.h>
#include "Weights.h"

class BackPropagation
{
  public:
    void init();

    vector<LayerParams> m_layers;

    double backProp(Weights& wts, const int & layerIdx);
    
    bool reluDerivative(vector<Mat> blob);
    
    bool sigmoidDerivative(vector<Mat> blob);
    
    bool leakyReluDerivative(vector<Mat> blob);
};
