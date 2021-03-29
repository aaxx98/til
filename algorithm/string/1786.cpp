#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <bitset>
#include <cmath>

using namespace std;
vector<int> getPartialMatch(const string &N)
{
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while (begin + matched < m)
    {
        if (N[begin + matched] == N[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
                begin++;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

vector<int> kmpSearch(const string &H, const string &N)
{
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);

    int matched = 0;
    for (int i = 0; i < n; i++)
    {
        while (matched > 0 && H[i] != N[matched])
            matched = pi[matched - 1];
        if (H[i] == N[matched])
        {
            matched++;
            if (matched == m)
            {
                ret.push_back(i - m + 1);
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string h, n;
    getline(cin, h);
    getline(cin, n);
    vector<int> ret = kmpSearch(h, n);

    cout << ret.size() << "\n";
    for (auto x : ret)
        cout << x + 1 << " ";

    return 0;
}