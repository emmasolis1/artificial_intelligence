#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#pragma once
#include "Matrix.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

/*

                1         2        n
    [in] ->    [10]      [20]  ... 
                         [21]  ... [] -> out
    [in] ->    [11]      [22]  ... 

            [10] -> [w10,20],[w10,21],[w10,22] // weight
            [11] -> [w11,20],[w11,21],[w11,22]

            [20] = [10] * [w10,20] + [11] * [w11,20] + [b20]
            [21] = [10] * [w10,21] + [11] * [w11,21] + [b21]
            [22] = [10] * [w10,22] + [11] * [w11,22] + [b22]
            
            
            [3 * 2]


            feedForward -> output;
            error = target - output; (minimization of err) <- minima
            derr = d/dw(error) = +, -
            derr = derr * learning rate
            transpose(values) [....]
            dw = [.] * derr;
                 [.]
                 [.]
                 [.]

            weight = weight + dw;


*/


using namespace std;

inline float Sigmoid(float x)
{
    return 1.0 / (1 + exp(-x));
}

inline float Dsigmoid(float x)
{
    return x * (1 - x);
}



class SimpleNeuralNetwork
{

public:
    vector<u_int32_t> _topology; // {3, 2, 1}
    vector<Matrix> _weightMatrices;
    vector<Matrix> _valueMatrices;
    vector<Matrix> _biasMatrices;
    float _learningRate;


    //SimpleNeuralNetwork();


    SimpleNeuralNetwork(vector<u_int32_t> topology, float learningRate = 0.1f);

    SimpleNeuralNetwork(vector<vector<float>> fileWeights, vector<vector<float>> fileBias);

    bool feedForward(vector<float> input);

    bool backPropagate(vector<float> targetOutput);

    bool saveWeights(const string& filename);

    bool saveBias(const string& filename);

    vector<float> getPrediction();

};

#endif