#include <iostream>
#include <math.h>
using namespace std;

int main(void) {

  int A[2*10^5];
  int N = 0;
  cin >>  N;

  int i = 0;
  int max = 0;
  int sum = 0;

  for(i = 0; i < N; i++) {
    cin >> A[i];
    if(i == 0) {
      max = A[i];
    } else {
      if(A[i] < max) {sum += (max - A[i]);}
      else {max = A[i];}
    }
  }


  cout << sum << endl;

  return 0;
}
    
  
  
