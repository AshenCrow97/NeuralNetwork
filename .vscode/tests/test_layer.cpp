// #include <iostream>
// #include <vector>

// #include "../src/layer.hpp"

// using namespace std;

// int main() {

//   // 1) init
//   Layer l = Layer(3, 4, "relu");
//   cout << "input size: " << l.input_size_ << endl;
//   cout << "size: " << l.size_ << endl;
//   cout << "activation: " << l.activation_.type_ << endl;
//   cout << "weights:" << endl;
//   print(l.weights_);
//   cout << endl;
//   cout << "biases:" << endl;
//   print(l.biases_);
//   cout << endl;
//   cout << "outputs:" << endl;
//   print(l.outputs_);
//   cout << endl;
//   cout << "dw:" << endl;
//   print(l.dw_);
//   cout << endl;
//   cout << "db:" << endl;
//   print(l.db_);
//   cout << endl;


//   // 2) forward
//   vector<float> vec {1, -2, 3};
//   print(l.forward(vec));

//   // 3) backward
//   vector<float> vec2 {1, -2, 3, 4};
//   print(l.backward(vec, vec2));
//   cout << "dw:" << endl;
//   print(l.dw_);
//   cout << endl;
//   cout << "db:" << endl;
//   print(l.db_);
//   cout << endl;
  
//   // 4) update
//   l.update(0.1);
//   cout << "weights:" << endl;
//   print(l.weights_);
//   cout << endl;
//   cout << "biases:" << endl;
//   print(l.biases_);
//   cout << endl;
//   cout << "outputs:" << endl;
//   print(l.outputs_);
//   cout << endl;
//   cout << "dw:" << endl;
//   print(l.dw_);
//   cout << endl;
//   cout << "db:" << endl;
//   print(l.db_);
//   cout << endl;

//   Layer l = Layer(2, 2, "leaky_relu");
//   cout << "INIT" << endl;
//   cout << "weights:" << endl;
//   print(l.get_weights());
//   cout << endl;
//   cout << "biases:" << endl;
//   print(l.get_biases());
//   cout << endl;

//   vector<float> vec1 {-1, 1};
//   vector<float> tar1 {0, 1};

//   cout << "FORWARD" << endl;
//   print(l.forward(vec1));
//   print(l.get_potentials());

//   cout << "BACKWARD" << endl;
//   print(l.backward(vec1, vecAddElem(l.forward(vec1), vecMul(-1.0, tar1))));

//   cout << "dw" << endl;
//   print(l.get_dw());
//   cout << endl;
//   cout << "db" << endl;
//   print(l.get_db());
//   cout << endl;



// }
