#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

typedef long long ll;

ll N, M, K;
ll a, b, c;
ll *tree;
ll *nums;

ll init(int start, int end, ll node)
{
    if (start == end)
    {
        return tree[node] = nums[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, ll node, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (start >= left && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, ll node, ll index, ll diff)
{
    if (index < start || index > end)
        return;
    tree[node] += diff;
    if (start == end)
    {
        nums[index] += diff;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll size;
    cin >> N >> M >> K;

    nums = (ll *)malloc(sizeof(ll) * N);
    size = 1 << (ll)(ceill(log2l(N) + 1));
    tree = (ll *)malloc(sizeof(ll) * size);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    init(0, N - 1, 1);

    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(0, N - 1, 1, b - 1, c - nums[b - 1]);
        }
        if (a == 2)
        {
            cout << sum(0, N - 1, 1, b - 1, c - 1) << endl;
        }
    }
}