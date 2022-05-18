#include "UserInterface.h"

UserInterface::UserInterface() {}

vector<vector<float>>  UserInterface::loadTargetInputs() {
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
    my_matrix.pop_back(); // The file reading add twice the last line so I am deleting it.

    return my_matrix;
}

vector<vector<float>> UserInterface::loadTargetOutputs() {
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
    my_matrix.pop_back(); // The file reading add twice the last line so I am deleting it.
    cout<<"Target outputs loaded succesfully..."<<endl;
    for (int i=0; i<my_matrix.size(); i++) {
      for (int j=0; j<my_matrix[i].size(); j++) {
        cout<<my_matrix[i][j]<<" ";
      }
      cout<<"\n";
    }

    return my_matrix;
}

uint32_t UserInterface::request_cant_epoch() {
    uint32_t epoch;
    cout<<"Enter the number of epoch to simulate: ";
    cin>>epoch;
    return epoch;
}

void UserInterface::print_welcome() {
    cout << R"(
            ░▀▀█▀▀░█▀▀░█▀▀░█░░█▀▀▄░█░█▀▀░░░▒█▄░▒█░█▀▀░█░▒█░█▀▀▄░█▀▀▄░█░░░░▒█▄░▒█░█▀▀░▀█▀░█░░░█░▄▀▀▄░█▀▀▄░█░▄
            ░░▒█░░░█▀▀░▀▀▄░█░░█▄▄█░░░▀▀▄░░░▒█▒█▒█░█▀▀░█░▒█░█▄▄▀░█▄▄█░█░░░░▒█▒█▒█░█▀▀░░█░░▀▄█▄▀░█░░█░█▄▄▀░█▀▄
            ░░▒█░░░▀▀▀░▀▀▀░▀▀░▀░░▀░░░▀▀▀░░░▒█░░▀█░▀▀▀░░▀▀▀░▀░▀▀░▀░░▀░▀▀░░░▒█░░▀█░▀▀▀░░▀░░░▀░▀░░░▀▀░░▀░▀▀░▀░▀
        )" << '\n';
}

vector<uint32_t> UserInterface::request_topology_info() {
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

void UserInterface::show_menu() {
    bool exit = false; 
    int option = 0;
    while(!exit) {
        cout<<"Welcome to the unique Neural Network...   " << R"( ╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) )" << "\n\n";
        cout<<"What do you need?\n1. LOAD a neural network.\n2. CREATE a neural network.\n3. Exit."<<endl;
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
        cout<<"Execution finish....\n"<<endl;
    }
}

float UserInterface::request_learning_rate() {
    float learning_rate = 0.0f;
    cout<<"Enter the learning rate: ";
    cin>>learning_rate;
    return learning_rate;
}

void UserInterface::create_new_neural_network() {
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


    // cout << "training started\n";
    // for(uint32_t i = 0; i < epoch; ++i)
    // {
    //     uint32_t index = rand() % 4;
    //     nn.feedForward(targetInputs[index]);
    //     nn.backPropagate(targetOutputs[index]);
    // }
    // cout << "training completed\n";

    // for(auto input : targetInputs)
    // {
    //     nn.feedForward(input);
    //     auto preds = nn.getPrediction();
    //     cout << input[0] << "," << input[1] << " -> " << preds[0] << endl;
    // }

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

    string results = toStringResults(nn, targetInputs);
    print_results(results);

    // Mostrar los resultados y guardarlos o volver a correr la simulacion con otro valores.
}


string UserInterface::toStringResults(SimpleNeuralNetwork myNeuNet,  vector<vector<float>> myTargetInputs) {
    string results = "";
    for(auto input : myTargetInputs)
    {
        myNeuNet.feedForward(input);
        auto preds = myNeuNet.getPrediction();
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

    return results;
}

void UserInterface::print_results(string my_results) { cout<<my_results<<endl; }
