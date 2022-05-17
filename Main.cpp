#include <iostream>
#include <fstream>
#include <sstream>
#include "NeuralNetwork.h"


using namespace std;

std::vector<uint32_t> request_topology_info();
void print_welcome();
std::vector<std::vector<float>> loadTargetInputs();
std::vector<std::vector<float>> loadTargetOutputs();
uint32_t request_cant_epoch();
float request_learning_rate();
void show_menu();
void create_new_neural_network();

int main()
{
    print_welcome();
    show_menu();
    return 0;
}


void print_welcome() {
    cout << R"(
            ░▀▀█▀▀░█▀▀░█▀▀░█░░█▀▀▄░█░█▀▀░░░▒█▄░▒█░█▀▀░█░▒█░█▀▀▄░█▀▀▄░█░░░░▒█▄░▒█░█▀▀░▀█▀░█░░░█░▄▀▀▄░█▀▀▄░█░▄
            ░░▒█░░░█▀▀░▀▀▄░█░░█▄▄█░░░▀▀▄░░░▒█▒█▒█░█▀▀░█░▒█░█▄▄▀░█▄▄█░█░░░░▒█▒█▒█░█▀▀░░█░░▀▄█▄▀░█░░█░█▄▄▀░█▀▄
            ░░▒█░░░▀▀▀░▀▀▀░▀▀░▀░░▀░░░▀▀▀░░░▒█░░▀█░▀▀▀░░▀▀▀░▀░▀▀░▀░░▀░▀▀░░░▒█░░▀█░▀▀▀░░▀░░░▀░▀░░░▀▀░░▀░▀▀░▀░▀
        )" << '\n';
}

vector<uint32_t> request_topology_info() {
    vector<uint32_t> toplogy = {};
    uint32_t answer = 0;
    cout<<"How many input neurons?"<<endl;
    cout<<"input: ";
    cin>>answer;
    toplogy.push_back(answer);
    cout<<"How many hidden layers?"<<endl;
    uint32_t hidden_layers = 0;
    cout<<"input: ";
    cin>>hidden_layers;
    for (short i=0; i<hidden_layers; i++) {
        cout<<"Hidden Layer "<<i+1<<": # of neurons?"<<endl;
        cout<<"input: ";
        cin>>answer;
        toplogy.push_back(answer);
    }
    cout<<"How many output neurons?"<<endl;
    cout<<"input: ";
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

uint32_t request_cant_epoch() {
    uint32_t epoch;
    cout<<"Enter the number of epoch to simulate: ";
    cin>>epoch;
    return epoch;
}

void show_menu() {
    cout<<"Welcome to the unique Neural Network...   " << R"( ╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) )" << "\n\n";
    cout<<"What do you need?\n1. LOAD a neural network.\n2. CREATE a neural network.\n3. Exit."<<endl;
    bool exit = false; 
    int option = 0;
    while(!exit) {
        cout<<"input: ";
        cin>>option;
        switch (option) {
        case 1:
            // Method for loading a neural network (Alvaro).
            break;
        
        case 2:
            create_new_neural_network();
            break;

        case 3:
            exit = true;
            break;

        default:
            break;
        }
    }

}

float request_learning_rate() {
    float learning_rate = 0.0f;
    cout<<"Enter the learning rate: ";
    cin>>learning_rate;
    return learning_rate;
}

void create_new_neural_network() {
    // vector<uint32_t> topology = {2, 3, 1};

    // SimpleNeuralNetwork nn(topology, 0.1);

    // vector<vector<float>> targetInputs {
    //     {0.0f, 0.0f},
    //     {1.0f, 1.0f},
    //     {1.0f, 0.0f},
    //     {0.0f, 1.0f}
    // };

    // vector<vector<float>> targetOutputs {
    //     {0.0f},
    //     {0.0f},
    //     {1.0f},
    //     {1.0f}
    // };

    // uint32_t epoch = 100000;

    // Request main info.
    vector<uint32_t> topology = request_topology_info();
    float learning_rate = request_learning_rate();
    SimpleNeuralNetwork nn(topology, learning_rate);
    vector<vector<float>> targetInputs = loadTargetInputs();
    vector<vector<float>> targetOutputs = loadTargetOutputs();
    uint32_t epoch = request_cant_epoch();

    // Show summary of neural info.
    
    cout << "training started\n";
    for(uint32_t i = 0; i < epoch; ++i)
    {
        uint32_t index = rand() % 4;
        nn.feedForward(targetInputs[index]);
        nn.backPropagate(targetOutputs[index]);
    }
    cout << "training completed\n";

    string results = "";
    for(auto input : targetInputs)
    {
        nn.feedForward(input);
        auto preds = nn.getPrediction();
        //cout << input[0] << "," << input[1] << " -> " << preds[0] << endl;
        for (size_t i=0; i<input.size(); i++) {
            if (i==0) {
                results.append(to_string(input[i]));
            } else {
                results.append(",");
                results.append(to_string(input[i]));
            }
        }
        results.append(" -> ");
        for (size_t i=0; i<preds.size(); i++) {
            if (i==0) {
                results.append(to_string(preds[i]));
            } else {
                results.append(",");
                results.append(to_string(preds[i]));
            }

        }
        results.append("\n");
    }
    cout<<results<<endl;

    // Mostrar los resultados y guardarlos o volver a correr la simulacion con otro valores.
}