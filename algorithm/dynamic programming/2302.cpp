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
int n, vip, lastvip = 1;
vector<int> cont;
int dp[41];

int main()
{
    int ret = 1;
    cin >> n >> vip;
    int tmp;
    while (vip--)
    {
        cin >> tmp;
        cont.push_back(tmp - lastvip);
        lastvip = tmp + 1;
    }
    cont.push_back(n - lastvip + 1);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 40; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    for (auto x : cont)
    {
        //cout << x << endl;
        if (x != 0)
            ret *= dp[x];
    }

    cout << ret;

    return 0;
}