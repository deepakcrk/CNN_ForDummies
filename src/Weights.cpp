#include <Weights.h>
#include <LayerContext.h>

Size Weights::imageSizeForFC(const int& layerIndex)
{ }

void Weights::init(vector<LayerParams>& layers)
{
    m_layerParams = layers;

    m_convWts.resize(layers.size());

    layerImgs.resize(layers.size());

    m_finalOut.resize(layers.size());

    vector<pair<int, int> > windowOutput;

    for (int i=0; i<layers.size(); i++)
    {
        //Find the Size of the Image at FC layer
        if (layers[i].type == CONV_LAYER || layers[i].type == FC_LAYER)
            windowOutput.push_back(make_pair(layers[i].windowSize, layers[i].outputs));
        else
            continue;

        vector<vector<Mat> > filts;

        int totalFilters = windowOutput[windowOutput.size()-1].second; //x3 incase of Color Image Now code is only for GRAY scale

        int depth = 1;

        if (windowOutput.size() > 1)
            depth = windowOutput[windowOutput.size() - 2].second;

        for (int j = 0; j < totalFilters; j++)
        {
            vector<Mat> filts3d;

            for (int k = 0; k < depth; k++)
            {
                Mat filter1(windowOutput[windowOutput.size() - 1].first, windowOutput[windowOutput.size() - 1].first, CV_64FC1);

                randu(filter1, Scalar(-1.0), Scalar(1.0)); //FIXME make it double vals and make it Gaussian

                filts3d.push_back(filter1);
            }

            filts.push_back(filts3d);
        }

        m_convWts[i] = filts;
    }
}

