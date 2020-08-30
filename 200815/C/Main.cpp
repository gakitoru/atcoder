#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main() {
  long long X, K, D;
  cin >> X >> K >> D;

  //X = pow(10, 15);
  //K = pow(10, 15);
  //D = 1;
  
  X = abs(X);
  
  long long amari = X%D; //2
  long long count = X/D;
  long long ans = 0;
  //  cout << X << ", " << amari << ", " << count << ", " << ans << endl;

  long long tmp = count - K;
  if (tmp >= 0) {
    for (int i = 0; i < K; i++) {
      X -= D;
    }
    ans = X;
  }
  else {
    if ((-tmp)%2 == 0) ans = amari;
    else ans = amari - D;
      
  }

  cout << abs(ans) << endl;

  

  return 0;
}

