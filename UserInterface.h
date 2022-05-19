#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#pragma once

#include <fstream>
#include <sstream>
#include <vector>

#include "NeuralNetwork.h"

using namespace std;

class UserInterface {
  public:
  UserInterface();

  std::vector<std::vector<float>> loadTargetInputs();
  std::vector<std::vector<float>> loadTargetOutputs();
  std::vector<uint32_t> request_topology_info();
  uint32_t request_cant_epoch();
  float request_learning_rate();
  void request_save_weights(SimpleNeuralNetwork& nn);
  void create_new_neural_network();
  void show_menu();
  string toStringResults(SimpleNeuralNetwork myNeuNet,  vector<vector<float>> myTargetInputs);
  void run_simulation(SimpleNeuralNetwork myNeuNet, vector<vector<float>> myTargetInputs, vector<vector<float>> myTargetOutputs, uint32_t my_epoch);
  void print_results(string my_results);
  void print_welcome();
  
};

#endif