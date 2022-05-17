<<<<<<< HEAD
#include "UserInterface.h"

int main()
{
    UserInterface ui;
    ui.print_welcome();
    ui.show_menu();
=======
#include <iostream>
#include "NeuralNetwork.h"
#include <string>


using namespace std;


int main()
{
    vector<uint32_t> topology = {2, 3, 1};

    SimpleNeuralNetwork nn(topology, 0.1);

    vector<vector<float>> targetInputs {
        {0.0f, 0.0f},
        {1.0f, 1.0f},
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    };

    vector<vector<float>> targetOutputs {
        {0.0f},
        {0.0f},
        {1.0f},
        {1.0f}
    };

    uint32_t epoch = 100000;


    cout << "training started\n";
    for(uint32_t i = 0; i < epoch; ++i)
    {
        uint32_t index = rand() % 4;
        nn.feedForward(targetInputs[index]);
        nn.backPropagate(targetOutputs[index]);
    }

    string name = "savedWeights.csv";
    nn.saveWeights(name);
    cout << "training completed\n";

    for(auto input : targetInputs)
    {
        nn.feedForward(input);
        auto preds = nn.getPrediction();
        cout << input[0] << "," << input[1] << " -> " << preds[0] << endl;
    }
>>>>>>> add saveWeights() method

    return 0;
}

