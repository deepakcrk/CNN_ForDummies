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

  int numOutputs =  m_layers[layerIdx].outputs;


  Mat t (1, numOutputs, CV_64FC1, Scalar(1)) ; //FIXME temporarly putting to 1, Modify based on configuration  
  Mat x (1, numOutputs, CV_64FC1, Scalar(1)) ; // Fill values accordingly

  if (wts.m_finalOut[layerIdx].size() != numOutputs)
    cerr << "BACKPROPAGATION:ERROR.." << endl;

  for(int i=0; i<x.rows; ++i)
    for(int j=0; j<x.cols; ++j)
      x.at<double>(i, j) = wts.m_finalOut[layerIdx][j];

  Mat derivative ; // wts.m_finalOut[ layerIdx ] //properly assign //FIXME XXX

  Mat derE = ( x - t ).mul(  derivative  );  

  //For LastLayer
  // Mat last_d = ( [LastLayerOut]  - [GroundTruth] ) .* derivative(lastLayer)

  //Delta = (transpose(WeightInPrevLayer)*(deltaInPrevLayer) .* derivative(CurrentLayer) )* Transpose(currentInput)


  //Weight Updation:

  // W =  W - * lr*W .*Delta
 
}
