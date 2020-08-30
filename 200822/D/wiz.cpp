#include <iostream>
#include <vector>
using namespace std;

void walk(int i, int j, vector< vector<char> >& S, int H, int W, int num) {
  
  if(i + 1 < H)  { if(S.at(i + 1).at(j) != '#' && S.at(i + 1).at(j) != num) {S.at(i + 1).at(j) = num; walk(i + 1, j, S, H, W, num);} else {}}
  if(i - 1 >= 0) { if(S.at(i - 1).at(j) != '#' && S.at(i - 1).at(j) != num) {S.at(i - 1).at(j) = num; walk(i - 1, j, S, H, W, num);} else {}}
  if(j + 1 < W)  { if(S.at(i).at(j + 1) != '#' && S.at(i).at(j + 1) != num) {S.at(i).at(j + 1) = num; walk(i, j + 1, S, H, W, num);} else {}}
  if(j - 1 >= 0) { if(S.at(i).at(j - 1) != '#' && S.at(i).at(j - 1) != num) {S.at(i).at(j - 1) = num; walk(i, j - 1, S, H, W, num);} else {}}
  return ;
  
}

int fill_5_matrix(int i, int j, int num, vector< vector<char> >& S, int H, int W) {

  int k, l = 0;

  int ret = 0;
  for(k = -2; k <=2; k++) {
    for(l = -2; l <=2; l++) {
      if(i + k >= 0 && i + k < H && j + l >= 0 && j + l < W) {
	//if ((S.at(i + k).at(j + l) >= 0 || S.at(i + k).at(j + l) < num) && S.at(i + k).at(j + l) != '#') S.at(i + k).at(j + l) = num + 1;
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
  S.at(Ch).at(Cw) = 0;D
  walk(Ch, Cw, S, H, W, num);
  if(S.at(Dh).at(Dw) >= 0 && S.at(Dh).at(Dw) != '#') {cout << "total jump:" << int(S.at(Dh).at(Dw)) << endl; return 0;}

  int ret = 0;
  ret = jump(num, S, H, W);
  if(S.at(Dh).at(Dw) >= 0 && S.at(Dh).at(Dw) != '#') {cout << "total jump:" << int(S.at(Dh).at(Dw)) << endl; return 0;}
  if(ret == 0) {cout << "unreachable" << endl; return 0;}
  
  num = num + 1;
  
  while(1) {
    
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
	if(S.at(i).at(j) == num) walk(i, j, S, H, W, num);
      }
    }
    
    ret = jump(num, S, H, W);
    if(ret == 0) {cout << "unreachable" << endl; return 0;}
    num = num + 1;

    cout << endl;
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
	cout << int(S.at(i).at(j)) << " ";
      }
      cout << endl;
    }

    if(S.at(Dh).at(Dw) > 0 && S.at(Dh).at(Dw) != '#') break;
  }

  cout << "total jump:" << int(S.at(Dh).at(Dw)) << endl;

    
  return 0;
}  
