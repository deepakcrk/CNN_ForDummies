#ifndef _TRAINMANAGER_
#define _TRAINMANAGER_

#include <iostream>

class TrainManager 
{
	public:
		Trainer();
		~Trainer();
		
  		bool train(const char* prototxtFile, const char* configFile);
};

#endif
