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

int r, c;
string ins;
string graph[101];
int maps[101][101];
struct point
{
    int x, y;
};
point I;
vector<point> R, nextR;
point dir[10] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
void drawmap()
{
    string printmap[101];
    for (int i = 0; i < r; i++)
    {
        string str = "";
        str.append(c, '.');
        printmap[i] = str;
        for (int j = 0; j < c; j++)
        {
            if (maps[i][j] == 1)
                printmap[i][j] = 'R';
        }
    }
    printmap[I.x][I.y] = 'I';
    for (int i = 0; i < r; i++)
    {
        cout << printmap[i] << "\n";
    }
}

int calc(point r)
{
    return abs(I.x - r.x) + abs(I.y - r.y);
}

bool move(int d)
{
    if (d == 5)
        return true;
    point newI = {I.x + dir[d].x, I.y + dir[d].y};
    if (maps[newI.x][newI.y] > 0)
        return false;
    else
    {
        maps[I.x][I.y]--;
        I = newI;
        maps[I.x][I.y]++;
    }

    return true;
}

bool michin()
{
    for (auto r : R)
    {
        int minlen = 321;
        point minp = {-1, -1};
        int ret;
        for (int i = 1; i < 10; i++)
        {
            ret = calc({r.x + dir[i].x, r.y + dir[i].y});
            if (ret < minlen)
            {
                minlen = ret;
                minp = {r.x + dir[i].x, r.y + dir[i].y};
            }
        }
        if (minp.x > -1)
        {
            if (minp.x == I.x && minp.y == I.y)
                return false;
            maps[r.x][r.y]--;
            maps[minp.x][minp.y]++;
            nextR.push_back(minp);
        }
    }
    /*
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << maps[i][j];
        cout << endl;
    }
    */
    /*
    drawmap();
    cout << endl;
    */
    R.clear();
    for (int i = nextR.size() - 1; i >= 0; i--)
    {
        point r = nextR[i];
        if (maps[r.x][r.y] > 1)
            maps[r.x][r.y] = 0;

        else if (maps[r.x][r.y] == 1)
            R.push_back(r);
    }
    nextR.clear();
    return true;
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> graph[i];
        for (int j = 0; j < c; j++)
        {
            if (graph[i][j] == 'I')
            {
                I = {i, j};
                maps[i][j] = 1;
            }
            else if (graph[i][j] == 'R')
            {
                maps[i][j] = 1;
                R.push_back({i, j});
            }
        }
    }

    cin >> ins;
    for (int i = 0; i < ins.size(); i++)
    {
        if (move(ins[i] - '0'))
        {
            if (!michin())
            {
                cout << "kraj " << i + 1;
                return 0;
            }
        }
        else
        {
            cout << "kraj " << i + 1;
            return 0;
        }
    }
    drawmap();
    return 0;
}