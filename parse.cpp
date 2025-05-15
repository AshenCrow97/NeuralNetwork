#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<float>> readCSV(string path) {

  vector<vector<float>> data;

  ifstream file (path);
  string line;

  while (getline(file, line)) {

    istringstream s (line);
    string value;
    vector<float> row;

    while (getline(s, value, ',')) {
      row.push_back(stof(value));
    }

    data.push_back(row);

  }

  file.close();
  return data;

}


vector<vector<float>> readOneHot(string path, unsigned classes) {

  vector<vector<float>> onehot;

  ifstream file (path);
  string value;

  while (getline(file, value)) {
    vector<float> row;
    row.resize(classes, 0);
    row[stoi(value)] = 1;
    onehot.push_back(row);
  }

  file.close();
  return onehot;
}


vector<vector<float>> oneHotEncode(const vector<vector<float>> &data) {

  int classes = 0;

  for (size_t i = 0; i < data.size(); ++i) {
    if (static_cast<int>(data[i][0]) > classes) {
      classes = static_cast<int>(data[i][0]);
    }
  }

  ++classes;

  cout << "classes: " << classes << endl;

  vector<vector<float>> onehot (data.size(), vector<float>(classes, 0));

  for (size_t i = 0; i < data.size(); ++i) {
    onehot[i][static_cast<int>(data[i][0])] = 1;
  }

  cout << "onehot done" << endl;
  return onehot;

}


void normalize(vector<vector<float>> &data) {

  double rows = data.size();
  double cols = data[0].size();
  double size = rows * cols;
  double sum = 0;

  for (auto &row : data) {
    for (float &value : row) {
      sum += value;
    }
  }

  double mean = sum / size;
  double std = 0;

  for (auto &row : data) {
    for (float &value : row) {
      std += pow(value - mean, 2);
    }
  }

  std = sqrt(std / size);

  for (auto &row : data) {
    for (float &value : row) {
      value = (value - mean) / std;
    }
  }

}

//TODO prediction to file

void saveCSV(const vector<int> &vec, const string &filepath) {

  std::ofstream output_file(filepath);
  for (const auto &x : vec) output_file << x << "\n";

}




/*------------------------------------TESTS---------------------------------- */

// print matrix
// void print(const vector<vector<float>> &mat) {
//
//   int limit_x = 0;
//   int limit_y = 0;
//
//   for (const auto &row : mat) {
//     for (const auto &val : row) {
//       ++limit_x;
//       cout << val << " ";
//       if (limit_x > 20) {
//         cout << "...";
//         limit_x = 0;
//         break;
//       }
//     }
//     limit_x = 0;
//     ++limit_y;
//     cout << endl;
//     if (limit_y > 20) {
//       cout << "..." << endl;
//       break;
//     }
//   }
//   cout << endl;
// }
//
// int main() {
//
//   // 1) readCSV
//   string path_xor = "../data/xor_vectors.csv";
//   string path_fmnist = "../data/fashion_mnist_train_vectors.csv";
//   string path_fmnist_test = "../data/fashion_mnist_test_vectors.csv";
//   string path_xor_labels = "../data/xor_labels.csv";
//   string path_fmnist_labels = "../data/fashion_mnist_train_labels.csv";
//   string path_fmnist_test_labels = "../data/fashion_mnist_test_labels.csv";
//
//   vector<vector<float>> data = readCSV(path_xor);
//   print(data);
//
//   // 2) oneHotEncode
//   //vector<vector<float>> ohe = oneHotEncode(data);
//   //print(ohe);
//
//   // 3) normalize
//   normalize(data);
//   print(data);
//
//
//   // 4) train_val_split
//   vector<vector<float>> train (2);
//   copy_n(data.begin(), 2, train.begin());
//   print(train);
//
//   vector<vector<float>> val (2);
//   copy_n(data.begin() + 2, 2, val.begin());
//   print(val);
//
// }
