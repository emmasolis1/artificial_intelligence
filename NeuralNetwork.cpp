#include "NeuralNetwork.h"

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

//SimpleNeuralNetwork();



SimpleNeuralNetwork::SimpleNeuralNetwork(vector<u_int32_t> topology, float learningRate)
{

    _topology = topology;
    _weightMatrices = {};
    _valueMatrices = {};
    _biasMatrices = {};
    _learningRate = learningRate;

    for (u_int32_t i = 0; i < topology.size() - 1; ++i)
    {
        Matrix weightMatrix(topology[i + 1], topology[i]);
        weightMatrix = weightMatrix.applyFunction(
            [](const float &f)
            {
                return (float)rand() / RAND_MAX;
            });
        _weightMatrices.push_back(weightMatrix);

        Matrix biasMatrix(topology[i + 1], 1);
        biasMatrix = biasMatrix.applyFunction(
            [](const float &f)
            {
                return (float)rand() / RAND_MAX;
            });
        _biasMatrices.push_back(biasMatrix);

        _valueMatrices.resize(topology.size());
    }
}


SimpleNeuralNetwork::SimpleNeuralNetwork(vector<vector<float>> fileWeights, vector<vector<float>> fileBias)
{
    _topology = {};
    _weightMatrices = {};
    _valueMatrices = {};
    _biasMatrices = {};
    //_learningRate = learningRate;

    
    for(uint32_t i = 0; i < fileWeights[0].size(); ++i)
    {
        _topology.push_back(fileWeights[0][i]);
    }

    for (u_int32_t i = 0; i < _topology.size() - 1; ++i)
    {
        Matrix weightMatrix(_topology[i + 1], _topology[i]);
        weightMatrix._vals = fileWeights[i + 1];
        _weightMatrices.push_back(weightMatrix);

        Matrix biasMatrix(_topology[i + 1], 1);
        biasMatrix._vals = fileBias[i + 1];
        _biasMatrices.push_back(biasMatrix);

        _valueMatrices.resize(_topology.size());
    }
}


bool SimpleNeuralNetwork::feedForward(vector<float> input)
{



    if (input.size() != _topology[0])
        return false;


    Matrix values(input.size(), 1);
    for (uint32_t i = 0; i < input.size(); i++)
    {
        values._vals[i] = input[i];
    }

    //feed forward to the next layers
    for (uint32_t i = 0; i < _weightMatrices.size(); i++)
    {
        _valueMatrices[i] = values;
        values = values.multiply(_weightMatrices[i]);
        values = values.add(_biasMatrices[i]);
        values = values.applyFunction(Sigmoid);
    }

    _valueMatrices[_weightMatrices.size()] = values;
    return true;
}

bool SimpleNeuralNetwork::backPropagate(vector<float> targetOutput)
{
    if (targetOutput.size() != _topology.back())
    {
        return false;
    }

    Matrix errors(targetOutput.size(), 1);
    errors._vals = targetOutput;

    Matrix sub = _valueMatrices.back().negative();
    errors = errors.add(sub);

    for (int i = _weightMatrices.size() - 1; i >= 0; i--)
    {
        Matrix trans = _weightMatrices[i].transpose();
        Matrix prevErrors = errors.multiply(trans);
        Matrix dOutputs = _valueMatrices[i + 1].applyFunction(
            Dsigmoid);
        Matrix gradients = errors.multiplyElement(dOutputs);
        gradients = gradients.multiplyScalar(_learningRate);
        Matrix weightGradients = _valueMatrices[i].transpose().multiply(gradients);
        _weightMatrices[i] = _weightMatrices[i].add(weightGradients);
        _biasMatrices[i] = _biasMatrices[i].add(gradients);

        errors = prevErrors;
    }

    return true;
}

vector<float> SimpleNeuralNetwork::getPrediction()
{
    return _valueMatrices.back()._vals;
}




/*

Formato de guardado en el csv

Primera fila topologia
---> c1,c2,c3,...,cn

Resto de filas
---> w1,w2,w3,...,wn

*/
bool SimpleNeuralNetwork::saveWeights(const string& filename)
{

    //Consulta si el archivo ya existe
    struct stat buf;
    if(stat(filename.c_str(), &buf) != -1)
    {
        return false;
    }

    ofstream file(filename);    


    for(uint32_t i = 0; i < _topology.size(); ++i)
    {
        file << _topology[i];

        if(i != _topology.size() - 1)
            file << ",";
    }

    for(uint32_t i = 0; i < _weightMatrices.size(); ++i)
    {
        file << "\n";
        for(uint32_t r = 0; r < _weightMatrices[i]._rows; ++r)
        {
            for(uint32_t c = 0; c < _weightMatrices[i]._cols; ++c)
            {
                file << _weightMatrices[i].at(c,r);

                if(c != _weightMatrices[i]._cols - 1
                || r != _weightMatrices[i]._rows - 1)
                    file << ",";
            }
        }
    }

    file.close();

    return true;
}


bool SimpleNeuralNetwork::saveBias(const string& filename)
{

    //Consulta si el archivo ya existe
    struct stat buf;
    if(stat(filename.c_str(), &buf) != -1)
    {
        return false;
    }

    ofstream file(filename);    


    for(uint32_t i = 0; i < _topology.size(); ++i)
    {
        file << _topology[i];

        if(i != _topology.size() - 1)
            file << ",";
    }

    for(uint32_t i = 0; i < _biasMatrices.size(); ++i)
    {
        file << "\n";
        for(uint32_t r = 0; r < _biasMatrices[i]._rows; ++r)
        {
            for(uint32_t c = 0; c < _biasMatrices[i]._cols; ++c)
            {
                file << _biasMatrices[i].at(c,r);

                if(c != _biasMatrices[i]._cols - 1
                || r != _biasMatrices[i]._rows - 1)
                    file << ",";
            }
        }
    }

    file.close();

    return true;
}
