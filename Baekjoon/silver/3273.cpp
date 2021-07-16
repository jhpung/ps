#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char** argv) {
  int answer = 0;
  ios::sync_with_stdio(0);
  cin.tie();

  int n, x, curr;
  vector<int> num_list;
  cin >> n;
  for(int i = 0; i< n;i++) {
    cin >> curr;
    num_list.push_back(curr);
  }
  cin >> x;

  sort(num_list.begin(), num_list.end());
  int i = 0; int j = n - 1;
  while(i < j) {
    if(num_list[i] + num_list[j] == x) {
      ++i;
      --j;
      ++answer;
    }
    if(num_list[i] + num_list[j] > x) {
      --j;
    }
    if(num_list[i] + num_list[j] < x) {
      ++i;
    }
  }

  cout << answer;
  return 0;
}


// 1 2 3 5 7 9 10 11 12
// 13