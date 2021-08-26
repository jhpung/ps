#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int a, b;
int start;
vector<int> orders[32001];
int count[32001] = {0};
int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    vector<int> result;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        orders[a].push_back(b);
        ++count[b];
    }

    for (int i = 1; i <= N; i++)
    {
        if (count[i] == 0)
        {
            q.push(i);
        }
    }
    int curr;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        result.push_back(curr);
        for (auto node : orders[curr])
        {
            if (--count[node] < 1)
            {
                q.push(node);
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}