#include <TrainManager.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;



bool TrainManager::train(const char* prototxtFile, const char* configFile)
{
 //initWeights(prototxtFile, configFile);
 //currently doing ONE forwardPass only for ONE image

 //FIXME load as gray scale currently coded for gray scale only
 Mat src = imread("input.jpeg");
 imshow("src", src);
 waitKey(0);

 ForwardPass fwd;

 fwd.forward(image /*************/ );
 


 return true;
}
