#include "Activation.h"

void Activation::init(vector<LayerParams> & layers)
{
  m_layers = layers;
}

void Activation::activate(Weights & wts, const int & layerIdx)
{

  vector<Mat>& out = wts.layerImgs[ layerIdx ];
  vector<Mat>& blob = wts.layerImgs[ layerIdx-1 ];

  out.resize(blob.size());

  enum ActFunc actiFun = m_layers[layerIdx].af;

  if (actiFun == RELU)
  {
    //SEE THIS: http://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#threshold
    //FIXME Validation required
    for (int i=0; i<blob.size(); i++)
    {
      imshow("b4act", blob[i]);
      threshold(blob[i], out[i], 0, 0/*NOT USED*/, THRESH_TOZERO);
      imshow("afterAct", out[i]);
      waitKey(0);
    }
  }

  else if (actiFun == LeakyRELU)
  {
    //Implement here..
  }
  else if (actiFun == Sigmoid)
  {
    //Implement here
  }
}


