#include "ForwardPass.h"

ForwardPass::forward(Mat src)
{
  for (int i=0; i<layers.size(); i++)
  {
    if (layers[i].LayerType == CROP_LAYER)
      cropper(src, i);
    
    if (layers[i].LayerType == CONV_LAYER)
      convolution(src, i);
    
    if (layers[i].LayerType == POOL_LAYER)
      pooling(src, i);
    
    if (layers[i].LayerType == ACT_LAYER)
      activation(src, i);
  }

}
