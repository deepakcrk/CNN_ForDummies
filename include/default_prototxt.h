
#include <iostream>
// THIS IS INTENDED TO USE IF THERE IS NO PROTOTXT FILE SPECIFIED
//


enum LayerType
{
  CROP_LAYER = 1,
  CONV_LAYER = 2,
  POOL_LAYER = 3,
  ACT_LAYER  =  4,
  FC_LAYER   = 5,
  NORM_LAYER = 6
};

enum ActFunc
{
  RELU = 1,
  LeakyRELU = 2,
  Sigmoid = 3
};

enum PoolType
{
  MAXPOOL = 1,
  AVGPOOL = 2,
};

enum FilterType
{
  Gaussian = 1,
  Random = 2,
};


struct layerParams
{
  int layerNum;
  enum LayerType type;
  int cropX;           // Only For CropLayer
  int cropY;           // Only For CropLayer
  int outputs;         // Common For all valid Layers
  int windowSize       // Common For all valid Layers
  double lr;           // Common For all valid Layers
  double decay;        // Common For all valid Layers  
  double bias;         // Common For all valid Layers 
  int stride;          // Common For all valid Layers
  enum FilterType ft;  // For Convolution/FC Layer
  double filterStd;    // For Convolution/FC Layer 
  enum ActFunc af;     // Activation Function
  enum PoolType pt;    // Pooling Type
};
