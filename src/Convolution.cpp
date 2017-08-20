#include "Convolution.h"
#include "Weights.h"

void Convolution::init(vector<LayerParams> layers)
{
  m_layers = layers;
}


void Convolution::convolve(vector<Mat> src, int convLayer)
{

#if 0
  vector<vector> filts = m_weights.m_convWts[ convLayer ];

  if (src.size() == filts[0].size())
  {
    vector<Mat> out;
    for (int i=0; i<filts.size(); i++)
    {
      vector<Mat> added1; //FIXME can be avoide by adding imgs inside the loop
      for (int j=0; j<src.size(); j++)
      {
        Mat f;
        filter2D(src[i], f, -1, filts[i][j]);
        added1.push_back (f)
      }
      for (int k=1; k<added1.size(); k++)
        added1[0] += added1[k];
      out.push_back(added1[0]);
    }
  }

  src = out;
#endif
}


