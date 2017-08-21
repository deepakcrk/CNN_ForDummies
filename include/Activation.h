#include <LayerContext.h>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;

class Activation
{
  public:
    void init(vector<LayerParams> & layers);
    vector<LayerParams> m_layers;
    void activate(vector<Mat> & blob, const int & layerIdx);
};
