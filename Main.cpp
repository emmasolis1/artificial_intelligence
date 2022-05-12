#include <iostream>
#include "Matrix.hpp"

int main(int argc, char **argv) {
  // Testing the Neural Network.
  Matrix m(3,3);

  for(int i=0; i<3;i++){
      for(int j=0; j<3;j++){
          m.at(i,j) = i;
          std::cout<< m.at(i,j);
      }
      std::cout<<std::endl;
  }

  return 0;
}