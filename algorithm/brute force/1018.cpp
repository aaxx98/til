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

string compare[2] = {"WBWBWBWB",
                     "BWBWBWBW"};
string graph[50];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int mincount = 2501;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            int total = 0;
            int total2 = 0;
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    if (compare[x % 2][y] != graph[x + i][y + j])
                        total++;
                    if (compare[(x + 1) % 2][y] != graph[x + i][y + j])
                        total2++;
                }
            }
            mincount = min(mincount, total);
            mincount = min(mincount, total2);
        }
    }
    cout << mincount;
    return 0;
}