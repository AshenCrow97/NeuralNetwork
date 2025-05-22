#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "../src/activation.hpp"

using namespace std;


bool almost_equal(float a, float b, float eps = 1e-5) {
    return fabs(a - b) < eps;
}

void test_relu() {

    Activation act("relu");

    vector<float> input = {-1.0f, 0.0f, 2.0f};
    vector<float> expected = {0.0f, 0.0f, 2.0f};
    vector<float> output = act.activate(input);

    for (size_t i = 0; i < output.size(); ++i) {
        assert(almost_equal(output[i], expected[i]));
    }

    vector<float> d_expected = {0.0f, 1.0f, 1.0f};
    vector<float> d_output = act.deactivate(input);

    for (size_t i = 0; i < d_output.size(); ++i) {
        assert(almost_equal(d_output[i], d_expected[i]));
    }
}

void test_leaky_relu() {

    Activation act("leaky_relu");

    vector<float> input = {-2.0f, 0.0f, 3.0f};
    vector<float> expected = {-0.02f, 0.0f, 3.0f};
    vector<float> output = act.activate(input);

    for (size_t i = 0; i < output.size(); ++i) {
        assert(almost_equal(output[i], expected[i]));
    }

    vector<float> d_expected = {0.01f, 1.0f, 1.0f};
    vector<float> d_output = act.deactivate(input);

    for (size_t i = 0; i < d_output.size(); ++i) {
        assert(almost_equal(d_output[i], d_expected[i]));
    }
}

void test_softmax() {

    Activation act("softmax");

    vector<float> input = {1.0f, 2.0f, 3.0f};
    vector<float> output = act.activate(input);

    float sum = 0.0f;
    for (float val : output) {
        sum += val;
    }

    assert(almost_equal(sum, 1.0f));  // Softmax outputs must sum to 1

    // Check expected ordering
    assert(output[2] > output[1]);
    assert(output[1] > output[0]);

    // Simplified derivative
    vector<float> d_output = act.deactivate(input);
    for (float val : d_output) {
        assert(almost_equal(val, 1.0f));
    }
}

int main() {
    test_relu();
    test_leaky_relu();
    test_softmax();
    cout << "All activation tests passed!" << endl;
    return 0;
}
