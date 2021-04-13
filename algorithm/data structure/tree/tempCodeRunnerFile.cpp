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
bool visited[502];

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
        bool isZero = false;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            if (!visited[x] && !visited[y]) //둘다 false라면
            {
                visited[x] = true;
                visited[y] = true;
                trees++;
            }
            else if (!visited[x] || !visited[y]) //둘중에 하나만 false라면
            {
                visited[x] = true;
                visited[y] = true;
            }

            else if (visited[x] && visited[y]) //둘다 true라면 cycle
                isZero = true;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                trees++;
        }

        cout << "Case " << tc;
        if (isZero)
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
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}