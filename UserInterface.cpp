#include "UserInterface.h"

using namespace std;

void UserInterface::print_welcome() {
    cout << R"(
            ░▀▀█▀▀░█▀▀░█▀▀░█░░█▀▀▄░█░█▀▀░░░▒█▄░▒█░█▀▀░█░▒█░█▀▀▄░█▀▀▄░█░░░░▒█▄░▒█░█▀▀░▀█▀░█░░░█░▄▀▀▄░█▀▀▄░█░▄
            ░░▒█░░░█▀▀░▀▀▄░█░░█▄▄█░░░▀▀▄░░░▒█▒█▒█░█▀▀░█░▒█░█▄▄▀░█▄▄█░█░░░░▒█▒█▒█░█▀▀░░█░░▀▄█▄▀░█░░█░█▄▄▀░█▀▄
            ░░▒█░░░▀▀▀░▀▀▀░▀▀░▀░░▀░░░▀▀▀░░░▒█░░▀█░▀▀▀░░▀▀▀░▀░▀▀░▀░░▀░▀▀░░░▒█░░▀█░▀▀▀░░▀░░░▀░▀░░░▀▀░░▀░▀▀░▀░▀
        )" << '\n';
}

vector<int> UserInterface::request_topology_info() {
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

vector<vector<float>> UserInterface::loadTargetInputs() {
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
    cout<<"Target outputs loaded succesfully..."<<endl;

    return my_matrix;
}