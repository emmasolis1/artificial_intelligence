#include <vector>
#include <functional>

class Matrix {
  public:
    uint32_t columns;
    uint32_t rows;
    std::vector<float> values;

    Matrix();
    Matrix(uint32_t columns, uint32_t rows);
    float& at(uint32_t columns, uint32_t rows);
    Matrix multiply(Matrix matrix);
    Matrix multiplyScaler(float scaler);
    Matrix add(Matrix matrix);
    Matrix addScaler(float scaler);
    Matrix negative();
    Matrix transpose();
};