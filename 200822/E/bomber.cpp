#include <iostream>
#include <vector>
using namespace std;

class Bomb {
public:
  int x;
  int y;
  bool is_target;
};
  
int main(void) {

  int H, W, M = 0;
  cin >> H >> W >> M;

  vector<Bomb> bombs(M);

  for(int i = 0; i < M; i++){
    cin >> bombs[i].x >> bombs[i].y;
    bombs[i].x -= 1;
    bombs[i].y -= 1;
    bombs[i].is_target = false;
  }

  int max = 0;
  for(int k = 0; k < H; k++){
    for(int l = 0; l < W; l++){
      int sum = 0;
      for(int m = 0; m < M; m++) {
	if(k == bombs[m].x || l == bombs[m].y) sum += 1;
      }
      if(sum >= max) max = sum;
    }
  }

  cout << max << endl;
  
  return 0;
}
