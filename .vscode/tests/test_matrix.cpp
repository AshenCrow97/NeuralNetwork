/*------------------------------------TESTS---------------------------------- */
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
