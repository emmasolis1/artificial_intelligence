#include "UserInterface.h"

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