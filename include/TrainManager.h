#ifndef _TRAINMANAGER_
#define _TRAINMANAGER_

#include <iostream>
#include <opencv2/opencv.hpp>
#include "LayerContext.h"
#include "Pooling.h"
#include "Activation.h"
#include "Normalization.h"
#include "Convolution.h"
#include "FConnect.h"
#include "Weights.h"

using namespace std;
using namespace cv;

class TrainManager 
{
	public:
		TrainManager();
		~TrainManager();

        vector<LayerParams> m_layers;

        Weights m_wts ;
        Pooling m_pooler ;
        Convolution m_conv ;
        Activation m_acti ;
        FConnect m_fcon ;
        Normalization m_norm ;

        void initLayers();
		
  		bool train(const char* prototxtFile, const char* configFile);

        bool fillSomeDefaultValues(vector<LayerParams> & layers);

        void forward(Mat src);
};

#endif
