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

string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int solution(string s)
{
    vector<pair<int, int>> v; // index, 숫자
    for (int i = 0; i < 10; i++)
    {
        int j = 0;
        while (s.find(nums[i], j) != std::string::npos)
        {
            v.push_back({s.find(nums[i], j), i});
            j = s.find(nums[i], j) + 1;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            v.push_back({i, int(s[i] - '0')});
    }
    sort(v.begin(), v.end());
    string answer = "";
    for (auto x : v)
    {
        answer += char('0' + x.second);
    }
    return stoi(answer);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << solution("2three45sixseven");
    return 0;
}