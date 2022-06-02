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

    return my_matrix;
}

vector<vector<float>>  UserInterface::loadSavedWeights() {
    vector<vector<float>> my_matrix = {};
    string dataset_path;
    cout<<"Enter saved WEIGHTS path: ";
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

vector<vector<float>>  UserInterface::loadSavedBias() {
    vector<vector<float>> my_matrix = {};
    string dataset_path;
    cout<<"Enter saved BIAS path: ";
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
            load_neural_network();
            break;
        
        case 2:
            create_new_neural_network();
            //request_save_weights();
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
    request_data_standardization_or_normalization(targetInputs);
    vector<vector<float>> targetOutputs = loadTargetOutputs();
    request_data_standardization_or_normalization(targetOutputs);
    data_separation(targetInputs, targetOutputs);
    uint32_t epoch = request_cant_epoch();

    // Show summary of neural info.
    
    cout << "training started(With 70 percent data)\n";
    int target_input_size = input_70.size();
    for(uint32_t i = 0; i < epoch; ++i)
    {
        uint32_t index = rand() % target_input_size;
        nn.feedForward(input_70[index]);
        nn.backPropagate(output_70[index]);
    }
    cout << "training completed\n\n";

    string results = {};
    
    cout << "20 percent data to test network's performance: \n\n";
    results = toStringResults(nn, input_20);
    print_results(results);
    cout << "\n\n";

    results = {};

    cout << "10 percent data to test 'artificial' inputs: \n\n";
    results = toStringResults(nn, input_10);
    print_results(results);
    cout << "\n\n";
    

    /*
    for(auto input : targetInputs)
    {
        nn.feedForward(input);
        auto preds = nn.getPrediction();
        cout << input[0] << "," << input[1] << " -> " << preds[0] << endl;
    }
    */


    //Save the weights and bias of the current neuralNetwork
    request_save_neural_network(nn);


    // Mostrar los resultados y guardarlos o volver a correr la simulacion con otro valores.
}


void UserInterface::load_neural_network()
{
    // Request main info.
    vector<vector<float>> savedWeights = loadSavedWeights();
    vector<vector<float>> savedBias = loadSavedBias();
    SimpleNeuralNetwork nn(savedWeights, savedBias);
    vector<vector<float>> targetInputs = loadTargetInputs();


    string results = toStringResults(nn, targetInputs);
    print_results(results);
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


void UserInterface::request_save_neural_network(SimpleNeuralNetwork& nn)
{
    uint32_t selection;
    string weights_name;
    string bias_name;

    cout<<"Do you want to save the current network?   ";
    cout<<"1 -> yes, other -> no" << endl;
    cout << "input: ";
    cin>>selection;
    
    if(selection == 1)
    {
        cout<<"Enter weights FILE name: ";
        cin>>weights_name;
        nn.saveWeights(weights_name);

        cout<<"Enter bias FILE name: ";
        cin>>bias_name;
        nn.saveBias(bias_name);
    }
}

void UserInterface::request_data_standardization_or_normalization(vector<vector<float>>& data)
{
    int selection = 0;

    vector<vector<float>> results = {};

    cout<<"Want to standardize or normalize the current data?   ";
    cout<<"1 -> standardize, 2 -> normalize, other -> no" << endl;
    cout << "input: ";
    cin>>selection;

    
    if(selection == 1)
    {
        results = dataStandardization(data);
        data = results;
    }

    if(selection == 2)
    {
        results = dataNormalization(data);
        data = results;
    }
    
    /*
    for(uint32_t row = 0; row < 10; ++row)
    {
        for(uint32_t col = 0; col < data[0].size(); ++col)
        {
            cout << data[row][col] << ", ";
        }
        cout << "\n";
    }
    */
    
}

vector<vector<float>> UserInterface::dataStandardization(vector<vector<float>>& data)
{
    vector<vector<float>> results = {};
    results.resize(data.size());
    int rowSize = data[0].size(); 

    for(int i = 0; i < results.size(); ++i)
    {
        results[i].resize(rowSize);
    }


    vector<float> colMean(results[0].size(),0);
    vector<float> colStd(results[0].size(),0);


    for(uint32_t col = 0; col < data[0].size(); ++col)
    {
        for(uint32_t row = 0; row < data.size(); ++row)
        {
            colMean[col] += data[row][col];
        }
        colMean[col] = colMean[col]/rowSize;
    }

    for(uint32_t col = 0; col < data[0].size(); ++col)
    {
        for(uint32_t row = 0; row < data.size(); ++row)
        {
            colStd[col] += pow(data[row][col] - colMean[col],2);
        }
        colStd[col] = sqrt(colStd[col]/rowSize);
    }

    for(uint32_t row = 0; row < data.size(); ++row)
    {
        for(uint32_t col = 0; col < data[0].size(); ++col)
        {
            results[row][col] = (data[row][col] - colMean[col])/colStd[col];
        }
    }

    return results;
}

vector<vector<float>> UserInterface::dataNormalization(vector<vector<float>>& data)
{
    vector<vector<float>> results = {};
    results.resize(data.size());
    int rowSize = data[0].size(); 

    for(int i = 0; i < results.size(); ++i)
    {
        results[i].resize(rowSize);
    }


    vector<float> colMin(results[0].size(),MAXFLOAT);
    vector<float> colMax(results[0].size(),0);
    vector<float> ranges(results[0].size(),0);

    for(uint32_t col = 0; col < data[0].size(); ++col)
    {
        for(uint32_t row = 0; row < data.size(); ++row)
        {
            if(colMin[col] > data[row][col]){colMin[col] = data[row][col];}
            if(colMax[col] < data[row][col]){colMax[col] = data[row][col];}
        }
    }

    for(uint32_t i = 0; i < ranges.size(); ++i)
    {
        ranges[i] = colMax[i] - colMin[i];
    }


    for(uint32_t row = 0; row < data.size(); ++row)
    {
        for(uint32_t col = 0; col < data[0].size(); ++col)
        {
            results[row][col] = (data[row][col] - colMin[col])/ranges[col];
        }
    }

    return results;
}


void UserInterface::data_separation(vector<vector<float>>& data_in, vector<vector<float>>& data_out)
{
    int val_70 = data_in.size() * 0.70;
    int val_20 = data_in.size() * 0.20;
    int val_10 = data_in.size() - val_70 - val_20;

    input_70.clear();
    output_70.clear();

    input_20.clear();
    output_20.clear();

    input_10.clear();
    output_10.clear();


    for(int i = 0; i < data_in.size(); ++i)
    {
        if(i < val_70)
        {
            input_70.push_back(data_in[i]);
            output_70.push_back(data_out[i]);
        }else if (i >= val_70 && i < (val_70 + val_20))
        {
            input_20.push_back(data_in[i]);
            output_20.push_back(data_out[i]);           
        }else
        {
            input_10.push_back(data_in[i]);
            output_10.push_back(data_out[i]);
        }      
    }
}