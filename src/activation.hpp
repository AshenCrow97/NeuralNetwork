#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <string>
#include <vector>


class Activation {

  std::string type_;

  std::vector<float> relu(const std::vector<float> &vec) const;
  std::vector<float> d_relu (const std::vector<float> &vec) const;
  std::vector<float> leaky_relu(const std::vector<float> &vec) const;
  std::vector<float> d_leaky_relu (const std::vector<float> &vec) const;
  std::vector<float> softmax(const std::vector<float> &vec) const;
  std::vector<float> d_softmax(const std::vector<float> &x) const;

public:

  Activation();
  Activation(const std::string &activation);
  std::string get_type() const;
  std::vector<float> activate(const std::vector<float> &vec) const;
  std::vector<float> deactivate(const std::vector<float> &vec) const;

};

