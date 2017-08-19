
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



struct layerParams
{
  //BASED ON THE LAYER TYPE USE PARAMETERS
  enum LayerType type;
  int cropX;
  int cropY;
  int outputs;
  int windowSize  //use with pool aslo
  double lr;
  double decay;
  double bias;    //used with other layers also
  int stride;     //used with pool also
  int type; //gaussian
  int std;
  int actFunc; //convert it in to enum for relu leaky relu etc.
  int poolingType;
};
