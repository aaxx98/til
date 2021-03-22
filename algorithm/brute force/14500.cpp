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

int twobythree[8][2][3] = {{{1, 0, 0}, {1, 1, 1}}, {{0, 0, 1}, {1, 1, 1}}, {{1, 1, 1}, {0, 0, 1}}, {{1, 1, 1}, {1, 0, 0}}, {{1, 1, 1}, {0, 1, 0}}, {{0, 1, 0}, {1, 1, 1}}, {{0, 1, 1}, {1, 1, 0}}, {{1, 1, 0}, {0, 1, 1}}};
int threebytwo[8][3][2] = {{{0, 1}, {0, 1}, {1, 1}}, {{1, 0}, {1, 0}, {1, 1}}, {{1, 1}, {1, 0}, {1, 0}}, {{1, 1}, {0, 1}, {0, 1}}, {{0, 1}, {1, 1}, {0, 1}}, {{1, 0}, {1, 1}, {1, 0}}, {{1, 0}, {1, 1}, {0, 1}}, {{0, 1}, {1, 1}, {1, 0}}};
int graph[501][501];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    int retmax = 0;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }

    //2*2 사각형
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            total = graph[i][j] + graph[i + 1][j] + graph[i][j + 1] + graph[i + 1][j + 1];
            retmax = max(retmax, total);
        }
    }

    //4*1 사각형
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = 0; j < m; j++)
        {
            total = graph[i][j] + graph[i + 1][j] + graph[i + 2][j] + graph[i + 3][j];
            retmax = max(retmax, total);
        }
    }

    //1*4 사각형
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 3; j++)
        {
            total = graph[i][j] + graph[i][j + 1] + graph[i][j + 2] + graph[i][j + 3];
            retmax = max(retmax, total);
        }
    }

    //2*3
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                total = 0;
                for (int x = 0; x < 2; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (twobythree[k][x][y])
                            total += graph[i + x][j + y];
                    }
                }
                retmax = max(retmax, total);
            }
        }
    }

    //3*2
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                total = 0;
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 2; y++)
                    {
                        if (threebytwo[k][x][y])
                            total += graph[i + x][j + y];
                    }
                }
                retmax = max(retmax, total);
            }
        }
    }

    cout << retmax;
    return 0;
}