#include "activation.hpp"

using namespace std;


class Activation {

  string type_;

  vector<float> relu(const vector<float> &vec) const {

    vector<float> result(vec.size());

    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = (vec[i] < 0) ? 0 : vec[i];
    }

    return result;

  }

  vector<float> d_relu (const vector<float> &vec) const {

    vector<float> result(vec.size());

    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = (vec[i] < 0) ? 0 : 1;
    }

    return result;

  }

  vector<float> leaky_relu(const vector<float> &vec) const {

    float leak = 0.01;

    vector<float> result(vec.size());

    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = (vec[i] < 0) ? leak * vec[i] : vec[i];
    }

    return result;

  }

  vector<float> d_leaky_relu (const vector<float> &vec) const {

    float leak = 0.01;

    vector<float> result(vec.size());

    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = (vec[i] < 0) ? leak : 1;
    }

    return result;

  }

  vector<float> softmax(const vector<float> &vec) const {

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

  vector<float> d_softmax(const vector<float> &x) const {
    vector<float> vec (x.size(), 1);
    return vec;
  }

public:

  Activation() {}

  Activation(const string &activation) {
    type_ = activation;
  }

  string get_type() {
    return type_;
  }

  vector<float> activate(const vector<float> &vec) const {

    if (type_ == "relu") {
      return relu(vec);
    } else if (type_ == "softmax") {
      return softmax(vec);
    } else if (type_ == "leaky_relu") {
      return leaky_relu(vec);
    }

    return vec;

  }

  vector<float> deactivate(const vector<float> &vec) const {

    if (type_ == "relu") {
      return d_relu(vec);
    } else if (type_ == "softmax") {
      return d_softmax(vec);
    } else if (type_ == "leaky_relu") {
      return d_leaky_relu(vec);
    }

    return vec;

  }

};

/*------------------------------------TESTS---------------------------------- */
//
//
// // print vector
// void print(const vector<float> &vec) {
//   for (const auto &x : vec) {
//     cout << x << " ";
//   }
//   cout << endl;
// }
//
// int main() {
//
//   cout << "1) init" << endl;
//   Activation a = Activation();
//   cout << a.get_type() << endl;
//   Activation b = Activation("relu");
//   cout << b.get_type() << endl;
//   Activation c = Activation("softmax");
//   cout << c.get_type() << endl;
//   cout << endl;
//
//
//   cout << "2) relu" << endl;
//   Activation r = Activation("relu");
//   vector<float> vec {1.0, -0.5, 2.0, -8.4, -6.0, 2.0};
//   cout << "expected: 1 0 2 0 0 2" << endl;
//   print(r.activate(vec));
//   cout << endl;
//
//
//   cout << "3) d_relu" << endl;
//   Activation dr = Activation("relu");
//   vector<float> dvec {1.0, -0.5, 2.0, -8.4, -6.0, 2.0};
//   cout << "expected: 1 0 1 0 0 1" << endl;
//   print(dr.deactivate(dvec));
//   cout << endl;
//
//
//   cout << "4) softmax" << endl;
//   Activation s = Activation("softmax");
//   vector<float> soft {1000, 2000, 3000};
//   cout << "expected: 0 0 1" << endl;
//   print(s.activate(soft));
//   vector<float> soft2 {0.1, -0.2, 0.5, 0.2};
//   cout << "expected: 0.23053087 0.17078147 0.34391165 0.25477601" << endl;
//   print(s.activate(soft2));
//   cout << endl;
//
//
//   cout << "5) d_softmax" << endl;
//   Activation ds = Activation("softmax");
//   //vector<float> dvec {1.0, -0.5, 2.0, -8.4, -6.0, 2.0};
//   cout << "expected: 1 -0.5 2 -8.4 -6 2" << endl;
//   print(ds.deactivate(dvec));
//   cout << endl;
//
// }
