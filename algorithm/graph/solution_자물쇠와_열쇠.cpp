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

vector<vector<int>> rotate(vector<vector<int>> v)
{
    int N = v.size();
    vector<vector<int>> ret;
    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < N; j++)
            tmp.push_back(0);

        ret.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            ret[j][N - i - 1] = v[i][j];
    }
    return ret;
}
int temp[21][21];
bool judge(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool ret = true;
    int key_N = key.size();
    int lock_N = lock.size();

    for (int i = 0; i < lock_N; i++)
    {
        for (int j = 0; j < lock_N; j++)
        {
            ret = true;

            for (int ii = 0; ii < lock_N; ii++)
                for (int jj = 0; jj < lock_N; jj++)
                    temp[ii][jj] = lock[ii][jj];

            for (int x = 0; x < key_N && i + x < lock_N; x++)
                for (int y = 0; y < key_N && j + y < lock_N; y++)
                    temp[i + x][j + y] = lock[i + x][j + y] + key[x][y];

            for (int ii = 0; ii < lock_N; ii++)
            {
                for (int jj = 0; jj < lock_N; jj++)
                {
                    cout << temp[ii][jj] << " ";

                    if (temp[ii][jj] != 1)
                        ret = false;
                }
                cout << endl;
            }
            cout << endl;
            if (ret == true)
                return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int key_N = key.size();
    int lock_N = lock.size();

    vector<vector<int>> key_map = key;
    for (int r = 0; r < 4; r++)
    {
        if (judge(key_map, lock))
            return true;
        key_map = rotate(key_map);
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    cout << solution(key, lock);

    return 0;
}