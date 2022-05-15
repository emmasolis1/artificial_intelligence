#ifndef MATRIX_H
#define MATRIX_H

#pragma once
#include <vector>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>

using namespace std;

class Matrix
{

public:
    u_int32_t _cols;
    u_int32_t _rows;
    vector<float> _vals;

    Matrix();

    Matrix(u_int32_t cols, u_int32_t rows);

    Matrix applyFunction(function<float(const float &)> func);

    float &at(u_int32_t col, u_int32_t row);

    Matrix multiply(Matrix &target);

    Matrix add(Matrix &target);

    Matrix multiplyScalar(float s);

    Matrix multiplyElement(Matrix &target);

    Matrix addScalar(float s);

    Matrix negative();

    Matrix transpose();
};

#endif