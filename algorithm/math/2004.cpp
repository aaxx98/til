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
long long find5(long long n)
{
    long long cnt = 0;
    for (long long i = 5; n / i > 0; i *= 5)
    {
        cnt += n / i;
    }
    return cnt;
}

long long find2(long long n)
{
    long long cnt = 0;
    for (long long i = 2; n / i > 0; i *= 2)
    {
        cnt += n / i;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    long long five, two;
    cin >> n >> k;

    five = find5(n) - find5(k) - find5(n - k);
    two = find2(n) - find2(k) - find2(n - k);

    cout << min(two, five);

    return 0;
}