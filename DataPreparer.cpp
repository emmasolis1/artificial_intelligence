#include "DataPreparer.h"


DataPreparer::DataPreparer(){
    
}
DataPreparer::DataPreparer(std::string dataset_path){
    ifstream fin;
    fin.open(dataset_path);
    string line;
    vector<float> dataset_values;
    getline(fin, line);

    stringstream ss(line);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        dataset_values.push_back(stof(substr));
    }
    fin.close();

    int numColumns = dataset_values.size();
    // Initialize with 0
    for (int i =0; i<numColumns; i++) {
        minValues.push_back(0);
        maxValues.push_back(0);
    }

}

void DataPreparer::calculateMaxAndMinValues(std::string dataset_path) {
    // For file Reading
    ifstream fin;
    fin.open(dataset_path);
    string line;

    // Read file line by line.
    while (fin) {
        // Read a Line from File
        getline(fin, line);
        vector<float> dataset_values;

        stringstream ss(line);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            dataset_values.push_back(stof(substr));
        }
        // Add the new vector<float> to the matrix (main vector).
        //auto it = minValues.begin();
        int i=0;
        for(auto it = std::begin(this->minValues); it != std::end(this->minValues); ++it,i++) {
            if(this->minValues[i] > dataset_values[i]){
                this->minValues.insert(it, dataset_values[i]);
            }
            // Assign max values
            if(this->maxValues[i] < dataset_values[i]){
                this->maxValues.insert(it, dataset_values[i]);
            }
        }
        std::cout<<dataset_values.size();
    
    }
    // Close the file
    fin.close();
    for(int i=0; i< this->minValues.size(); i++) {
        std::cout<<"MinValues"<<std::endl;
        std::cout<< std::to_string(minValues[i]);
    }
    std::cout<<std::endl;
    for(int i=0; i< this->minValues.size(); i++) {
        std::cout<<"MaxValues"<< std::to_string(maxValues[i]);
    }
}
float DataPreparer::normalizeInput(float input, int column) {
    return ((input - this->minValues[column]) / (this->maxValues[column] - this->minValues[column]));
}