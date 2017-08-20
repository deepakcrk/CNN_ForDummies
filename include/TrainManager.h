#ifndef _TRAINMANAGER_
#define _TRAINMANAGER_

#include <iostream>
#include <LayerContext.h>

class TrainManager 
{
	public:
		Trainer();
		~Trainer();

        vector<LayerParams> m_layers;

        Weights m_wts ;
        Pooling m_pooler ;
        Convolution m_conv ;
        Activation m_acti ;
        FConnect m_fcon ;
        Normalization m_norm ;

        void initLayers();
		
  		bool train(const char* prototxtFile, const char* configFile);
};

#endif
