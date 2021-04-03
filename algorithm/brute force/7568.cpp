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

vector<pair<int, int>> person;
vector<int> num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        person.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if ((person[i].first < person[j].first) && (person[i].second < person[j].second))
                count++;
        }
        num.push_back(count + 1);
    }

    for (auto x : num)
        cout << x << " ";
    return 0;
}