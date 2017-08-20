#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <LayerContext.h>

using namespace std;
using namespace cv;

class Weights
{
  public:
    Weights(vector<LayerParams> layerParams);
    bool init(vector<LayerParams> layerParams);

    vector<vector<vector<cv::Mat> > > m_convWts;
    vector<cv::Mat> m_fcWts;
    vector<LayerParams> m_layerParams
}


