#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(int argc, char** argv) {
  int F,S,G,U,D;
  int answer = 0;
  scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
  queue<pair<int, int>> q;
  vector<bool> visited(F + 1, false);
  q.push(make_pair(S, 0));
  visited[S] = true;
  while(!q.empty()) {
    pair<int, int> current = q.front(); q.pop();
    // cout << current.first << ' ' << current.second << endl;
    int up = current.first + U;
    int down = current.first - D;
    if(current.first == G) {
      cout << current.second;
      return 0;
    }
    if(up <= F && !visited[up]) {
      q.push(make_pair(up, current.second + 1));
      visited[up] = true;
    }
    if(down > 0 && !visited[down]) {
      q.push(make_pair(down, current.second + 1));
      visited[down] = true;
    }
  }
  cout << "use the stairs";
  return 0;
}