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



double BackPropagation::backProp(Weights& wts)
{
  
}
