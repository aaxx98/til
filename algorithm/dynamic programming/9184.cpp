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
int dp[21][21][21];

int calc(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return calc(20, 20, 20);
    if (dp[a][b][c] != -1)
        return dp[a][b][c];
    if (a < b && b < c)
        return dp[a][b][c] = calc(a, b, c - 1) + calc(a, b - 1, c - 1) - calc(a, b - 1, c);

    return dp[a][b][c] = calc(a - 1, b, c) + calc(a - 1, b - 1, c) + calc(a - 1, b, c - 1) - calc(a - 1, b - 1, c - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    memset(dp, -1, sizeof(dp));
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << calc(a, b, c) << "\n";
    }
    return 0;
}