#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"
#include "Weights.h"

class BackPropagation
{
  public:
    void init();
    double backProp(Weights& wts);
    bool reluDerivative(vector<Mat> blob);
    bool sigmoidDerivative(vector<Mat> blob);
    bool leakyReluDerivative(vector<Mat> blob);
};
