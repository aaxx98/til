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

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = true;
    int M = key.size();
    int N = lock.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int ii = 0; ii < i; ii++)
            {
                for (int jj = 0; jj < j; jj++)
                {
                    if
                }
            }
            for (int x = 0; x < M; x++)
            {
                for (int y = 0; y < M; y++)
                {
                }
            }
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> key = {{1, 1, 1}, {3, 3, 3}};
    int M = key.size();
    cout << M;
    return 0;
}