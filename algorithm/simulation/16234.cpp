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

int N, L, R;
int maps[51][51];
bool visited[51][51];
struct point
{
    int x, y;
};
point dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
queue<point> bfs_q;

int bfs(point p)
{
    vector<point> vec;
    int total = maps[p.x][p.y];
    int n = 1;

    vec.push_back(p);
    visited[p.x][p.y] = true;
    bfs_q.push(p);

    while (!bfs_q.empty())
    {
        point v = bfs_q.front();
        bfs_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int wx, wy;
            wx = v.x + dir[i].x;
            wy = v.y + dir[i].y;

            if (wx < N && wy < N && wx >= 0 && wy >= 0)
            {
                int diff = abs(maps[wx][wy] - maps[v.x][v.y]);
                if (!visited[wx][wy] && diff <= R && diff >= L)
                {
                    visited[wx][wy] = true;
                    vec.push_back({wx, wy});
                    bfs_q.push({wx, wy});
                    total += maps[wx][wy];
                    n++;
                }
            }
        }
    }

    int avr = total / n;
    for (auto el : vec)
    {
        //cout << el.x << " " << el.y << " " << avr << endl;
        maps[el.x][el.y] = avr;
    }
    return n;
}

int main()
{
    int cnt = 0, count = 0;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> maps[i][j];

    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    if (bfs({i, j}) > 1)
                        cnt++;
                }
            }
        }
        if (cnt > 0)
        {
            count++;
            memset(visited, 0, sizeof(visited));
            cnt = 0;
        }
        else
            break;
    }

    /*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << maps[i][j] << " ";
        }
        cout << endl;
    }
    */
    //cout << cnt << " ";
    cout << count;
    return 0;
}