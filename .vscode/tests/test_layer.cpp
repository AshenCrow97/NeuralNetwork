#include "layer.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

bool almost_equal(float a, float b, float eps = 1e-4) {
    return std::fabs(a - b) < eps;
}

bool vectors_equal(const std::vector<float>& a, const std::vector<float>& b, float eps = 1e-4) {

    assert(a.size() == b.size());

    for (size_t i = 0; i < a.size(); ++i) {
        if (!almost_equal(a[i], b[i], eps)) return false;
    }

    return true;
}

void test_forward_shape() {

    Layer layer(3, 4, "relu");

    std::vector<float> input = {1.0f, -1.0f, 0.5f};
    std::vector<float> output = layer.forward(input);

    assert(output.size() == 4);

    std::cout << "test_forward_shape passed\n";
}

void test_forward_values_not_all_zero() {

    Layer layer(2, 2, "relu");

    std::vector<float> input = {1.0f, -1.0f};
    std::vector<float> output = layer.forward(input);

    bool any_nonzero = false;

    for (float val : output) {
        if (std::fabs(val) > 1e-5f) any_nonzero = true;
    }

    assert(any_nonzero);

    std::cout << "test_forward_values_not_all_zero passed\n";
}

void test_backward_shape() {

    Layer layer(4, 3, "tanh");

    std::vector<float> input = {1, 2, 3, 4};
    std::vector<float> dE = {0.1f, 0.2f, 0.3f};

    layer.forward(input);
    std::vector<float> d_input = layer.backward(input, dE);

    assert(d_input.size() == 4);

    std::cout << "test_backward_shape passed\n";
}

void test_gradient_accumulation() {

    Layer layer(2, 2, "relu");

    std::vector<float> input = {1.0f, 2.0f};
    std::vector<float> dE = {0.1f, 0.2f};

    layer.forward(input);
    layer.backward(input, dE);

    auto dw = layer.get_dw();
    assert(dw.size() == 2 && dw[0].size() == 2);

    std::cout << "test_gradient_accumulation passed\n";
}

void test_weight_update_reduces_weights() {

    Layer layer(2, 2, "relu");

    std::vector<float> input = {1.0f, 1.0f};
    std::vector<float> dE = {0.1f, 0.1f};

    layer.forward(input);
    layer.backward(input, dE);

    auto w_before = layer.get_weights();
    layer.update(0.01f);
    auto w_after = layer.get_weights();

    for (size_t i = 0; i < w_before.size(); ++i) {
        for (size_t j = 0; j < w_before[i].size(); ++j) {
            assert(std::fabs(w_before[i][j] - w_after[i][j]) > 1e-6f);
        }
    }
    std::cout << "test_weight_update_reduces_weights passed\n";
}

void test_adam_weight_change() {

    Layer layer(2, 2, "relu");

    std::vector<float> input = {1.0f, 1.0f};
    std::vector<float> dE = {0.1f, 0.1f};

    layer.forward(input);
    layer.backward(input, dE);
    auto w_before = layer.get_weights();
    layer.adam(1, 0.01f);
    auto w_after = layer.get_weights();

    for (size_t i = 0; i < w_before.size(); ++i) {
        for (size_t j = 0; j < w_before[i].size(); ++j) {
            assert(std::fabs(w_before[i][j] - w_after[i][j]) > 1e-6f);
        }
    }

    std::cout << "test_adam_weight_change passed\n";
}

int main() {
    test_forward_shape();
    test_forward_values_not_all_zero();
    test_backward_shape();
    test_gradient_accumulation();
    test_weight_update_reduces_weights();
    test_adam_weight_change();
    std::cout << "All Layer tests passed.\n";
    return 0;
}
