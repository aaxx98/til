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

const int MOD = 10007;
int cache[1001];

int tiling(int n)
{
    if (n <= 1)
        return 1;

    int &ret = cache[n];
    if (ret != -1)
        return ret;
    return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int main()
{
    int num;
    cin >> num;
    memset(cache, -1, sizeof(cache));
    cout << tiling(num);
    return 0;
}