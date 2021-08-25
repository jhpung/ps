#include <iostream>
#include <vector>
using namespace std;

int result = 0;
vector<int> ap;

vector<int> makePi(string p)
{
    int m = (int)p.size();
    vector<int> pi(m, 0);
    int count = 0;
    for (int i = 1; i < m; i++)
    {
        while (count > 0 && p[i] != p[count])
        {
            count = pi[count - 1];
        }
        if (p[i] == p[count])
        {
            pi[i] = ++count;
        }
    }
    return pi;
}

bool kmp(string s, string p)
{
    vector<int> pi = makePi(p);
    int n = s.size(), m = p.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        while (count > 0 && s[i] != p[count])
        {
            count = pi[count - 1];
        }
        if (s[i] == p[count])
        {
            if (count == m - 1)
            {
                result++;
                ap.push_back((i + 1) - (m - 1));
                count = pi[count];
                continue;
            }
            else
            {
                ++count;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    char a[1000001];
    char b[1000001];
    cin.getline(a, 1000001);
    cin.getline(b, 1000001);
    kmp(a, b);
    cout << result << endl;
    for (int i = 0; i < ap.size(); i++)
    {
        if (i == ap.size() - 1)
        {
            cout << ap[i];
        }
        else
        {

            cout << ap[i] << ' ';
        }
    }
}