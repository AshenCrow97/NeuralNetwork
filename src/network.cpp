#include "network.hpp"

using namespace std;


int argmax(const vector<float> &vec) {

  int arg = 0;
  float max = vec[0];

  for (size_t i = 0; i < vec.size(); ++i) {
    if (vec[i] > max) {
      arg = i;
    }
  }

  return arg;

}


float accuracy(const vector<int> &pred, const vector<vector<float>> &target) {

  float correct = 0;

  for (size_t i = 0; i < pred.size(); ++i) {
    if (static_cast<float>(pred[i]) == argmax(target[i])) {
      ++correct;
    }
  }

  return correct / pred.size();

}


float cross_entropy(const vector<vector<float>> &pred, const vector<vector<float>> &target) {

  float loss = 0.0;

  for (int i = 0; i < pred.size(); ++i) {
    for (int j = 0; j < target[0].size(); ++j) {
      if (target[i][j]) { // because it's one hot encoded
        loss += log(pred[i][j] + 1e-10);
      }
    }
  }

  return -loss;

}


class Network {

  vector<float> get_outputs_() {
    return layers_.back().get_outputs();
  }

  vector<float> forward_(vector<float> x) {
    for (auto &layer : layers_) {
      x = layer.forward(x);
    }
    return get_outputs_();
  }

  void backward_(const vector<float> &x, const vector<float> &y) {

    // softmax + cross entropy => loss = prediction - target
    vector<float> dE = vecAddElem(get_outputs_(), vecMul(-1.0, y));

    for (int i = layers_.size() - 1; i >= 0; --i) {
      if (i == 0) { //first layer
        dE = layers_[i].backward(x, dE);
      } else {
        dE = layers_[i].backward(layers_[i-1].get_outputs(), dE);
      }

    }

  }

  void update_(const int epoch, const float lr) {
    for (auto &layer : layers_) layer.adam(epoch, lr);
    //for (auto &layer : layers_) layer.update(lr);
  }

public:
  vector<Layer> layers_;

  Network() {

    // XOR architecture
    // layers_.push_back(Layer(2, 4, "relu"));
    // layers_.push_back(Layer(4, 2, "softmax"));

    // MNIST architecture
    //layers_.push_back(Layer(784, 64, "leaky_relu"));
    layers_.push_back(Layer(784, 1024, "leaky_relu"));
    layers_.push_back(Layer(1024, 10, "softmax"));

  }


  vector<vector<float>> predict_proba(vector<vector<float>> &X) {

    vector<vector<float>> preds(X.size());

    for (size_t i = 0; i < X.size(); ++i) {
      preds[i] = forward_(X[i]);
    }

    return preds;

  }

  vector<int> predict(vector<vector<float>> &X) {

    vector<int> preds(X.size());

    for (size_t i = 0; i < X.size(); ++i) {
      preds[i] = argmax(forward_(X[i]));
    }

    return preds;

  }

  void fit(
    vector<vector<float>> &X,
    vector<vector<float>> &y,
    vector<vector<float>> &X_val,
    vector<vector<float>> &y_val,
    int epochs=12,
    int batch_size=256,
    float lr=1,
    float lr_decay=true,
    bool verbose=true) {

    for (int epoch = 0; epoch < epochs; ++epoch) {
      for (int i = 0; i < X.size(); ++i) {
        forward_(X[i]);
        backward_(X[i], y[i]);
        if (i % batch_size == 0) {
          if (lr_decay) {
            update_(epoch, lr / (1 + 1.0 * epoch));
            //return;
          } else {
            update_(epoch, lr);
            //return;
          }
        }
        // if (i == 32) {
        //   return;
        // }
      }

      // val_loss ...
      if (verbose) {
        cout << epoch << " val_loss: " << cross_entropy(predict_proba(X_val), y_val);
        cout << " val_acc: " << accuracy(predict(X_val), y_val) << endl;
      }

    }

  }



};

