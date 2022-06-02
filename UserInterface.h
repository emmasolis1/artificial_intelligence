#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "NeuralNetwork.h"

using namespace std;

class UserInterface {
  
  private:
  vector<vector<float>> input_70;
  vector<vector<float>> input_20;
  vector<vector<float>> input_10;
  vector<vector<float>> output_70;
  vector<vector<float>> output_20;
  vector<vector<float>> output_10;
  
  
  public:
  UserInterface();

  std::vector<std::vector<float>> loadTargetInputs();
  std::vector<std::vector<float>> loadTargetOutputs();
  vector<vector<float>> loadSavedWeights();
  vector<vector<float>> loadSavedBias();
  vector<vector<float>> dataStandardization(vector<vector<float>>& data);
  vector<vector<float>> dataNormalization(vector<vector<float>>& data);
  void request_data_standardization_or_normalization(vector<vector<float>>& data);
  std::vector<uint32_t> request_topology_info();
  uint32_t request_cant_epoch();
  float request_learning_rate();
  void request_save_neural_network(SimpleNeuralNetwork& nn);
  void data_separation(vector<vector<float>>& data_input, vector<vector<float>>& data_output);
  void create_new_neural_network();
  void load_neural_network();
  void show_menu();
  string toStringResults(SimpleNeuralNetwork myNeuNet,  vector<vector<float>> myTargetInputs);
  void run_simulation(SimpleNeuralNetwork myNeuNet, vector<vector<float>> myTargetInputs, vector<vector<float>> myTargetOutputs, uint32_t my_epoch);
  void print_results(string my_results);
  void print_welcome();
  
};

#endif