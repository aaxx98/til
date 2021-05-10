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
vector<vector<int>> graph;
int N, ret = 0;

int ins[5];

void find_max(vector<vector<int>> g)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            ret = max(ret, g[i][j]);
    }
}

vector<vector<int>> play(vector<vector<int>> g, int in)
{
    queue<int> q, new_q;

    if (in == 0) //왼쪽
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (g[i][j] != 0)
                {
                    q.push(g[i][j]);
                    g[i][j] = 0;
                }
            }
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                if (!q.empty() && t == q.front())
                {
                    q.pop();
                    new_q.push(t * 2);
                }
                else
                    new_q.push(t);
            }
            int k = 0;
            while (!new_q.empty())
            {
                g[i][k++] = new_q.front();
                new_q.pop();
            }
        }
    }

    if (in == 1) //오른쪽
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (g[i][j] != 0)
                {

                    q.push(g[i][j]);
                    g[i][j] = 0;
                }
            }
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                if (!q.empty() && t == q.front())
                {
                    q.pop();
                    new_q.push(t * 2);
                }
                else
                    new_q.push(t);
            }
            int k = N - 1;
            while (!new_q.empty())
            {
                g[i][k--] = new_q.front();
                new_q.pop();
            }
        }
    }

    if (in == 2) // 위
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < N; i++)
            {
                if (g[i][j] != 0)
                {

                    q.push(g[i][j]);
                    g[i][j] = 0;
                }
            }
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                if (!q.empty() && t == q.front())
                {
                    q.pop();
                    new_q.push(t * 2);
                }
                else
                    new_q.push(t);
            }
            int k = 0;
            while (!new_q.empty())
            {
                g[k++][j] = new_q.front();
                new_q.pop();
            }
        }
    }

    if (in == 3) // 아래
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = N - 1; i >= 0; i--)
            {
                if (g[i][j] != 0)
                {
                    q.push(g[i][j]);
                    g[i][j] = 0;
                }
            }
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                if (!q.empty() && t == q.front())
                {
                    q.pop();
                    new_q.push(t * 2);
                }
                else
                    new_q.push(t);
            }
            int k = N - 1;
            while (!new_q.empty())
            {
                g[k--][j] = new_q.front();
                new_q.pop();
            }
        }
    }

    return g;
}

void print_ins(int m)
{
    for (int i = 0; i < m; i++)
        cout << ins[i] << " ";
    cout << endl;
}

void make_ins(int n, int m) //m개의 명령을 생성하고, 명령을 실행함
{
    if (n == m)
    {
        //print_ins(m);
        vector<vector<int>> temp = play(graph, ins[0]);
        for (int i = 1; i < m; i++)
            temp = play(temp, ins[i]);
        find_max(temp);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        ins[n] = i;
        make_ins(n + 1, m);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    graph.resize(N);
    for (int i = 0; i < N; i++)
    {
        graph[i].resize(N);
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    }
    for (int m = 1; m <= 5; m++)
        make_ins(0, m);

    cout << ret;

    /*
    vector<vector<int>> g = play(graph, 3);
    g = play(g, 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    */
    //테스트를 위한 코드
    return 0;
}