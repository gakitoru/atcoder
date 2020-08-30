#include <queue>
#include <algorithm>
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


  
  queue<int> point_q;
  queue< vector<int> > cards_q;
  cards_q.push(cards);
  point_q.push(0);

  int q_len = 0;
  int tmp_point = 0;
  int max_point = 0;

  while (true) {

    q_len = cards_q.size();
    if (q_len == 0) break;
    
    for (int k = 0; k < q_len; k++) {
    
      vector<int> tmp_cards = cards_q.front();
      tmp_point = point_q.front();
      cards_q.pop();
      point_q.pop();
      counts.clear();

      for (int i = 0; i < 5; i++) {
	counts[tmp_cards[i]]++;
      }
    
      for (auto m: counts) {
	cout << m.first << ", " << m.second << endl;
      }
    
      int select = 0;
      for (auto m: counts) {
	if (m.second >= 3) select = m.first;
      }
    
      if (select != 0) {
	cout << "choose:" << select << endl;
	for (int i = 0; i < 5; i++) {
	  if (tmp_cards[i] == select) tmp_cards[i] = 0;
	}
	sort(tmp_cards.begin(), tmp_cards.begin() + 5);
	cout << endl;
	for (int i = 0; i < tmp_cards.size(); i++) {
	  cout << tmp_cards[i] << " ";
	}
	cout << endl;
	tmp_cards.erase(tmp_cards.begin(), tmp_cards.begin() + 3);
	for (int i = 0; i < tmp_cards.size(); i++) {
	  cout << tmp_cards[i] << " ";
	}
	cout << endl;
	if(tmp_cards.size() != 0) {
	  cards_q.push(tmp_cards);
	  point_q.push(tmp_point + 1);
	  cout << "IN" << endl;
	} else {
	  if (max_point < tmp_point + 1) max_point = tmp_point + 1;
	}
      
      } else {
	cout << "no three" << endl;
	int leave1, leave2 = 0;

	vector<int> new_cards1 = tmp_cards;
	leave1 = 0;
	leave2 = 1;
	new_cards1[2] = 0;
	new_cards1[3] = 0;
	new_cards1[4] = 0;
	sort(new_cards1.begin(), new_cards1.begin() + 5);
	new_cards1.erase(new_cards1.begin(), new_cards1.begin() + 3);
	if(new_cards1.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}
      

	vector<int> new_cards2 = tmp_cards;
	leave1 = 0;
	leave2 = 2;
	new_cards2[1] = 0;
	new_cards2[3] = 0;
	new_cards2[4] = 0;
	sort(new_cards2.begin(), new_cards2.begin() + 5);
	new_cards2.erase(new_cards2.begin(), new_cards2.begin() + 3);
	if(new_cards2.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}

	vector<int> new_cards3 = tmp_cards;
	leave1 = 0;
	leave2 = 3;
	new_cards3[1] = 0;
	new_cards3[2] = 0;
	new_cards3[4] = 0;
	sort(new_cards3.begin(), new_cards3.begin() + 5);
	new_cards3.erase(new_cards3.begin(), new_cards3.begin() + 3);
	if(new_cards3.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}

	vector<int> new_cards4 = tmp_cards;
	leave1 = 0;
	leave2 = 4;
	new_cards4[1] = 0;
	new_cards4[2] = 0;
	new_cards4[3] = 0;
	sort(new_cards4.begin(), new_cards4.begin() + 5);
	new_cards4.erase(new_cards4.begin(), new_cards4.begin() + 3);
	if(new_cards4.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}

	vector<int> new_cards5 = tmp_cards;
	leave1 = 1;
	leave2 = 2;
	new_cards5[0] = 0;
	new_cards5[3] = 0;
	new_cards5[4] = 0;
	sort(new_cards5.begin(), new_cards5.begin() + 5);
	new_cards5.erase(new_cards5.begin(), new_cards5.begin() + 3);
	if(new_cards5.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}


	vector<int> new_cards6 = tmp_cards;
	leave1 = 1;
	leave2 = 3;
	new_cards6[0] = 0;
	new_cards6[2] = 0;
	new_cards6[4] = 0;
	sort(new_cards6.begin(), new_cards6.begin() + 5);
	new_cards6.erase(new_cards6.begin(), new_cards6.begin() + 3);
	if(new_cards6.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}

	vector<int> new_cards7 = tmp_cards;
	leave1 = 1;
	leave2 = 4;
	new_cards7[0] = 0;
	new_cards7[2] = 0;
	new_cards7[3] = 0;
	sort(new_cards7.begin(), new_cards7.begin() + 5);
	new_cards7.erase(new_cards7.begin(), new_cards7.begin() + 3);
	if(new_cards7.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}

	vector<int> new_cards8 = tmp_cards;
	leave1 = 2;
	leave2 = 3;
	new_cards8[0] = 0;
	new_cards8[1] = 0;
	new_cards8[4] = 0;
	sort(new_cards8.begin(), new_cards8.begin() + 5);
	new_cards8.erase(new_cards8.begin(), new_cards8.begin() + 3);
	if(new_cards8.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}


	vector<int> new_cards9 = tmp_cards;
	leave1 = 2;
	leave2 = 4;
	new_cards9[0] = 0;
	new_cards9[1] = 0;
	new_cards9[3] = 0;
	sort(new_cards9.begin(), new_cards9.begin() + 5);
	new_cards9.erase(new_cards9.begin(), new_cards9.begin() + 3);
	if(new_cards9.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}

	vector<int> new_cards10 = tmp_cards;
	leave1 = 3;
	leave2 = 4;
	new_cards10[0] = 0;
	new_cards10[1] = 0;
	new_cards10[2] = 0;
	sort(new_cards10.begin(), new_cards10.begin() + 5);
	new_cards10.erase(new_cards10.begin(), new_cards10.begin() + 3);
	if(new_cards10.size() != 0) {
	  cards_q.push(new_cards1);
	  point_q.push(tmp_point);
	}
      }
    
    }
    
  }  

  cout << "max: " << max_point << endl;
  return 0;
  
}
  
