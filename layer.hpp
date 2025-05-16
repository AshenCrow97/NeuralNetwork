#pragma once

#include <random>
#include <string>
#include <vector>

#include "activation.hpp"
#include "matrix.hpp"


std::vector<std::vector<float>> random_init(unsigned n, unsigned m, const std::string &type);
void clip_gradient(std::vector<std::vector<float>> &mat, float min=-1.0, float max=1.0);
void clip_gradient(std::vector<float> &vec, float min=-1.0, float max=1.0);


class Layer {

private:

  unsigned input_size_;
  unsigned size_;
  Activation activation_;
  std::vector<std::vector<float>> weights_;
  std::vector<float> biases_;
  std::vector<float> potentials_;
  std::vector<float> outputs_;
  std::vector<std::vector<float>> dw_;
  std::vector<float> db_;

  // Adam
  std::vector<std::vector<float>> m_dw_;
  std::vector<std::vector<float>> v_dw_;
  std::vector<float> m_db_;
  std::vector<float> v_db_;
  float beta1_ = 0.9;
  float beta2_ = 0.999;
  float eps_ = 1e-8;

public:

  Layer(unsigned input_size, unsigned size, const std::string &activation);
  std::vector<float> get_outputs();
  std::vector<float> forward(const std::vector<float> &inputs);
  std::vector<float> backward(const std::vector<float> &inputs, const std::vector<float> &dE);
  void adam(int epoch, float lr=0.01);
  void update(const float lr);

};
