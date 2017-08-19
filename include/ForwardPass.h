#include <opencv2/opencv.hpp>

class ForwardPass
{
  ForwardPass(vector<layerParams> layers);
  forward(Mat img);
}
