#include <Weights.h>


bool Weights::initWeights(/**************/)
{

#define ConvLayers 3
#define ConvLayer1_window 7
#define ConvLayer1_output 25
#define ConvLayer1_window 5
#define ConvLayer1_output 45
#define ConvLayer1_window 3
#define ConvLayer1_output 55

//Add above things in map
vector<pair<int, int> > windowOutput;
windowOutput.push_back(make_pair(ConvLayer1_window, ConvLayer1_output);
windowOutput.push_back(make_pair(ConvLayer2_window, ConvLayer2_output);
windowOutput.push_back(make_pair(ConvLayer3_window, ConvLayer3_output);


  //m_convWts
   for (int i=0; i<ConvLayers; i++)
   {
      vector<vector<Mat> > filts;
      int totalFilters = windowOutput[i].second; //x3 incase of Color Image Now code is only for GRAY scale
      int depth = 1;
      if (i != 0)
      {
        depth =windowOutput[i].second - 1;
      }

      for (int j=0; j<totalFilters; j++)
      {
        vector<Mat> filts3d;
        for (int k=0; k<depth;k++)
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
Weights::Weights(/****************/)
{
  initWeights();
}
