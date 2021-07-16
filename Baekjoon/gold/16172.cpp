#include <iostream>
#include <vector>
using namespace std;


vector<int> makePi(string p) {
  int m = (int)p.size();
  vector<int> pi(m, 0);
  int j = 0;
  for(int i=1;i<m;i++) {
    while(j > 0 && p[i] != p[j]) {
      j = pi[j-1];
    }
    if(p[i] == p[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}

bool kmp(string s, string p) {
  vector<int> pi = makePi(p);
  int n = s.size(),m = p.size();
  int j = 0;

  for(int i = 0; i < n; i++) {
    if(isdigit(s[i])) continue;
    while(j > 0 && s[i] != p[j]) {
      j = pi[j - 1];
    }
    if(s[i] == p[j]) {
      if(j == m-1) {
        return true;
      } else {
        ++j;
      }
    }
  }
  return false;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string a, b;
  cin >> a >> b;
  bool result = kmp(a,b);
  cout << result;
}