#ifndef DATAPREPARER_H
#define DATAPREPARER_H
#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class DataPreparer {
  public:
    std::vector<float> minValues;
    std::vector<float> maxValues;

    DataPreparer();
    DataPreparer(std::string dataset_path);
    void calculateMaxAndMinValues(std::string dataset_path);
    float normalizeInput(float input, int column);
};

#endif