#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

int N, M, K;
int a, b, c;
int *min_tree;
int *nums;

int init_min(int start, int end, int node)
{
  if (start == end)
  {
    return min_tree[node] = nums[start];
  }
  if ((start - end) == 1)
  {
    return min_tree[node] = min(nums[start], nums[end]);
  }
  int mid = (start + end) / 2;
  return min_tree[node] = min(init_min(start, mid, node * 2), init_min(mid + 1, end, node * 2 + 1));
}

int find_min(int start, int end, int node, int left, int right)
{
  if (start > right || end < left)
  {
    return 1000000000;
  }
  if (start >= left && end <= right)
  {
    return min_tree[node];
  }
  int mid = (start + end) / 2;
  return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}

int main(int argc, char **argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int size;
  cin >> N >> M;

  nums = (int *)malloc(sizeof(int) * N);
  size = 1 << (int)(ceil(log2l(N) + 1));
  min_tree = (int *)malloc(sizeof(int) * size);
  memset(min_tree, 1000000000, sizeof(int) * size);

  for (int i = 0; i < N; i++)
  {
    cin >> nums[i];
  }
  init_min(0, N - 1, 1);
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    cout << find_min(0, N - 1, 1, a - 1, b - 1) << '\n';
  }
}