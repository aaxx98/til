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

int dp[100001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][0] %= 9901;
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][1] %= 9901;
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] %= 9901;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
    return 0;
}