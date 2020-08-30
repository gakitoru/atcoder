#include <iostream>
using namespace std;

int main(void) {

  int N, X, T;

  cin >> N >> X >> T;

  //cout << "N:" << N << ", X:" << X << ", T:" << T << endl;

  int roop = N/X;
  int left = N%X;

  if(left != 0) roop += 1;

  int time = roop * T;

  //cout << roop << ", " << left << ", " << time << endl;

  cout << time << endl;

}
