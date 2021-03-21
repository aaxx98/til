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
int dp[300][2];
int stairs[301];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stairs[i];
    }
    dp[1][0] = stairs[1];
    dp[2][0] = stairs[1] + stairs[2];
    dp[2][1] = stairs[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1] + stairs[i];
        dp[i][1] += stairs[i];
        dp[i][1] += max(dp[i - 2][0], dp[i - 2][1]);

        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}