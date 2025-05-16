#include "layer.hpp"

using namespace std;


vector<vector<float>> random_init(unsigned n, unsigned m, const string &type) {

  vector<vector<float>> result (n, vector<float>(m, 0));

  mt19937 gen(1); // seed

  normal_distribution<float> distr(0, 1);

  for (unsigned i = 0; i < n; ++i) {
    for (unsigned j = 0; j < m; ++j) {
      if (type == "softmax") {
        result[i][j] = 2 * distr(gen) / (n + m);
      } else {
        result[i][j] = 2 * distr(gen) / (n);
      }
    }
  }

  return result;

}

void clip_gradient(vector<vector<float>> &mat, float min=-1.0, float max=1.0) {

  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[0].size(); ++j) {
      if (mat[i][j] < min) {
        mat[i][j] = min;
      }
      if (mat[i][j] > max) {
        mat[i][j] = max;
      }
    }
  }
}

void clip_gradient(vector<float> &vec, float min=-1.0, float max=1.0) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] < min) {
      vec[i] = min;
    }
    if (vec[i] > max) {
      vec[i] = max;
    }
  }
}



class Layer {

private:

  unsigned input_size_;
  unsigned size_;
  Activation activation_;
  vector<vector<float>> weights_;
  vector<float> biases_;
  vector<float> potentials_;
  vector<float> outputs_;
  vector<vector<float>> dw_;
  vector<float> db_;

  // Adam
  vector<vector<float>> m_dw_;
  vector<vector<float>> v_dw_;
  vector<float> m_db_;
  vector<float> v_db_;
  float beta1_ = 0.9;
  float beta2_ = 0.999;
  float eps_ = 1e-8;

public:

  Layer(unsigned input_size, unsigned size, const string &activation) {

    input_size_ = input_size;
    size_ = size;
    activation_ = Activation(activation);
    weights_ = random_init(size_, input_size_, activation);
    biases_.resize(size_); // zeroes
    potentials_.resize(size_);
    outputs_.resize(size_);
    dw_ = vector<vector<float>>(size_ ,vector<float>(input_size_, 0));
    db_.resize(size_);

    // Adam
    m_dw_ = vector<vector<float>>(size_ ,vector<float>(input_size_, 0));
    v_dw_ = vector<vector<float>>(size_ ,vector<float>(input_size_, 0));
    m_db_.resize(size_);
    v_db_.resize(size_);
  }

  vector<float> get_outputs() {

    return outputs_;

  }

  vector<float> forward(const vector<float> &inputs) {

    potentials_ = vecAddElem(matMul(weights_, inputs), biases_);
    outputs_ = activation_.activate(potentials_);

    return outputs_;

  }

  vector<float> backward(const vector<float> &inputs, const vector<float> &dE){

    vector<float> dE_deact = vecMulElem(dE, activation_.deactivate(potentials_));
    matAdd(dw_, matMul(dE_deact, inputs)); //vec * vec = mat
    db_ = vecAddElem(db_, dE_deact);

    return matMul(dE_deact, weights_); //vec * mat = vec; propagates further

  }

  void adam(int epoch, float lr=0.01) {
    // https://towardsdatascience.com/how-to-implement-an-adam-optimizer-from-scratch-76e7b217f1cc

    clip_gradient(dw_);
    clip_gradient(db_);

    for (int i = 0; i < size_; ++i) {
      for (int j = 0; j < input_size_; ++j) {
        m_dw_[i][j] = beta1_ * m_dw_[i][j] + (1 - beta1_) * dw_[i][j];
        v_dw_[i][j] = beta2_ * v_dw_[i][j] + (1 - beta2_) * dw_[i][j] * dw_[i][j];
      }
    }

    for (int i = 0; i < size_; ++i) {
      m_db_[i] = beta1_ * m_db_[i] + (1 - beta1_) * db_[i];
      v_db_[i] = beta2_ * v_db_[i] + (1 - beta2_) * db_[i] * db_[i];
    }

    for (int i = 0; i < size_; ++i) {
      for (int j = 0; j < input_size_; ++j) {
        float m_dw_corr = m_dw_[i][j] / (1 - pow(beta1_, epoch+1));
        float v_dw_corr = v_dw_[i][j] / (1 - pow(beta2_, epoch+1));
        weights_[i][j] -= lr * (m_dw_corr / (sqrt(v_dw_corr) + eps_));
      }
    }

    for (int i = 0; i < size_; ++i) {
      float m_db_corr = m_db_[i] / (1 - pow(beta1_, epoch+1));
      float v_db_corr = v_db_[i] / (1 - pow(beta2_, epoch+1));
      biases_[i] -= lr * (m_db_corr / (sqrt(v_db_corr) + eps_));
    }

    matMul(0.0, dw_);
    db_ = vecMul(0.0, db_);

  }



