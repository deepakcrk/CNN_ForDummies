#ifndef _WEIGHTS_
#define _WEIGHTS_

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <LayerContext.h>

using namespace std;
using namespace cv;

class Weights
{
  public:

    void init(vector<LayerParams>& layerParams);

    vector<vector<vector<Mat> > > m_convWts;

    vector<cv::Mat> m_fcWts;

    vector<LayerParams> m_layerParams;

    Size imageSizeForFC(const int& layerIndex);

    vector<vector<double> > m_finalOut;
};

#endif
