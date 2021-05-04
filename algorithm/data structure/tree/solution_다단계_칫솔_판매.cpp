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

map<string, int> to_index; //이름을 넣으면 index 반환
//referral은 부모
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(0);

    for (int i = 0; i < enroll.size(); i++)
    {
        to_index.insert(pair<string, int>(enroll[i], i));
    }
    to_index.insert(pair<string, int>("-", -1));

    for (int i = 0; i < seller.size(); i++)
    {
        int get = amount[i] * 100;
        int fee = get / 10;
        int now = to_index[seller[i]];
        while (true)
        {
            answer[now] += get - fee;
            if (fee == 0)
                break;
            get = fee;
            fee = get / 10;
            now = to_index[referral[now]];
            if (now == -1)
                break;
        }
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}