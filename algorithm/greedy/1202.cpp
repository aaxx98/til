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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    long long ret = 0;
    vector<pair<int, int>> gem;
    vector<int> bag;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        gem.push_back({0, 0});
        cin >> gem[i].first >> gem[i].second;
    }

    for (int i = 0; i < k; i++)
    {
        bag.push_back(0);
        cin >> bag[i];
    }

    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && bag[i] >= gem[j].first)
            pq.push(gem[j++].second);

        if (!pq.empty())
        {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";

    return 0;
}