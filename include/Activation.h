#include <LayerContext.h>
#include <iostream>
#include <vector>


class Activation
{
  public:
    void init(vector<LayerParams> layers);
    vector<LayerParams> m_layers;
};
