#include <TrainManager.h>


/********* Now using hard coded layers as follows **********/
//2ClassProb
//layer1:   Crop Layer: 448x448
//layer2:   ConvLayer: lr=1, output=96, stride=1, weghtFill=gaussian, std=0.01
//layer3:   ReLu
//layer4:   Pooling 3x3 max
//layer5:   ConvLayer: lr=1, output=256, stride=1, weghtFill=gaussian, std=0.01
//layer3:   ReLu
//layer4:   Pooling 3x3 max
//layer4:   InnerProduct

//TrainManager::TrainManager()
//{
//}

bool TrainManager::train(const char* prototxtFile, const char* configFile)
{
 //initWeights(prototxtFile, configFile);
 
 //currently doing forwardPass




 return true;
}
