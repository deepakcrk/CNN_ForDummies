#include "SoftMax.h"


void SoftMax::init(vector<LayerParams> & layers)
{
  m_layers = layers;
}

void SoftMax::softmax(vector<Mat> & src, vector<Mat> & dst)
{
  dst.resize(src.size());
  double sum = 0;

  for (int i=0; i<src.size(); i++)
  {
    cv::exp(src[i], dst[i]);
    sum += cv::sum(dst[i])[0];
  }

  for (int i=0; i<dst.size(); i++)
    dst[i] = dst[i] / sum;

}
void SoftMax::softmax(Mat & src, Mat & dst)
{
  cv::exp(src, dst);
  double s = cv::sum(dst)[0];
  dst = dst / s; 
}


void SoftMax::softmax(vector<double> & src, vector<double> & dst)
{
  dst.resize(src.size());
  double sum = 0;

  for (int i=0; i<src.size(); i++)
  {
    dst[i] = exp (src[i]);
    sum += dst[i];
  }

  for (int i=0; i<dst.size(); i++)
    dst[i] = dst[i] / sum;
}

void SoftMax::softmax(Weights& wts, const int& layerIdx)
{
  //FIXME XXX
  //CURRENTLY ASSUMING PREVIOUS LAYER IS FCONNECT
  //AND PREVIOUS LAYER OUTPUT IS A VECTOR.
  softmax(wts.m_finalOut[layerIdx - 1], wts.m_finalOut[layerIdx]);
}


