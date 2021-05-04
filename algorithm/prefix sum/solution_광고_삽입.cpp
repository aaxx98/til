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

int sum[360000];

int string_to_second(string str)
{
    int h, m, s;
    h = stoi(str.substr(0, 2));
    m = stoi(str.substr(3, 2));
    s = stoi(str.substr(6, 2));

    return h * 3600 + m * 60 + s;
}

string second_to_string(int sec)
{
    int h, m, s;
    s = sec % 60, sec /= 60;
    m = sec % 60, sec /= 60;
    h = sec;

    string str = "";
    if (h < 10)
        str += "0";
    str += to_string(h);
    str += ":";
    if (m < 10)
        str += "0";
    str += to_string(m);
    str += ":";
    if (s < 10)
        str += "0";
    str += to_string(s);

    return str;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    int len_all = string_to_second(play_time);
    int len_adv = string_to_second(adv_time);
    int start_time = 0;
    long long maxsum = 0, total = 0;
    queue<int> q;

    for (auto x : logs)
    {
        int start = string_to_second(x.substr(0, 8));
        int finish = string_to_second(x.substr(9, 8));
        for (int i = start; i < finish; i++)
            sum[i]++;
    }

    for (int i = 0; i < len_adv; i++)
    {
        total += sum[i];
        q.push(sum[i]);
    }
    maxsum = total;

    for (int i = len_adv; i < len_all; i++)
    {
        total += sum[i];
        total -= q.front();
        q.pop();
        q.push(sum[i]);
        if (total > maxsum)
        {
            start_time = i - len_adv + 1;
            maxsum = total;
        }
    }

    return second_to_string(start_time);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}