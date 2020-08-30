#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b){
    a = b;
    return true;
  }
  return false;
}


int H, W, M;
set<i_i> st;

void input() {
  cin >> H >> W >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    st.insert({a, b});
  }
}

void solve() {
  map<int, int> mph, mpw;
  int hmaxval = 0;
  int wmaxval = 0;
  vector<int> hmax, wmax;

  for(auto tmp : st) {
    chmax(hmaxval, ++mph[tmp.first]);
    chmax(wmaxval, ++mpw[tmp.second]);
  }

  for(auto tmp: mph) {
    if (hmaxval == tmp.second) hmax.push_back(tmp.first);
  }
  for(auto tmp: mpw) {
    if (wmaxval == tmp.second) wmax.push_back(tmp.first);
  }

  int ANS = hmaxval + wmaxval - 1;
  for (auto h : hmax) {
    for (auto w :wmax) {
      if (st.find({h, w}) == st.end()) {
	ANS++;
	cout << ANS << endl;
	return;
      }
    }
  }

  cout << ANS << endl;

  
}


int main() {
  input();
  solve();
  return 0;
}
