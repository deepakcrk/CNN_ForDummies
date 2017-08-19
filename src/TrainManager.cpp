#include <TrainManager.h>
#include <opencv2/opencv.hpp>
#include <default_prototxt.h>
using namespace cv;
using namespace std;


bool TrainManager::fillSomeDefaultValues(vector<layerParams> & layers)
{
 struct layerParams layer1; 
 struct layerParams layer2;
 struct layerParams layer3;
 struct layerParams layer4;
 struct layerParams layer5;
 struct layerParams layer6;
 struct layerParams layer7;
 struct layerParams layer8;
 struct layerParams layer9;
 /*************Crop Layer***************/
 layer1.layerNum = 1;
 layer1.type = CROP_LAYER;  
 layer1.cropX = 448;
 layer1.cropY = 448;
 
 /**********Conv Layer ****************/
 layer2.layerNum = 2;
 layer2.type = CONV_LAYER;
 layer2.outputs = 11;
 layer2.windowSize = 5;
 layer2.lr = 0.001;
 layer2.decay = 0.001;
 layer2.stride = 1;
 layer2.ft = 1;
 layer2.std = 0.1;
 
 /********* Activation Layer **********/
 layer3.layerNum = 3;
 layer3.type = ACT_LAYER;
 layer3.af = 1;

 /*********** Pooling ***************/
 layer4.layerNum = 4;
 layer4.type = POOL_LAYER;
 layer4.windowSize = 5;
 layer4.pt = 1;

 /*********** Conv Layer ***********/
 layer5.layerNum = 5;
 layer5.type = CONV_LAYER;
 layer5.outputs = 33;
 layer5.windowSize = 7;
 layer5.lr = 0.001;
 layer5.decay = 0.001;
 layer5.stride = 1;
 layer5.ft = 1;
 layer5.std = 0.1;

 /********** Activation Layer **********/
 layer6.layerNum = 6;
 layer6.type = ACT_LAYER;
 layer6.af = 1;

 /************ Conv Layer ************/
 layer7.layerNum = 7;
 layer7.type = CONV_LAYER;
 layer7.outputs = 43;
 layer7.windowSize = 7;
 layer7.lr = 0.001;
 layer7.decay = 0.001;
 layer7.stride = 1;
 layer7.ft = 1;
 layer7.std = 0.1;


 /******** Activation Layer **********/
 layer8.layerNum = 8;
 layer8.type = ACT_LAYER;
 layer8.af = 1;

 /********** Pooling Layer **********/
 layer9.layerNum = 9;
 layer9.type = POOL_LAYER;
 layer9.windowSize = 5;
 layer9.pt = 1;


 layers.push_back(layer1);
 layers.push_back(layer2);
 layers.push_back(layer3);
 layers.push_back(layer4);
 layers.push_back(layer5);
 layers.push_back(layer6);
 layers.push_back(layer7);
 layers.push_back(layer8);
 layers.push_back(layer9);

}



bool TrainManager::train(const char* prototxtFile, const char* configFile)
{
 
  //Layer Context
  vector<layerParams> layers;
 

 fillSomeDefaultValues(layers);

 Weights     wts    (layers);
 Pooling     pooler (layers);
 Convolution conv   (layers);
 Activation  acti   (layers);
 FConnect    fcon   (layers);
 Normalization norm (layers);
 
 ForwardPass  fwd (layers);
 BackwardPass bwd (layers);

 fwd.set (wts, pooler, conv, acti, fcon, norm);
 bwd.set (wts, pooler, conv, acti, fcon, norm);


 //FIXME load as gray scale currently coded for gray scale only
 Mat src = imread("input.jpeg");
 imshow("src", src);
 waitKey(0);


 fwd.forward(image /*************/ );
 


 return true;
}
