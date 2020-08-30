#include <iostream>
#include <math.h>
using namespace std;

int getDigit(int N);
int sumOfEachNumber(int N, int digit);

int main(void) {

  int N;
  
  cin >> N;

  int digit = getDigit(N);

  //cout << digit << endl;

  int sum = sumOfEachNumber(N, digit);

  //cout << sum << endl;

  if (sum % 9 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}

int getDigit(int N) {
  int digit = 0;

  while (N != 0) {
    N /= 10;
    digit += 1;
  }

  return digit;
}

int sumOfEachNumber(int N, int digit) {

  int sum = 0;
  int number = 0;
  int i = 0;
  int j = 0;

  for(i = digit; i >= 0; i--) {
    number = N/pow(10, i);
    sum += number;
    N -= number*pow(10, i);    
  }
  
  return sum;
}
