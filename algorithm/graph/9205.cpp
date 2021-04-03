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

int tc, n;
vector<pair<int, int>> point;
int visited[103];

bool possible(int x, int y)
{
    int value = abs(point[x].first - point[y].first) + abs(point[x].second - point[y].second);
    return value <= 1000;
}

bool bfs(int p)
{
    queue<int> bfs_q; //bfs를 위한 큐
    int len = point.size();
    int v = 0;
    bfs_q.push(p); //현재 정점 탐색!
    visited[p] = 1;

    while (!bfs_q.empty())
    { //큐가 비어있을 때 까지
        v = bfs_q.front();
        //cout << "_" << v;
        if (v == len - 1)
            return true;

        bfs_q.pop();
        for (int i = 0; i < len; i++)
        {               //인접정점 탐색
            int wx, wy; //인접 정점의 index
            wx = v;
            wy = i;
            if (wx < len && wy < len && wx >= 0 && wy >= 0)
            { // 인접정점이 맵 안에 있고
                if (!visited[wy] && possible(wx, wy))
                { // 방문되지 않았고, 갈 수 있다면

                    bfs_q.push(wy); // 큐에 넣고
                    visited[wy] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        int x, y;
        cin >> n;
        for (int i = -2; i < n; i++)
        {
            cin >> x >> y;
            point.push_back({x, y});
        }

        if (bfs(0))
            cout
                << "happy\n";
        else
            cout << "sad\n";

        point.clear();
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}