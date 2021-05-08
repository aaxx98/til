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
#include <list>

using namespace std;
string solution(int n, int k, vector<string> cmd)
{
    list<pair<int, bool>> member;
    stack<int> deleted;

    std::list<pair<int, bool>>::iterator iter = member.begin();

    for (int i = 0; i < n; i++)
        member.push_back({i, true});

    for (int i = 0; i <= k; i++)
        iter++;

    for (auto com : cmd)
    {
        int t;
        cout << (*iter).first;
        switch (com[0])
        {
        case 'U':
            for (int i = 0; i < com[2]; i++)
            {
                iter--;
                if ((*iter).second == false)
                    i--;
            }
            break;
        case 'D':
            for (int i = 0; i < com[2]; i++)
            {
                iter++;
                if ((*iter).second == false)
                    i--;
            }
            break;
        case 'C':
            deleted.push((*iter).first);
            (*iter).second = false;

            for (std::list<pair<int, bool>>::iterator itr = member.end(); itr != member.begin(); --itr)
            {
                if ((*itr).second == true)
                {
                    t = (*itr).first;
                    break;
                }
            }
            if ((*iter).first == t)
                iter--;
            else
                iter++;
            break;
        case 'Z':
            t = deleted.top();
            for (std::list<pair<int, bool>>::iterator itr = member.begin(); itr != member.end(); ++itr)
            {
                if ((*itr).first == t)
                {
                    (*itr).second = true;
                }
            }
            /*
            for (auto x : member)
            {
                if (x.first == t)
                    x.second = true;
            }*/
            deleted.pop();
            break;

        default:
            break;
        }
    }
    string answer = "";
    for (auto x : member)
    {
        if (x.second == true)
            answer += 'O';
        else
            answer += 'X';
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> cmd = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"};
    vector<string> cmd2 = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"};
    cout << solution(8, 2, cmd) << endl;
    cout << solution(8, 2, cmd2) << endl;

    return 0;
}