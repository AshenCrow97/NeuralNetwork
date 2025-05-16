#pragma once

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


std::vector<std::vector<float>> readCSV(const std::string &path);
std::vector<std::vector<float>> readOneHot(const std::string &path, const size_t classes);
std::vector<std::vector<float>> oneHotEncode(const std::vector<std::vector<float>> &data);
void normalize(std::vector<std::vector<float>> &data);
void saveCSV(const std::vector<int> &vec, const std::string &filepath);