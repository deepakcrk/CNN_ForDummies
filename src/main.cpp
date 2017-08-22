#include <iostream>

#include "TrainManager.h"
#include "Utils.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Starting: CNN" << endl;

    ConfigMgr confMgr(argc, argv); 

    TrainManager trainer;

    if (confMgr.mode == 1)
        trainer.train(argv[1], argv[2]);
    else if (confMgr.mode == 2)
        cout << "test: under construction.." << endl;
}
