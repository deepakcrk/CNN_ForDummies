#ifndef _TRAINMANAGER_
#define _TRAINMANAGER_

#include <iostream>

class TrainManager 
{
	public:
		Trainer();
		~Trainer();
        Weights     m_wts    (layers);
        Pooling     m_pooler (layers);
        Convolution m_conv   (layers);
        Activation  m_acti   (layers);
        FConnect    m_fcon   (layers);
        Normalization m_norm (layers);


		
  		bool train(const char* prototxtFile, const char* configFile);
};

#endif
