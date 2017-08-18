#include <iostream>
#include <TrainManager.h>

using namespace std;

int main(int argc, char** argv)
{
  cout << "CNN..." << endl;
  TrainManager trainer;

  trainer.train(argv[1], argv[2]);

  //if ()
  //test( ...);
}

