#include "Convolution.h"
#include "Weights.h"

void Convolution::init(vector<LayerParams> layers)
{
  m_layers = layers;
}


void Convolution::convolve(vector<Mat> & src, Weights & wts, const int layerIdx)
{

#if 1
  vector<vector<Mat> > filts = wts.m_convWts[ layerIdx ];
    
  vector<Mat> out;

  if (src.size() == filts[0].size())
  {
    cerr << "Filters     : " << filts.size() << endl;
    cerr << "FiltersDepth: " << filts[0].size() << endl;

    for (int i=0; i<filts.size(); i++)
    {

      vector<Mat> added1; //FIXME can be avoide by adding imgs inside the loop
      for (int j=0; j<src.size(); j++)
      {
        Mat f;
        filter2D(src[i], f, -1, filts[i][j]);

        imshow("Filtered", f);
        waitKey(0);
        added1.push_back (f);
      }
      for (int k=1; k<added1.size(); k++)
        added1[0] += added1[k];

      out.push_back(added1[0] / added1.size());
    }
  }
  else
  {
    cerr << "Not matching filters depth and images depth" << endl;
  }

  src = out;
#endif
}


