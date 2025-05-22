#include "parse.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void test_readCSV() {
  ofstream file("test.csv");
  file << "1.0,2.0,3.0\n4.0,5.0,6.0\n";
  file.close();

  vector<vector<float>> data = readCSV("test.csv");
  assert(data.size() == 2);
  assert(data[0].size() == 3);
  assert(data[0][0] == 1.0f);
  assert(data[1][2] == 6.0f);
}

void test_readOneHot() {
  ofstream file("labels.txt");
  file << "1\n0\n2\n";
  file.close();

  vector<vector<float>> onehot = readOneHot("labels.txt", 3);
  assert(onehot.size() == 3);
  assert(onehot[0][1] == 1.0f);
  assert(onehot[1][0] == 1.0f);
  assert(onehot[2][2] == 1.0f);
}

void test_oneHotEncode() {
  vector<vector<float>> data = {{2}, {0}, {1}};
  vector<vector<float>> encoded = oneHotEncode(data);
  assert(encoded.size() == 3);
  assert(encoded[0][2] == 1.0f);
  assert(encoded[1][0] == 1.0f);
  assert(encoded[2][1] == 1.0f);
}

void test_normalize() {
  vector<vector<float>> data = {{1, 2}, {3, 4}};
  normalize(data);
  float mean = 0, std = 0;
  for (auto &row : data) for (float v : row) mean += v;
  mean /= 4;
  for (auto &row : data) for (float v : row) std += (v - mean) * (v - mean);
  std = sqrt(std / 4);
  assert(abs(mean) < 1e-5);
  assert(abs(std - 1) < 1e-5);
}

void test_saveCSV() {
  vector<int> data = {5, 10, 15};
  saveCSV(data, "output.csv");
  ifstream file("output.csv");
  string line;
  getline(file, line);
  assert(line == "5");
  getline(file, line);
  assert(line == "10");
  getline(file, line);
  assert(line == "15");
  file.close();
}

int main() {
  test_readCSV();
  test_readOneHot();
  test_oneHotEncode();
  test_normalize();
  test_saveCSV();
  cout << "All parse tests passed!" << endl;
  return 0;
}
