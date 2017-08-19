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

 //
 //fill layerNum parameter also, call take the actions based on layer num
 //for example Convolution(image, 7);
 //Will do convolution based on 7th layaer
 //
 //
 //
 //
 //Layer1 is crop layer filling parameters
 layer1.type = CROP_LAYER;  
 layer1.cropX = 448;
 layer1.cropY = 448;
 
 //Layer2 is conv layer filling parameters
 layer2.type = CONV_LAYER;
 layer2.outputs = 11;
 layer2.windowSize = 5;
 layer2.lr = 0.001;
 layer2.decay = 0.001;
 layer2.stride = 1;
 layer2.filltype = 1;
 layer2.std = 0.1;
 
 //Activation Layer
 layer3.type = ACT_LAYER;
 layer3.actFunc = 1;

 //Pooling Layer
 layer4.type = POOL_LAYER;
 layer4.windowSize = 5;

 //Layer5 is conv layer filling parameters
 layer5.type = CONV_LAYER;
 layer5.outputs = 33;
 layer5.windowSize = 7;
 layer5.lr = 0.001;
 layer5.decay = 0.001;
 layer5.stride = 1;
 layer5.filltype = 1;
 layer5.std = 0.1;

 //Activation Layer
 layer6.type = ACT_LAYER;
 layer6.actFunc = 1;

 //Layer7 conv layer filling parameters
 layer7.type = CONV_LAYER;
 layer7.outputs = 43;
 layer7.windowSize = 7;
 layer7.lr = 0.001;
 layer7.decay = 0.001;
 layer7.stride = 1;
 layer7.filltype = 1;
 layer7.std = 0.1;


 //Activation Layer
 layer8.type = ACT_LAYER;
 layer8.actFunc = 1;

 //Pooling Layer
 layer9.type = POOL_LAYER;
 layer9.windowSize = 5;




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
 /************** CREATE LAYER PARAMS ***********************/
 vector<layerParams> layers;
 

 fillSomeDefaultValues(layers);
 Weights wts;
 wts.initWeights(layers);
 initPooling(layers);
 initConvolution();

 //PASS THE 'layers' TO ALL OTHER CLASSES (Weights, Convolution, ForwardPass), TO
 //INITIALIZE THEM. eX. INITIALIZE INTIAL WEIGHTS (FILTERS) WITH THE info inside 'layers'
 //






 //FIXME load as gray scale currently coded for gray scale only
 Mat src = imread("input.jpeg");
 imshow("src", src);
 waitKey(0);

 ForwardPass fwd;

 fwd.forward(image /*************/ );
 


 return true;
}
