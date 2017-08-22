#include "FConnect.h"

void FConnect::init(vector<LayerParams> & layers)
{
    m_layers =layers;
}

void FConnect::fullyConnect(vector<Mat> & blob, Weights & wts, const int layerIdx)
{
 
 int outs = m_layers[layerIdx].outputs;
 /*******************************************/
 /***MOVE FC WEIGHTS INIT TO WEIGHTS CLASS***/
 //
 // Calculate the size of the image at Fully connected layer and in the begining and 
 // initialize the weight in the FConnect along with the other weights in the Weights class
 //
 // Currently initailization is done so that size of the image is obtained directly. And to
 // avoid the image size calculation. 
 //
 if (wts.m_convWts[ layerIdx ].size() == 0)
 {
   vector<vector<Mat> > filts;
   //NOT INITIALIZED. Initialization required.
   for (int i=0; i<outs; i++)
   {
     vector<Mat> filts3d;
     for (int j=0; j<blob.size(); j++)
     {
       Mat filter1(blob[0].rows, blob[0].cols, CV_64FC1);
       randu (filter1, Scalar(-1.0), Scalar(1.0)); //MAKE IT BASED ON FILTER TYPE
       filts3d.push_back(filter1);
     }
     filts.push_back(filts3d);
   }
   wts.m_convWts[layerIdx] = filts;
 }
 /*******************************************/

 if (wts.m_finalOut[layerIdx].size() == 0)
 {
   wts.m_finalOut[layerIdx].resize(outs);
 }

 for (int i=0; i<outs; i++)
 {
   double sum=0;
   for (int j=0; j<blob.size(); j++)
   {
     Mat tmp = blob[j].mul( wts.m_convWts[layerIdx][i][j]);

     sum += cv::sum(tmp)[0]; //XXX FIXME

   }
    wts.m_finalOut[layerIdx][i] = sum;
 }
}

