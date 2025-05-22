#include "network.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

void test_argmax() {
    vector<float> v = {0.1, 0.3, 0.2, 0.9, 0.4};
    assert(argmax(v) == 3);
}

void test_accuracy() {
    vector<int> preds = {1, 0, 2};
    vector<vector<float>> targets = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
    };
    assert(fabs(accuracy(preds, targets) - 1.0) < 1e-6);
}

void test_cross_entropy() {
    vector<vector<float>> preds = {
        {0.1, 0.6, 0.3},
        {0.2, 0.2, 0.6},
    };
    vector<vector<float>> targets = {
        {0, 1, 0},
        {0, 0, 1},
    };
    float expected = -log(0.6) - log(0.6);
    assert(fabs(cross_entropy(preds, targets) - expected) < 1e-5);
}

void test_network_predict() {
    Network net;
    vector<vector<float>> X(1, vector<float>(784, 0.01));
    vector<int> result = net.predict(X);
    assert(result.size() == 1);
    assert(result[0] >= 0 && result[0] < 10); // valid softmax output class
}

void test_network_predict_proba() {
    Network net;
    vector<vector<float>> X(1, vector<float>(784, 0.01));
    auto probs = net.predict_proba(X);
    assert(probs.size() == 1);
    assert(probs[0].size() == 10);
    float sum = 0;
    for (float p : probs[0]) sum += p;
    assert(fabs(sum - 1.0) < 1e-3); // softmax output should sum to 1
}

int main() {
    test_argmax();
    test_accuracy();
    test_cross_entropy();
    test_network_predict();
    test_network_predict_proba();
    cout << "All network tests passed.\n";
    return 0;
}
