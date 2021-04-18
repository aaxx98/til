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

int solution(vector<int> money)
{
    int answer = 0;
    int N = money.size();
    int dp[1000001][2];
    dp[0][0] = money[0];
    dp[0][1] = 0;
    dp[1][0] = money[1];
    dp[1][1] = money[0];
    for (int i = 2; i < N - 1; i++)
    {
        dp[i][0] = dp[i - 1][1] + money[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    answer = max(dp[N - 2][0], dp[N - 2][1]);

    dp[1][0] = money[1];
    dp[1][1] = 0;
    dp[2][0] = money[2];
    dp[2][1] = money[1];
    for (int i = 3; i < N; i++)
    {
        dp[i][0] = dp[i - 1][1] + money[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    answer = max(answer, dp[N - 1][0]);
    answer = max(answer, dp[N - 1][1]);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a = {20, 21, 2};
    cout << " ,,," << endl;
    cout << solution(a) << endl;
    return 0;
}