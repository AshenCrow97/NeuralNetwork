#include "activation.hpp"

using namespace std;


Activation::Activation() {}

Activation::Activation(const string &activation) {
  type_ = activation;
}

string Activation::get_type() const {
  return type_;
}

vector<float> Activation::relu(const vector<float> &vec) const {

  vector<float> result(vec.size());

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = (vec[i] < 0) ? 0 : vec[i];
  }

  return result;

}

vector<float> Activation::d_relu (const vector<float> &vec) const {

  vector<float> result(vec.size());

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = (vec[i] < 0) ? 0 : 1;
  }

  return result;

}

vector<float> Activation::leaky_relu(const vector<float> &vec) const {

  float leak = 0.01;

  vector<float> result(vec.size());

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = (vec[i] < 0) ? leak * vec[i] : vec[i];
  }

  return result;

}

vector<float> Activation::d_leaky_relu (const vector<float> &vec) const {

  float leak = 0.01;

  vector<float> result(vec.size());

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = (vec[i] < 0) ? leak : 1;
  }

  return result;

}

vector<float> Activation::softmax(const vector<float> &vec) const {

  vector<float> result = vec;

  float max = result[0];

  for (auto x : result) {
    if (x > max) {
      max = x;
    }
  }

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = pow(M_E, result[i] - max);
  }

  float sum = 0;

  for (size_t i = 0; i < result.size(); ++i) {
    sum += result[i];
  }

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] /= sum;
  }

  return result;
}


// simplified for when softmax is immediately followed by a cross-entropy loss during backpropagation
vector<float> Activation::d_softmax(const vector<float> &x) const {

  vector<float> vec (x.size(), 1);
  return vec;

}


vector<float> Activation::activate(const vector<float> &vec) const {

  if (type_ == "relu") {
    return relu(vec);
  } else if (type_ == "softmax") {
    return softmax(vec);
  } else if (type_ == "leaky_relu") {
    return leaky_relu(vec);
  }

  return vec;

}

vector<float> Activation::deactivate(const vector<float> &vec) const {

  if (type_ == "relu") {
    return d_relu(vec);
  } else if (type_ == "softmax") {
    return d_softmax(vec);
  } else if (type_ == "leaky_relu") {
    return d_leaky_relu(vec);
  }

  return vec;

}


