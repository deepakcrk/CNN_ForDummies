#include "Pooling.h"

void Pooling::init(vector<LayerParams> & layers)
{
  m_layers =layers;
}

void Pooling::pooler(Weights & wts, const int & layerIdx)
{ 
  vector<Mat>& blob = wts.layerImgs[ layerIdx-1 ];
  vector<Mat>& out = wts.layerImgs[ layerIdx ];
  
  if (blob.size() == 0) return;
  
  out.clear(); //FIXME
  out.resize(blob.size());


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
      resize(blob[i], out[i], Size(round(blob[i].cols/wind), round(blob[i].rows/wind)), wind, wind);
      imshow("b4Pool", blob[i]);
      imshow("afterPool", out[i]);
      waitKey(0);
    }
  }
}

