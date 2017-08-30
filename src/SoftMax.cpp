#include "SoftMax.h"

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