  void update(const float lr) {

    // gradient clipping
    clip_gradient(dw_);
    clip_gradient(db_);

    // weight update
    for (size_t i = 0; i < weights_.size(); ++i) {
      for (size_t j = 0; j < weights_[0].size(); ++j) {
        weights_[i][j] -= lr * dw_[i][j];
      }
    }

    // bias update
    for (size_t i = 0; i < biases_.size(); ++i) {
      biases_[i] -= lr * db_[i];
    }

    // momentum
    matMul(0.1, dw_);
    db_ = vecMul(0.1, db_);

  }

};

/*------------------------------------TESTS---------------------------------- */


// int main() {
//
//   // 1) init
//   //Layer l = Layer(3, 4, "relu");
//   // cout << "input size: " << l.input_size_ << endl;
//   // cout << "size: " << l.size_ << endl;
//   // cout << "activation: " << l.activation_.type_ << endl;
//   // cout << "weights:" << endl;
//   // print(l.weights_);
//   // cout << endl;
//   // cout << "biases:" << endl;
//   // print(l.biases_);
//   // cout << endl;
//   // cout << "outputs:" << endl;
//   // print(l.outputs_);
//   // cout << endl;
//   // cout << "dw:" << endl;
//   // print(l.dw_);
//   // cout << endl;
//   // cout << "db:" << endl;
//   // print(l.db_);
//   // cout << endl;
//
//
//   // 2) forward
//   //vector<float> vec {1, -2, 3};
//   //print(l.forward(vec));
//
//   // 3) backward
//   // vector<float> vec2 {1, -2, 3, 4};
//   // print(l.backward(vec, vec2));
//   // cout << "dw:" << endl;
//   // print(l.dw_);
//   // cout << endl;
//   // cout << "db:" << endl;
//   // print(l.db_);
//   // cout << endl;
//   //
//   // // 4) update
//   // l.update(0.1);
//   // cout << "weights:" << endl;
//   // print(l.weights_);
//   // cout << endl;
//   // cout << "biases:" << endl;
//   // print(l.biases_);
//   // cout << endl;
//   // cout << "outputs:" << endl;
//   // print(l.outputs_);
//   // cout << endl;
//   // cout << "dw:" << endl;
//   // print(l.dw_);
//   // cout << endl;
//   // cout << "db:" << endl;
//   // print(l.db_);
//   // cout << endl;
//
//   Layer l = Layer(2, 2, "leaky_relu");
//   cout << "INIT" << endl;
//   cout << "weights:" << endl;
//   print(l.weights_);
//   cout << endl;
//   cout << "biases:" << endl;
//   print(l.biases_);
//   cout << endl;
//
//   vector<float> vec1 {-1, 1};
//   vector<float> tar1 {0, 1};
//
//   cout << "FORWARD" << endl;
//   print(l.forward(vec1));
//   print(l.potentials_);
//
//   cout << "BACKWARD" << endl;
//   print(l.backward(vec1, vecAddElem(l.forward(vec1), vecMul(-1.0, tar1))));
//
//   cout << "dw" << endl;
//   print(l.dw_);
//   cout << endl;
//   cout << "db" << endl;
//   print(l.db_);
//   cout << endl;
//
//
//
// }
