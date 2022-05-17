#include <iostream>
#include <fstream>
#include <sstream>
#include "NeuralNetwork.h"


using namespace std;

std::vector<int> request_topology_info();
void print_welcome();
std::vector<std::vector<float>> loadTargetInputs();
std::vector<std::vector<float>> loadTargetOutputs();

int main()
{
    print_welcome();
    loadTargetOutputs();
    loadTargetInputs();
    request_topology_info();

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
    cout << "training completed\n";

    for(auto input : targetInputs)
    {
        nn.feedForward(input);
        auto preds = nn.getPrediction();
        cout << input[0] << "," << input[1] << " -> " << preds[0] << endl;
    }

    return 0;
}


void print_welcome() {
    cout << R"(
            ░▀▀█▀▀░█▀▀░█▀▀░█░░█▀▀▄░█░█▀▀░░░▒█▄░▒█░█▀▀░█░▒█░█▀▀▄░█▀▀▄░█░░░░▒█▄░▒█░█▀▀░▀█▀░█░░░█░▄▀▀▄░█▀▀▄░█░▄
            ░░▒█░░░█▀▀░▀▀▄░█░░█▄▄█░░░▀▀▄░░░▒█▒█▒█░█▀▀░█░▒█░█▄▄▀░█▄▄█░█░░░░▒█▒█▒█░█▀▀░░█░░▀▄█▄▀░█░░█░█▄▄▀░█▀▄
            ░░▒█░░░▀▀▀░▀▀▀░▀▀░▀░░▀░░░▀▀▀░░░▒█░░▀█░▀▀▀░░▀▀▀░▀░▀▀░▀░░▀░▀▀░░░▒█░░▀█░▀▀▀░░▀░░░▀░▀░░░▀▀░░▀░▀▀░▀░▀
        )" << '\n';
}

vector<int> request_topology_info() {
    vector<int> toplogy;
    int answer = 0;
    cout<<"How many input neurons?"<<endl;
    cin>>answer;
    toplogy.push_back(answer);
    cout<<"How many hidden layers?"<<endl;
    int hidden_layers = 0;
    cin>>hidden_layers;
    for (short i=0; i<hidden_layers; i++) {
        cout<<"How many neurons in the hidden layer "<<i+1<<"?"<<endl;
        cin>>answer;
        toplogy.push_back(answer);
    }
    cout<<"How many output neurons?"<<endl;
    cin>>answer;
    toplogy.push_back(answer);

    return toplogy;
}

vector<vector<float>> loadTargetInputs() {
    vector<vector<float>> my_matrix = {};
    string dataset_path;
    cout<<"Enter targets INPUTS path (do no include the expected results): ";
    cin>>dataset_path;

    // Tools for reading the file.
    ifstream fin;
    fin.open(dataset_path);
    string line;

    // Read file line by line.
    while (fin) {
        // Read a Line from File
        getline(fin, line);
        vector<float> new_vector;
 
        stringstream ss(line);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            new_vector.push_back(stof(substr));
        }
        // Add the new vector<float> to the matrix (main vector).
        my_matrix.push_back(new_vector);
    }
    // Close the file
    fin.close();
    cout<<"Target inputs loaded succesfully..."<<endl;

    return my_matrix;
}

vector<vector<float>> loadTargetOutputs() {
    vector<vector<float>> my_matrix = {};
    string dataset_path;
    cout<<"Enter targets OUTPUTS path (do no include the expected results): ";
    cin>>dataset_path;

    // Tools for reading the file.
    ifstream fin;
    fin.open(dataset_path);
    string line;

    // Read file line by line.
    while (fin) {
        // Read a Line from File
        getline(fin, line);
        vector<float> new_vector;
 
        stringstream ss(line);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            new_vector.push_back(stof(substr));
        }
        // Add the new vector<float> to the matrix (main vector).
        my_matrix.push_back(new_vector);
    }

    // Close the file
    fin.close();
    cout<<"Target outputs loaded succesfully..."<<endl;

    return my_matrix;
}