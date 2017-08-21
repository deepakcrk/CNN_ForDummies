#include "Pooling.h"

void Pooling::init(vector<LayerParams> & layers)
{
  m_layers =layers;
}

void Pooling::pooler(vector<Mat> & blob, const int & layerIdx)
{ 
  if (blob.size() == 0) return;

  double wind = (double) m_layers[layerIdx].windowSize;

  if (m_layers[layerIdx].pt == MAXPOOL && 0)  
  {
    //Implement here.
  }
  else if (m_layers[layerIdx].pt == AVGPOOL || 1) 
  {
    cerr << "POOL:BlobSize: " << blob.size() << endl;
    for (int i=0; i<blob.size(); i++) 
    {
      Mat tmp;
      resize(blob[i], tmp, Size(round(blob[i].cols/wind), round(blob[i].rows/wind)), wind, wind);

      imshow("b4Pool", blob[i]);
      imshow("afterPool", tmp);
      waitKey(0);

      blob[i] = tmp;
    }
  }
}

