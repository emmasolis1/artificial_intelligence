#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class UserInterface {
  public:
    static vector<int> request_topology_info();
    static void print_welcome();
    static vector<vector<float>> loadTargetInputs();
    static vector<vector<float>> loadTargetOutputs();

  private:
  UserInterface();
};


#endif