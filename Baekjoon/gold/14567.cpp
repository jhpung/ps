#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 1000
#define MAX_M 50000
using namespace std;

int N, M;
int a, b;
vector<int> graph[MAX_N + 1];
int count[MAX_N + 1] = {0};
int result[MAX_N + 1] = {0};
int main(int argc, char **argv)
{

    queue<pair<int, int>> q;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        ++count[b];
    }
    for (int i = 1; i <= N; i++)
    {
        if (count[i] == 0)
        {
            q.push({i, 1});
        }
    }
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        if (count[curr.first] < 0)
        {
            continue;
        }
        count[curr.first]--;
        result[curr.first] = curr.second;
        for (auto node : graph[curr.first])
        {
            count[node]--;
            if (count[node] == 0)
            {
                q.push({node, curr.second + 1});
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << " ";
    }
}