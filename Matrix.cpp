#include "Matrix.hpp"
#include <vector>


Matrix::Matrix():columns(0),rows(0),values({}) {

}

Matrix::Matrix(uint32_t columns, uint32_t rows){
  this->columns=columns;
  this->rows = rows;
}

float& Matrix::at(uint32_t my_column, uint32_t my_row){
  return this->values[my_row * this->columns + my_column];
}


Matrix multiply(Matrix matrix);
Matrix Matrix::multiplyScaler(float scaler) {
  Matrix output(this->columns, this->rows);
  for (uint32_t y=0; y < output.rows; y++) {
    for (uint32_t x=0; x < output.columns; x++) {
      output.at(x, y) = at(x, y) * scaler;
    }
  }
  return output;
}
Matrix add(Matrix matrix);
Matrix addScaler(float scaler);
Matrix negative();
Matrix transpose();
