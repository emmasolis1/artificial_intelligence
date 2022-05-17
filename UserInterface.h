#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class UserInterface {
  public:
    vector<int> request_topology_info();
    void print_welcome();
    vector<vector<float>> loadTargetInputs();
    vector<vector<float>> loadTargetOutputs();

  private:
  UserInterface();
};


#endif