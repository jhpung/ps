#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int hx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int k;
int w;
int h;
// int board[h][w];
// int visited[h][w];
int board[200][200];
bool visited[200][200][32];
int ny, nx;
int y;
int x;


bool in_range(int ny, int nx, int nk) {
  return 0 <= ny && ny < h && 0 <= nx && nx < w && board[ny][nx] != 1 && !visited[ny][nx][nk];
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie();
  cin >> k >> w >> h;

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> board[i][j];
    }
  }

  queue<vector<int>> q;

  q.push({0, 0, 0, 0});
  visited[0][0][0] = true;
  while(!q.empty()) {
    vector<int> current = q.front(); q.pop();
    int cy = current[0], cx = current[1], cc = current[2], ck = current[3];
    if(cy == h - 1 && cx == w - 1) {
      cout << cc;
      return 0;
    }
    if(ck < k) {
      for(int i = 0; i < 8; i++) {
        ny = cy + hy[i];
        nx = cx + hx[i];
        if(in_range(ny, nx, ck + 1)) {
          visited[ny][nx][ck + 1] = true;
          q.push({ny,nx, cc + 1, ck + 1});
        }
      }
    }

    for(int i = 0; i < 4; i++) {
      ny = cy + dy[i];
      nx = cx + dx[i];
      if(in_range(ny, nx, ck)) {
        visited[ny][nx][ck] = true;
        q.push({ny, nx, cc + 1, ck});
      }
    }
  }
  cout << -1;
  return 0;
}
