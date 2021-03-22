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

list<int> person;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        person.push_back(i);
    }
    cout << "<";
    list<int>::iterator iter = person.begin();
    while (!person.empty())
    {
        for (int i = 0; i < k; i++)
        {
            if (iter == person.end())
                iter = person.begin();
            iter++;
        }
        iter--;
        if (person.size() > 1)
        {
            cout << *iter << ", ";
            iter = person.erase(iter);
        }
        else
        {
            cout << *iter << ">";
            break;
        }
    }
    return 0;
}