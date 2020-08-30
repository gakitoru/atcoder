#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main() {

  int N = 0;
  cin >> N;
  vector<int> L(N);

  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
	int a = L[i];
	int b = L[j];
	int c = L[k];
	if (a + b > c && b + c > a && c + a > b && a != b && b != c && c != a) cnt++;
      }
    }
  }

  cout << cnt << endl;
  


  return 0;

}
