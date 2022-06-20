#include "UserInterface.h"

int main()
{
    UserInterface ui;


    vector<vector<float>> data = {};
    data = ui.loadTargetInputs();

    for(uint32_t row = 0; row < data.size(); ++row)
    {
        for(uint32_t col = 0; col < data[0].size(); ++col)
        {
            cout << data[row][col] << ", ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    vector<vector<float>> results = {};

    /*
    results = ui.dataStandarization(data);
    */

   results = ui.dataNormalization(data);

    for(uint32_t row = 0; row < results.size(); ++row)
    {
        for(uint32_t col = 0; col < results[0].size(); ++col)
        {
            cout << results[row][col] << ", ";
        }
        cout << "\n";
    }

    return 0;
}

