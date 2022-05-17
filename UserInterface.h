#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class UserInterface {
  public:
    UserInterface();
    std::vector<int> request_topology_info();
    void print_welcome();
    std::vector<std::vector<float>> loadTargetInputs();
    std::vector<std::vector<float>> loadTargetOutputs();
};

UserInterface::UserInterface() {}


#endif