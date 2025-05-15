#include <string>

#include "network.cpp"
#include "parse.cpp"

using namespace std;


/*
TODO
  - gradient momentum
  - val loss
  - variable learning rate
  - leaky relu
  - regularization
  - fixed leaky relu error
  - check the maths
  - init distribution of weights
- dropout
- optimizers - Adam, RMSProp, Nesterov momentum, ...
- (float -> double)

- predictions to file
- run it on AISA
- all formalities and turn it in
  - read discussion forum, instructions, ...
- matrix operations without copying, const and non const versions
- hyperparameters


*/


int main() {

  cout << "loading data" << endl;

  // string path_xor = "../data/xor_vectors.csv";
  // string path_xor_labels = "../data/xor_labels.csv";

  // vector<vector<float>> X_xor = readCSV(path_xor);
  // vector<vector<float>> y_xor = readOneHot(path_xor_labels, 2);

  string path_fmnist = "../data/fashion_mnist_train_vectors.csv";
  string path_fmnist_labels = "../data/fashion_mnist_train_labels.csv";

  vector<vector<float>> X_mnist = readCSV(path_fmnist);
  normalize(X_mnist);
  vector<vector<float>> y_mnist = readOneHot(path_fmnist_labels, 10);


  // train_val_split
  vector<vector<float>> X_train (54000);
  copy_n(X_mnist.begin(), 54000, X_train.begin());
  vector<vector<float>> y_train (54000);
  copy_n(y_mnist.begin(), 54000, y_train.begin());

  vector<vector<float>> X_val (6000);
  copy_n(X_mnist.begin() + 54000, 6000, X_val.begin());
  vector<vector<float>> y_val (6000);
  copy_n(y_mnist.begin() + 54000, 6000, y_val.begin());

  cout << "data loading done" << endl;

  Network net = Network();

  cout << "fit" << endl;

  // net.fit(X_xor, y_xor, X_xor, y_xor);
  // saveCSV(net.predict(X_xor), "../xor_predictions.csv");

  net.fit(X_train, y_train, X_val, y_val);

  cout << "train predict" << endl;
  saveCSV(net.predict(X_mnist), "../train_predictions.csv");




  // TEST SET
  string path_fmnist_test = "../data/fashion_mnist_test_vectors.csv";
  //string path_fmnist_test_labels = "../data/fashion_mnist_test_labels.csv";

  vector<vector<float>> X_test = readCSV(path_fmnist_test);
  normalize(X_test);
  //vector<vector<float>> y_test = readOneHot(path_fmnist_test_labels, 10);

  cout << "test predict" << endl;
  saveCSV(net.predict(X_test), "../test_predictions.csv");

  cout << "DONE" << endl;

}
