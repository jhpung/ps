#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;

typedef long long ll;

int N, M, K;
int *nums;
ll *tree;
ll mod = 1000000007;
int a, b, c;

ll init_mul(int start, int end, int node)
{
  if (start == end)
  {
    return tree[node] = nums[start];
  }
  int mid = (start + end) / 2;
  return tree[node] = init_mul(start, mid, node * 2) * init_mul(mid + 1, end, node * 2 + 1) % mod;
}

ll find_mul(int start, int end, int node, int left, int right)
{
  // 구간 밖일 시
  if (start > right || end < left)
  {
    return 1;
  }
  // 완전 포함 시
  if (start >= left && end <= right)
  {
    return tree[node];
  }
  // 걸쳐 있을 시
  int mid = (start + end) / 2;
  return find_mul(start, mid, node * 2, left, right) * find_mul(mid + 1, end, node * 2 + 1, left, right) % mod;
}

void update(int start, int end, int node, int index, int diff)
{
  if (index < start || index > end)
  {
    return;
  }
  if (start == end)
  {
    tree[node] += diff;
    nums[start] = tree[node];
    return;
  }
  else
  {
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
    tree[node] = tree[node * 2] * tree[node * 2 + 1] % mod;
  }
}

int main(int argc, char **argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> K;
  nums = (int *)malloc(sizeof(int) * N);
  int size = 1 << (int)ceil(log2(N) + 1);
  tree = (ll *)malloc(sizeof(ll) * size);
  memset(tree, 0, sizeof(ll) * size);
  for (int i = 0; i < N; i++)
  {
    cin >> nums[i];
  }

  init_mul(0, N - 1, 1);

  for (int i = 0; i < M + K; i++)
  {
    cin >> a >> b >> c;
    if (a == 1)
    {
      update(0, N - 1, 1, b - 1, c - nums[b - 1]);
    }
    if (a == 2)
    {
      cout << find_mul(0, N - 1, 1, b - 1, c - 1) % 1000000007 << '\n';
    }
  }
}