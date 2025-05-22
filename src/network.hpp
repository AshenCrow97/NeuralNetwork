#pragma once

#include <cmath>
#include <iostream>
#include <vector>

#include "layer.hpp"


int argmax(const std::vector<float> &vec);
float accuracy(const std::vector<int> &pred, const std::vector<std::vector<float>> &target);
float cross_entropy(const std::vector<std::vector<float>> &pred, const std::vector<std::vector<float>> &target);


class Network {

  std::vector<float> get_outputs_();
  std::vector<float> forward_(std::vector<float> x);
  void backward_(const std::vector<float> &x, const std::vector<float> &y);
  void update_(const int epoch, const float lr);

public:

  std::vector<Layer> layers_;

  Network() {

    // XOR architecture
    // layers_.push_back(Layer(2, 4, "relu"));
    // layers_.push_back(Layer(4, 2, "softmax"));

    // MNIST architecture
    //layers_.push_back(Layer(784, 64, "leaky_relu"));
    layers_.push_back(Layer(784, 1024, "leaky_relu"));
    layers_.push_back(Layer(1024, 10, "softmax"));

  }


  std::vector<std::vector<float>> predict_proba(std::vector<std::vector<float>> &X);

  std::vector<int> predict(std::vector<std::vector<float>> &X);

  void fit(
    std::vector<std::vector<float>> &X,
    std::vector<std::vector<float>> &y,
    std::vector<std::vector<float>> &X_val,
    std::vector<std::vector<float>> &y_val,
    int epochs=12,
    int batch_size=256,
    float lr=1,
    float lr_decay=true,
    bool verbose=true);


};
