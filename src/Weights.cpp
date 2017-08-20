#include <Weights.h>

Weights::Weights(vector<LayerParams> & layerParams)
{
  m_layerParams = layerParams;
  initWeights(layerParams);
}


bool Weights::init(vector<LayerParams> layers)
{

  //Add above things in map
  vector<pair<int, int> > windowOutput;
  for (int i=0; i<layers.size(); i++)
  {
    if (layers[i].type == CONV_LAYER)
      windowOutput.push_back(make_pair(layers[i].windowSize, layers[i].outputs));
  }

  //FIXME WEIGHTS FOR FULLY CONNECTED NOT INITIALIZED. XXX NEED TO ADD THAT


  //m_convWts
  for (int i=0; i<ConvLayers; i++)
  {
    vector<vector<Mat> > filts;
    int totalFilters = windowOutput[i].second; //x3 incase of Color Image Now code is only for GRAY scale
    int depth = 1;
    if (i != 0)
    {
      depth =windowOutput[i - 1].second;
    }

    for (int j=0; j<totalFilters; j++)
    {
      vector<Mat> filts3d;
      for (int k=0; k<depth; k++)
      {
        Mat filter1(windowOutput[i].first, windowOutput[i].first, CV_64FC1);
        randu (filter1, Scalar(-1.0), Scalar(1.0)); //FIXME make it double vals and make it Gaussian
        filts3d.push_back(filter1);
      }
      filts.push_back(filts3d);
    }
    m_convWts.push_back(filts);
  }
}

