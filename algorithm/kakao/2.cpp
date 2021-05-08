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

int calc(pair<int, int> x, pair<int, int> y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int judge(vector<string> place)
{
    vector<pair<int, int>> person;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (place[i][j] == 'P')
                person.push_back({i, j});
        }
    }

    for (int i = 0; i < person.size(); i++)
    {
        for (int j = i + 1; j < person.size(); j++)
        {
            int dist = calc({person[i]}, {person[j]});
            if (dist > 2)
                continue;
            if (dist == 1)
                return 0;
            if (dist == 2)
            {
                if (person[i].first == person[j].first)
                {
                    if (person[i].second > person[j].second && place[person[i].first][person[j].second + 1] == 'O')
                        return 0;
                    if (person[i].second < person[j].second && place[person[i].first][person[i].second + 1] == 'O')
                        return 0;
                }
                else if (person[i].second == person[j].second)
                {
                    if (person[i].first > person[j].first && place[person[j].first + 1][person[i].second] == 'O')
                        return 0;
                    if (person[i].first < person[j].first && place[person[i].first + 1][person[i].second] == 'O')
                        return 0;
                }
                else
                {
                    if (place[person[i].first][person[j].second] == 'O' || place[person[j].first][person[i].second] == 'O')
                        return 0;
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for (auto place : places)
    {
        answer.push_back(judge(place));
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}