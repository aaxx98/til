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

int dp[5001];
string code;
int len;
int mod = 1000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> code;

    len = code.length();
    dp[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        int one = code[i - 1] - '0', ten = (code[i - 2] - '0') * 10 + code[i - 1] - '0';
        //cout << one << ' ' << ten << endl;
        if (one > 0)
            dp[i] += dp[i - 1];
        if (ten <= 26 && ten >= 10)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        dp[i] %= mod;
    }
    if (code == "0")
        cout << 0 << "\n";
    else
        cout << dp[len] << "\n";
    return 0;
}