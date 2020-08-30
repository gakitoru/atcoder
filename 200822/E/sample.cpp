#include <iostream>
#include <set>

using namespace std;

int main(void) {
  set<int> st{1, 1, 3, 3, 2, 4, 0, 3, 6};
  auto itr = st.begin();
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    cout << *itr;
  }

  return 0;
}
  
