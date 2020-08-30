#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {

  int N;
  cin >> N;
  vector<int> cards(3*N);
  map<int, int> counts;

  for (int i = 0; i < 3*N; i++) {
    cin >> cards[i];
  }
  
  for (int i = 0; i < 3*N; i++) {
    cout << cards[i] << endl;
  }

  for (int i = 0; i < 5; i++) {
    counts[cards[i]]++;
  }
  
  /* 1. count up first 5 cards */
  for (auto m: counts) {
  cout << m.first << ", " << m.second << endl;
}
  
  /* 2. if 3 cards are same, choose them & get 1 point */
  int selects = 0;
  
  
  /* 2. else choose, (1,2) or (2,3) or (1,3) to the next 5 cards, generate 3 branches */
  
  // 3. gen new cards
  
  // 4. goto 1
  
  return 0;
  
}
  
