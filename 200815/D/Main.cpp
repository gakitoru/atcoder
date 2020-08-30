#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int main(void) {

  int N;
  long long K;
  cin >> N >> K;
  
  vector<int> P(N + 1); //move
  for (int i = 1; i < N + 1; i++) {
    cin >> P[i];
  }
  vector<long long> C(N + 1); //point
  for (int i = 1; i < N + 1; i++) {
    cin >> C[i];
  }

  long long max_point = LLONG_MIN;
  long long tmp_point = 0;
  int current_p = 0;

  max_point = LLONG_MIN;
  for (int m_first = 1; m_first < N + 1; m_first++) {
    tmp_point = 0;
    current_p = m_first;
    //cout << "m_first: " << m_first << ", current: " << current_p << endl;
    for (int total = 1; total <= K; total++) {
      //cout << "total: " << total << ", current: " << current_p << endl;
      //cout << "tmp_point: " << tmp_point << endl;
      tmp_point += C[P[current_p]];
      if (max_point <= tmp_point) max_point = tmp_point;
      current_p = P[current_p];

      if (m_first == current_p && tmp_point <= 0) {
	tmp_point += C[P[current_p]];
	if (max_point <= tmp_point) max_point = tmp_point;
	break;
      } else if (m_first == current_p && tmp_point > 0){
	int cycle_num = K/total;
	int amari = K % total;
	// cout << "cycle_num: " << cycle_num << endl;
	// cout << "amari: " << amari << endl;
	// cout << "tmp_potnt: " << tmp_point << endl;
	tmp_point = tmp_point * (cycle_num - 1);
	if (max_point <= tmp_point) max_point = tmp_point;
	for (int l = 0; l < amari + total; l++) {
	  //cout << "tmp_point:" << tmp_point << endl;
	  tmp_point += C[P[current_p]];
	  if (max_point <= tmp_point) max_point = tmp_point;
	  current_p = P[current_p];
	}
	break;
      }
      
    }
    //cout << "" << endl;
  }

  cout << max_point << endl;
    
  return 0;
}  
