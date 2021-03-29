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
int n, k;
string now;
string nextstr;

void change()
{
    nextstr = "";
    for (int i = 0; i < n; i++)
    {

        int pre = (i + n - 1) % n, post = (i + 1) % n;
        if (now[i] == now[post] && now[i] == now[pre])
        {
            nextstr += 'B';
            continue;
        }

        int r = 0, g = 0, b = 0;
        if (now[i] == 'R')
            r++;
        else if (now[i] == 'G')
            g++;
        else if (now[i] == 'B')
            b++;

        if (now[pre] == 'R')
            r++;
        else if (now[pre] == 'G')
            g++;
        else if (now[pre] == 'B')
            b++;

        if (now[post] == 'R')
            r++;
        else if (now[post] == 'G')
            g++;
        else if (now[post] == 'B')
            b++;

        if (r == 1 && b == 1 && g == 1)
        {
            nextstr += 'B';
            continue;
        }
        if ((r == 2 && g == 1) || (g == 2 && b == 1) || (b == 2 && r == 1))
            nextstr += 'R';
        else
            nextstr += 'G';
    }
    now = nextstr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cin >> now;

    while (k--)
    {
        change();
        //cout << nextstr << endl;
    }
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (now[i] == 'R')
            r++;
        else if (now[i] == 'G')
            g++;
        else
            b++;
    }

    cout << r << " " << g << " " << b;

    return 0;
}