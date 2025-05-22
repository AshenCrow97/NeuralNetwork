#pragma once

#include <iostream>
#include <vector>


// vector + vector, element-wise
std::vector<float> vecAddElem(const std::vector<float> &a, const std::vector<float> &b);

// matrix + matrix, element-wise
void matAdd(std::vector<std::vector<float>> &a, const std::vector<std::vector<float>> &b);

// vector * vector, element-wise
std::vector<float> vecMulElem(const std::vector<float> &a, const std::vector<float> &b);

// vector * matrix = vector, (1, n) * (n,m) = (1, m)
std::vector<float> matMul(const std::vector<float> &vec, const std::vector<std::vector<float>> &mat);

// matrix * vector = vector, (n, m) * (m, 1) = (n, 1)
std::vector<float> matMul(const std::vector<std::vector<float>> &mat, const std::vector<float> &vec);

// vector * vector = matrix, (n, 1) * (1, m) = (n, m)
std::vector<std::vector<float>> matMul(const std::vector<float> &a, const std::vector<float> &b);

// scalar * vector, element-wise
std::vector<float> vecMul(const float f, const std::vector<float> &vec);

// scalar * matrix, element-wise
void matMul(const float f, std::vector<std::vector<float>> &mat);

// print vector
void print(const std::vector<float> &vec);

// print matrix
void print(const std::vector<std::vector<float>> &mat);
