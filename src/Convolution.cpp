#include "Convolution.h"
#include "Weights.h"

void Convolution::init(vector<LayerParams> layers)
{
  m_layers = layers;
}


void Convolution::convolve(vector<Mat>& src, Weights& wts, const int layerIdx)
{
  vector<vector<Mat> > filts = wts.m_convWts[ layerIdx ];
    
  vector<Mat> out;

  if (src.size() == filts[0].size())
  {
    cerr << "CONV:: Filters     : " << filts.size() << endl;
    cerr << "CONV:: FiltersDepth: " << filts[0].size() << endl;

    for (int i=0; i<filts.size(); i++)
    {

      vector<Mat> added1; //FIXME can be avoide by adding imgs inside the loop
      for (int j=0; j<src.size(); j++)
      {
        Mat f;

        if (j >= filts.size())
        {
          cerr << "CONV:: #ERRORR.." << endl;
          cerr << "CONV:: #ERRORR.." << endl;
        }

        cerr << "CONV:: ImageSize : " << src[j].cols << " x " << src[j].rows << endl;

        cerr << "CONV:: FilterSize: " << filts[i][j].cols << " x " << filts[i][j].rows << endl;

        filter2D(src[j], f, -1, filts[i][j]);

        imshow("CONV:: Filtered", f);
        waitKey(100);
        added1.push_back (f);
      }

      for (int k=1; k<added1.size(); k++)
        added1[0] += added1[k];
      
      cerr << "CONV:: ImageSize : " << added1[0].cols << " x " << added1[0].rows << endl;

      out.push_back(added1[0] / added1.size());
    }
  }
  else
  {
    cerr << "CONV:: Not matching filters depth and images depth" << endl;
  }

  src = out;
}


