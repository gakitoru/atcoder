#include <iostream>
#include <string>
using namespace std;
int main() {

  string s;
  cin >> s;

  int max = 0;
  int cnt = 0;

  if (s[0] == 'R') {cnt++; max = 1;}
  for (int i = 1; i < 3; i++) {
    if (s[i - 1] == 'S' && s[i] == 'R') {cnt = 1; if(max < cnt) max = cnt;}
    if (s[i - 1] == 'R' && s[i] == 'R') {cnt++; if(max < cnt) max = cnt;}
    if (s[i] == 'S') cnt = 0;
  }
  
  
  cout << max << endl;

  return 0;

}
