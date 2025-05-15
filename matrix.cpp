#include <vector>

using namespace std;

// vector + vector, element-wise
vector<float> vecAddElem(const vector<float> &a, const vector<float> &b) {

  vector<float> sum (a.size());

  for (size_t i = 0; i < sum.size(); ++i) {
    sum[i] = a[i] + b[i];
  }

  return sum;
}

// matrix + matrix, element-wise
void matAdd(vector<vector<float>> &a, const vector<vector<float>> &b) {

  //cout << a.size() << "x" << a[0].size() << " " << b.size() << "x" << b[0].size() << endl;

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = 0; j < a[0].size(); ++j)
      a[i][j] += + b[i][j];
  }

}


// vector * vector, element-wise
vector<float> vecMulElem(const vector<float> &a, const vector<float> &b) {
  vector<float> product (a.size());

  for (size_t i = 0; i < product.size(); ++i) {
    product[i] = a[i] * b[i];
  }

  return product;
}


// vector * matrix = vector, (1, n) * (n,m) = (1, m)
vector<float> matMul(const vector<float> &vec, const vector<vector<float>> &mat) {
  vector<float> result(mat[0].size(), 0);

  for (size_t i = 0; i < vec.size(); ++i) {
    for (size_t j = 0; j < mat[0].size(); ++j) {
      result[j] += vec[i] * mat[i][j];
    }
  }

  return result;
}


// matrix * vector = vector, (n, m) * (m, 1) = (n, 1)
vector<float> matMul(const vector<vector<float>> &mat, const vector<float> &vec) {

  vector<float> result(mat.size(), 0);

  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < vec.size(); ++j) {
      result[i] += mat[i][j] * vec[j];
    }
  }

  return result;
}


// vector * vector = matrix, i.e. dimensions: (n, 1) * (1, m) = (n, m)
vector<vector<float>> matMul(const vector<float> &a, const vector<float> &b) {

  vector<vector<float>> result(a.size(), vector<float>(b.size(), 0));

  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = 0; j < b.size(); ++j) {
      result[i][j] = a[i] * b[j];
    }
  }

  return result;
}


// scalar * vector, element-wise
vector<float> vecMul(const float f, const vector<float> &vec) {

  vector<float> result(vec.size());

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] = f * vec[i];
  }

  return result;

}


// scalar * matrix, element-wise
// update weights
void matMul(const float f, vector<vector<float>> &mat) {

  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < mat[0].size(); ++j) {
      mat[i][j] *= f;
    }
  }

}



/*------------------------------------TESTS---------------------------------- */
//
#include <iostream>

// print vector
void print(const vector<float> &vec) {
  for (const auto &x : vec) {
    cout << x << " ";
  }
  cout << endl;
}

// print matrix
void print(const vector<vector<float>> &mat) {
  for (const auto &row : mat) {
    for (const auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}
//
//
// int main() {
//
//   float f = -1.0;
//
//   vector<float> vec1 {1,2,3};
//   vector<float> vec2 {4,5,6};
//   vector<float> vec3 {2,4,6,8};
//
//   vector<vector<float>> mat1 {{1,2,3}, {4,5,6}};
//   vector<vector<float>> mat2 {{9,8,7}, {6,5,4}};
//   vector<vector<float>> mat3 {{1,1}, {2,2}, {3,3}};
//
//
//   cout << "1) vecAddElem" << endl;
//   cout << "expected: 5 7 9" << endl;
//   print(vecAddElem(vec1, vec2));
//   cout << endl;
//
//   cout << "2) matAdd - element wise matrix" << endl;
//   cout << "expected: 10 10 10 - 10 10 10" << endl;
//   print(matAdd(mat1, mat2));
//   cout << endl;
//
//   cout << "3) vecMulElem" << endl;
//   cout << "expected: 4 10 18"  << endl;
//   print(vecMulElem(vec1, vec2));
//   cout << endl;
//
//
//   cout << "4) matMul - vector matrix" << endl;
//   cout << "expected: 14 14"  << endl;
//   print(matMul(vec1, mat3));
//   cout << endl;
//
//   cout << "5) matMul - matrix vector" << endl;
//   cout << "expected: 14 32"  << endl;
//   print(matMul(mat1, vec1));
//   cout << endl;
//
//   cout << "6) matMul vector vector = matrix" << endl;
//   cout << "expected: 2 4 6 8 - 4 8 12 16 - 6 12 18 24"  << endl;
//   print(matMul(vec1, vec3));
//   cout << endl;
//
//   cout << "7) vecMul - scalar vector" << endl;
//   cout << "expected: -1 -2 -3"  << endl;
//   print(vecMul(f, vec1));
//   cout << endl;
//
//   cout << "8) matMul - scalar matrix" << endl;
//   cout << "expected: -1 -2 -3 - -4 -5 -6"  << endl;
//   print(matMul(f, mat1));
//   cout << endl;
// }
