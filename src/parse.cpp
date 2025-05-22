#include "parse.hpp"

using namespace std;


vector<vector<float>> readCSV(const string &path) {

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


vector<vector<float>> readOneHot(const string &path, const size_t classes) {

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


void saveCSV(const vector<int> &vec, const string &filepath) {

  std::ofstream output_file(filepath);
  for (const auto &x : vec) output_file << x << "\n";

}
