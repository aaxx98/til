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
int dp[12];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < 12; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    int n, temp;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        cout << dp[temp] << "\n";
    }

    return 0;
}