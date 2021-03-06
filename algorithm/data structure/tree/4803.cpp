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
int parent[502];

int getParent(int set[], int x)
{
    if (set[x] == x)
        return x;
    return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
    a = getParent(set, a);
    b = getParent(set, b);
    if (a < b)
        set[b] = a;
    else
        set[a] = b;
}

bool find(int set[], int a, int b)
{
    a = getParent(set, a);
    b = getParent(set, b);
    if (a == b)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tc = 1;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        int x, y;
        int trees = 0;

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            if (find(parent, x, y))
            {
                for (int i = 1; i <= n; i++)
                {
                    int p = getParent(parent, x);
                    if (parent[i] == p)
                        parent[i] = 0;
                }
            }
            else
                unionParent(parent, x, y);
        }

        for (int i = 1; i <= n; i++)
        {
            if (i == parent[i])
                trees++;
        }

        cout << "Case " << tc;
        if (trees == 0)
            cout << ": No trees.\n";
        else
        {
            if (trees == 1)
                cout << ": There is one tree.\n";
            else
                cout << ": A forest of " << trees << " trees.\n";
        }

        tc++;
        cin >> n >> m;
    }

    return 0;
}