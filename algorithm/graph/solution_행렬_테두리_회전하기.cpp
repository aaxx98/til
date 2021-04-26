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

int C = 0;
int calc(int r, int c)
{
    return (r - 1) * C + c;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> maps;
    vector<int> answer;
    C = columns;

    for (int i = 0; i <= rows * columns; i++)
    {
        maps.push_back(i);
    }

    for (auto q : queries)
    {
        vector<int> index;
        int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
        int minnum = 98765;

        for (int i = y1; i < y2; i++)
            index.push_back(calc(x1, i));

        for (int i = x1; i < x2; i++)
            index.push_back(calc(i, y2));

        for (int i = y2; i > y1; i--)
            index.push_back(calc(x2, i));

        for (int i = x2; i > x1; i--)
            index.push_back(calc(i, y1));
        /*
        for (auto i : index)
        {
            cout << i << " ";
        }
        cout << endl;
        */

        int tmp = maps[index[index.size() - 1]];
        minnum = min(minnum, tmp);
        for (int i = index.size() - 2; i >= 0; i--)
        {
            minnum = min(minnum, maps[index[i]]);
            maps[index[i + 1]] = maps[index[i]];
        }
        maps[index[0]] = tmp;
        /*
        for (int i = 0; i <= 36; i++)
            cout << maps[i] << " ";
        cout << endl;
        */
        answer.push_back(minnum);
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> quer = {{2, 2, 5, 4},
                                {3, 3, 6, 6},
                                {5, 1, 6, 3}};

    vector<int> sol = solution(6, 6, quer);
    for (auto x : sol)
        cout << x << " ";

    return 0;
}