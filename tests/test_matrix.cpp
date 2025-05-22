#include "matrix.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

bool almost_equal(float a, float b, float eps = 1e-5) {
    return std::fabs(a - b) < eps;
}

bool vectors_equal(const std::vector<float>& a, const std::vector<float>& b, float eps = 1e-5) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i)
        if (!almost_equal(a[i], b[i], eps)) return false;
    return true;
}

void test_vecAddElem() {
    std::vector<float> a = {1, 2, 3};
    std::vector<float> b = {4, 5, 6};
    std::vector<float> expected = {5, 7, 9};
    assert(vectors_equal(vecAddElem(a, b), expected));
    std::cout << "test_vecAddElem passed\n";
}

void test_vecMulElem() {
    std::vector<float> a = {1, 2, 3};
    std::vector<float> b = {4, 5, 6};
    std::vector<float> expected = {4, 10, 18};
    assert(vectors_equal(vecMulElem(a, b), expected));
    std::cout << "test_vecMulElem passed\n";
}

void test_matMul_vec_matrix() {
    std::vector<float> vec = {1, 2};
    std::vector<std::vector<float>> mat = {{3, 4}, {5, 6}};
    std::vector<float> expected = {13, 16};
    assert(vectors_equal(matMul(vec, mat), expected));
    std::cout << "test_matMul_vec_matrix passed\n";
}

void test_matMul_matrix_vec() {
    std::vector<std::vector<float>> mat = {{3, 4}, {5, 6}};
    std::vector<float> vec = {1, 2};
    std::vector<float> expected = {11, 17};
    assert(vectors_equal(matMul(mat, vec), expected));
    std::cout << "test_matMul_matrix_vec passed\n";
}

void test_matMul_outer_product() {
    std::vector<float> a = {1, 2};
    std::vector<float> b = {3, 4};
    std::vector<std::vector<float>> expected = {{3, 4}, {6, 8}};
    assert(matMul(a, b) == expected);
    std::cout << "test_matMul_outer_product passed\n";
}

void test_vecMul_scalar() {
    std::vector<float> vec = {1, 2, 3};
    float scalar = 2;
    std::vector<float> expected = {2, 4, 6};
    assert(vectors_equal(vecMul(scalar, vec), expected));
    std::cout << "test_vecMul_scalar passed\n";
}

void test_matMul_scalar() {
    std::vector<std::vector<float>> mat = {{1, 2}, {3, 4}};
    matMul(2.0f, mat);
    std::vector<std::vector<float>> expected = {{2, 4}, {6, 8}};
    assert(mat == expected);
    std::cout << "test_matMul_scalar passed\n";
}

void test_matAdd() {
    std::vector<std::vector<float>> a = {{1, 2}, {3, 4}};
    std::vector<std::vector<float>> b = {{5, 6}, {7, 8}};
    matAdd(a, b);
    std::vector<std::vector<float>> expected = {{6, 8}, {10, 12}};
    assert(a == expected);
    std::cout << "test_matAdd passed\n";
}

int main() {
    test_vecAddElem();
    test_vecMulElem();
    test_matMul_vec_matrix();
    test_matMul_matrix_vec();
    test_matMul_outer_product();
    test_vecMul_scalar();
    test_matMul_scalar();
    test_matAdd();
    std::cout << "All matrix tests passed.\n";
    return 0;
}
