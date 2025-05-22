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
