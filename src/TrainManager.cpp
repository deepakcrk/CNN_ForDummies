#include <TrainManager.h>
#include <opencv2/opencv.hpp>
#include <LayerContext.h>

using namespace cv;
using namespace std;

TrainManager::TrainManager()
{ }


TrainManager::~TrainManager()
{ }

void TrainManager::initLayers()
{
    m_wts.init(m_layers);
    m_pooler.init(m_layers);
    m_conv.init(m_layers);
    m_acti.init(m_layers);
    m_fcon.init(m_layers);
    m_norm.init(m_layers);
    m_smax.init(m_layers);
}

bool TrainManager::train(const char* prototxtFile, const char* configFile)
{ 
    fillSomeDefaultValues(m_layers);
    initLayers();

    //FIXME load as gray scale currently coded for gray scale only
    Mat src = imread("data/input.jpeg", CV_LOAD_IMAGE_GRAYSCALE);
    imshow("src", src);
    waitKey(0);

#define TOTAL_ITER 1

    for (int iter=0; iter < TOTAL_ITER; iter++)
    {
        forward(src);
        //backward();
    }
    return true;
}


void TrainManager::forward(Mat & src)
{
    vector<Mat> blob; 
    blob.push_back(src);

    //First Layer is "INPUT_LAYER" where original data is there
    m_wts.layerImgs[0] = blob;   //FIXME:  Move To INPUT DataLayer.
    m_wts.layerImgs[1] = blob;   //FIXME:  For CropLayer, Since Currently Code Is Not Written For CropLayer. (Move to Crop Layer Class)
                                   
    cerr << "Layers:   " << m_layers.size() << endl;
    cerr << "BlobSize: " << blob.size() << endl;

    vector<Mat> & out = m_wts.layerImgs[ 0 ];
    cerr << "BlobSize_:"  << out.size() << endl;

    //Starting from layerIdx=1, since first layer is Input_layer, where original data is filled.
    //FIXME, Move Input_Layer also to the below forLoop 
    for (int layerIdx=0; layerIdx<m_layers.size(); layerIdx++)
    {
      //if (m_layers[layerIdx].type == CROP_LAYER)
      //  cropper(m_wts, i);
      if (m_layers[layerIdx].type == CONV_LAYER)
      {
        m_conv.convolve(m_wts, layerIdx);
      }
      else if (m_layers[layerIdx].type == ACT_LAYER)
      {
        m_acti.activate(m_wts, layerIdx);
      }
      else if (m_layers[layerIdx].type == POOL_LAYER)
      {
        m_pooler.pooler(m_wts, layerIdx);
      }
      else if (m_layers[layerIdx].type == SOFTMAX_LAYER)
      {
        m_smax.softmax(m_wts, layerIdx);
      }
      // ....  ... ....  ....  ...  ....
      // ....  ... ....  ....  ...  ....
    }

}

bool TrainManager::fillSomeDefaultValues(vector<LayerParams> & layers)
{
    struct LayerParams layer0; 
    struct LayerParams layer1; 
    struct LayerParams layer2;
    struct LayerParams layer3;
    struct LayerParams layer4;
    struct LayerParams layer5;
    struct LayerParams layer6;
    struct LayerParams layer7;
    struct LayerParams layer8;
    struct LayerParams layer9;
    struct LayerParams layer10;

    /*************InputDataLayer************/
    layer0.layerNum = 0;
    layer0.type = INPUT_LAYER;  

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
    layer2.ft = Gaussian;
    layer2.filterStd = 0.1;

    /********* Activation Layer **********/
    layer3.layerNum = 3;
    layer3.type = ACT_LAYER;
    layer3.af = RELU;

    /*********** Pooling ***************/
    layer4.layerNum = 4;
    layer4.type = POOL_LAYER;
    layer4.windowSize = 5;
    layer4.pt = MAXPOOL;

    /*********** Conv Layer ***********/
    layer5.layerNum = 5;
    layer5.type = CONV_LAYER;
    layer5.outputs = 33;
    layer5.windowSize = 7;
    layer5.lr = 0.001;
    layer5.decay = 0.001;
    layer5.stride = 1;
    layer5.ft = Gaussian;
    layer5.filterStd = 0.1;

    /********** Activation Layer **********/
    layer6.layerNum = 6;
    layer6.type = ACT_LAYER;
    layer6.af = RELU;

    /************ Conv Layer ************/
    layer7.layerNum = 7;
    layer7.type = CONV_LAYER;
    layer7.outputs = 43;
    layer7.windowSize = 7;
    layer7.lr = 0.001;
    layer7.decay = 0.001;
    layer7.stride = 1;
    layer7.ft = Gaussian;
    layer7.filterStd = 0.1;


    /******** Activation Layer **********/
    layer8.layerNum = 8;
    layer8.type = ACT_LAYER;
    layer8.af = RELU;

    /********** Pooling Layer **********/
    layer9.layerNum = 9;
    layer9.type = POOL_LAYER;
    layer9.windowSize = 5;
    layer9.pt = MAXPOOL;

    /************ SOFTMAX_LAYER **********/
    layer10.layerNum = 10;
    layer10.type = SOFTMAX_LAYER;


    layers.push_back(layer0);
    layers.push_back(layer1);
    layers.push_back(layer2);
    layers.push_back(layer3);
    layers.push_back(layer4);
    layers.push_back(layer5);
    layers.push_back(layer6);
    layers.push_back(layer7);
    layers.push_back(layer8);
    layers.push_back(layer9);
    layers.push_back(layer10);
}
