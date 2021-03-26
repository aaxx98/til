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
    long long cnt = 0, total = 0;
    for (long long i = n; i >= 5; i /= 5)
    {
        cnt++;
        total += cnt;
        //cout << cnt << endl;
    }
    total += n / 5 - cnt;

    return total;
}

long long find2(long long n)
{
    long long cnt = 0, total = 0;
    for (long long i = n; i >= 2; i /= 2)
    {
        cnt++;
        total += cnt;
        //cout << cnt << endl;
    }
    total += n / 2 - cnt;

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    long long five, two;
    cin >> n >> k;
    //cout << find5(2000000000) << endl;
    five = find5(n) - find5(k) - find5(n - k);
    two = find2(n) - find2(k) - find2(n - k);

    cout << min(two, five);

    return 0;
}