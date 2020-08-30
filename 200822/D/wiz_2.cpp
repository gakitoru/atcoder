#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void walk(int i, int j, vector< vector<char> >& S, int H, int W, int num) {

  queue<int> q1;

  //i, j kitenn
  q1.push(i*W + j);
  
  while(1) {
    if(q1.empty()) break;
    int current = q1.front();
    q1.pop();
    int l = current%H;
    int k = current/H;
    cout << "k:" << k << endl;
    cout << "l:" << l << endl;
    if(k + 1 < H) {if(S.at(k + 1).at(l) == -1) {q1.push((k + 1)*H + l); S.at(k + 1).at(l) = num;}}
    if(k - 1 >= 0){if(S.at(k - 1).at(l) == -1) {q1.push((k - 1)*H + l); S.at(k - 1).at(l) = num;}}
    if(l + 1 < H) {if(S.at(k).at(l + 1) == -1) {q1.push(k*H + l + 1);   S.at(k).at(l + 1) = num;}}
    if(l - 1 >= H) {if(S.at(k).at(l - 1) == -1) {q1.push(k*H + l - 1);   S.at(k).at(l - 1) = num;}}
  }
					     
  return;
  
}

int fill_5_matrix(int i, int j, int num, vector< vector<char> >& S, int H, int W) {

  int k, l = 0;

  int ret = 0;
  for(k = -2; k <=2; k++) {
    for(l = -2; l <=2; l++) {
      if(i + k >= 0 && i + k < H && j + l >= 0 && j + l < W) {
	if ((S.at(i + k).at(j + l) >= num + 1 || S.at(i + k).at(j + l) < 0) && S.at(i + k).at(j + l) != '#') {S.at(i + k).at(j + l) = num + 1; ret++;}
      }
    }
  }

  return ret;
}

int jump(int num, vector< vector<char> >& S, int H, int W) {

  int ret = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++) {
      if(S.at(i).at(j) == num) {
	ret = fill_5_matrix(i, j, num, S, H, W);
      }
    }
  }
    
  return ret;
}

int main(void) {

  int H, W = 0;
  cin >> H >> W;
  cout << "H:" << H << " " << "W:" << W << endl;

  vector< vector<char> > S(H, vector<char>(W));
  
  int Ch, Cw = 0;
  cin >> Ch >> Cw;
  cout << "Ch:" << Ch << " " << "Cw:" << Cw << endl;

  int Dh, Dw = 0;
  cin >> Dh >> Dw;
  cout << "Dh:" << Dh << " " << "Dw:" << Dw << endl;

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> S.at(i).at(j);
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if (S.at(i).at(j) == '.') S.at(i).at(j) = -1;
      cout << S.at(i).at(j) << " ";
    }
    cout << endl;
  }

  cout << endl;

  int num = 0;
  S.at(Ch).at(Cw) = 0;

  while(1) {
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++) {
	if(S.at(i).at(j) == num) walk(i, j, S, H, W, num);
      }
    }
    if(S.at(Dh).at(Dw) == num) break;
    jump(num, S, H, W);
    num = num + 1;
  }
  
  cout << endl;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cout << int(S.at(i).at(j)) << " ";
    }
    cout << endl;
  }

  cout << "total:" << num << endl;
    
  return 0;
}  
