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

string str = "";

bool judge(char c)
{
    for (int i = 0; i < 3; i++)
    {
        if (str[i] == c && str[i + 3] == c && str[i + 6] == c)
            return true;
        if (str[i * 3] == c && str[i * 3 + 1] == c && str[i * 3 + 2] == c)
            return true;
    }

    if (str[4] == c)
    {
        if (str[0] == c && str[8] == c)
            return true;
        if (str[6] == c && str[2] == c)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    while (str != "end")
    {
        int x = 0, o = 0;
        for (int i = 0; i < 9; i++)
        {
            if (str[i] == 'X')
                x++;
            else if (str[i] == 'O')
                o++;
        }

        bool resultO = judge('O'), resultX = judge('X');

        if (resultO && !resultX && x == o)
            cout << "valid\n";
        else if (!resultO && resultX && x == o + 1)
            cout << "valid\n";
        else if (!resultO && !resultX && x == 5 && o == 4)
            cout << "valid\n";
        else
            cout << "invalid\n";

        cin >> str;
    }

    return 0;
}