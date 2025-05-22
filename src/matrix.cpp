#include "matrix.hpp"

using namespace std;


vector<float> vecAddElem(const vector<float> &a, const vector<float> &b) {

  vector<float> sum (a.size());

  for (size_t i = 0; i < sum.size(); ++i) {
    sum[i] = a[i] + b[i];
  }

  return sum;
}

void matAdd(vector<vector<float>> &a, const vector<vector<float>> &b) {

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = 0; j < a[0].size(); ++j)
      a[i][j] += + b[i][j];
  }

}


vector<float> vecMulElem(const vector<float> &a, const vector<float> &b) {
  vector<float> product (a.size());

  for (size_t i = 0; i < product.size(); ++i) {
    product[i] = a[i] * b[i];
  }

  return product;
}


vector<float> matMul(const vector<float> &vec, const vector<vector<float>> &mat) {
  vector<float> result(mat[0].size(), 0);

  for (size_t i = 0; i < vec.size(); ++i) {
    for (size_t j = 0; j < mat[0].size(); ++j) {
      result[j] += vec[i] * mat[i][j];
    }
  }

  return result;
}


vector<float> matMul(const vector<vector<float>> &mat, const vector<float> &vec) {

  vector<float> result(mat.size(), 0);

  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < vec.size(); ++j) {
      result[i] += mat[i][j] * vec[j];
    }
  }

  return result;
}


vector<vector<float>> matMul(const vector<float> &a, const vector<float> &b) {

  vector<vector<float>> result(a.size(), vector<float>(b.size(), 0));

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = 0; j < b.size(); ++j) {
      result[i][j] = a[i] * b[j];
    }
  }

  return result;
}


vector<float> vecMul(const float f, const vector<float> &vec) {

  vector<float> result(vec.size());

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = f * vec[i];
  }

  return result;

}


void matMul(const float f, vector<vector<float>> &mat) {

  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < mat[0].size(); ++j) {
      mat[i][j] *= f;
    }
  }

}


void print(const vector<float> &vec) {
  for (const auto &x : vec) {
    cout << x << " ";
  }
  cout << endl;
}


void print(const vector<vector<float>> &mat) {
  for (const auto &row : mat) {
    for (const auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

