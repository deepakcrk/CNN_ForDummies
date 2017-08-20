#include <TrainManager.h>
#include <opencv2/opencv.hpp>
#include <LayerContext.h>

using namespace cv;
using namespace std;


bool TrainManager::fillSomeDefaultValues(vector<LayerParams> & layers)
{
 struct LayerParams layer1; 
 struct LayerParams layer2;
 struct LayerParams layer3;
 struct LayerParams layer4;
 struct LayerParams layer5;
 struct LayerParams layer6;
 struct LayerParams layer7;
 struct LayerParams layer8;
 struct LayerParams layer9;
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

forward(Mat src)
{
  for (int i=0; i<layers.size(); i++)
  {
    if (layers[i].LayerType == CROP_LAYER)
      cropper(src, i);

    if (layers[i].LayerType == CONV_LAYER)
      m_conv.convolve(src, i);

    if (layers[i].LayerType == POOL_LAYER)
      m_pooler.pooling(src, i);

    if (layers[i].LayerType == ACT_LAYER)
      m_act.activation(src, i);
  }

}

void TrainManager::initLayers()
{
  m_wts.init(m_layers);
  m_pooler.init(m_layers);
  m_conv.init(m_layers);
  m_acti.init(m_layers);
  m_fcon.init(m_layers);
  m_norm.init(m_layers);
}


bool TrainManager::train(const char* prototxtFile, const char* configFile)
{
 
 fillSomeDefaultValues(m_layers);

 initLayers();

 //FIXME load as gray scale currently coded for gray scale only
 Mat src = imread("input.jpeg");
 imshow("src", src);
 waitKey(0);

 forward(image /*************/ );
 
 return true;
}
