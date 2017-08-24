#include "BackPropagation.h"
#include "Weights.h"

void BackPropagation::init() 
{
  cout << "BackPropagation Initialized.." << endl;
}
    
bool BackPropagation::reluDerivative(vector<Mat> blob)
{ 
  for (auto& it : blob)
  {
    //FIXME verify results
    threshold(it, it, 0, 1, THRESH_BINARY);
  }
}

bool BackPropagation::sigmoidDerivative(vector<Mat> blob)
{
 
}
bool BackPropagation::leakyReluDerivative(vector<Mat> blob)
{
  
}



double BackPropagation::backProp(Weights& wts, const int & layerIdx)
{
  //REFERENCE: https://sudeepraja.github.io/Neural/


  //For LastLayer
  // Mat last_d = ( [LastLayerOut]  - [GroundTruth] ) .* derivative(lastLayer) 


  //Delta = (transpose(WeightInPrevLayer)*(deltaInPrevLayer) .* derivative(CurrentLayer) )* Transpose(currentInput)


  //Weight Updation:

  // W =  W - * lr*W .*Delta
 
}
