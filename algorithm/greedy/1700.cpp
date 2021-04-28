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

vector<int> use;
vector<int> temp[102];
vector<queue<int>> will;
int check[101];
int remain;

const int INF = -1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, ret = 0;
    cin >> n >> k;
    remain = n;
    for (int i = 0; i < k; i++)
    {
        use.push_back(0);
        cin >> use[i];
        temp[use[i]].push_back(i);
    }
    for (int i = 1; i <= k; i++)
    {
        if (temp[i].size())
        {
            queue<int> q;
            for (auto x : temp[i])
            {
                q.push(x);
            }
            q.push(INF);
            will.push_back(q);
        }
    }

    for (int i = 0; i < k; i++)
    {

        for (auto x : will)
            cout << x.front() << " ";
        cout << endl;

        int j = 0;
        for (auto x : will)
        {
            if (!x.empty() && x.front() == i)
            {
                cout << x.front() << endl;
                will[j].pop();

                if (!check[j] && remain > 0)
                    remain--, check[j] = true;

                else
                {
                    ret++;
                    int maximum = 0, index;

                    int k = 0;
                    for (auto x : will)
                    {
                        if (check[k])
                        {
                            if (maximum < x.front())
                                maximum = x.front(), index = k;
                        }
                        check[k] = false;
                    }
                    check[j] = true;
                }
            }
            j++;
        }
    }
    cout << ret;
    return 0;
}