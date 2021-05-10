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
vector<int> number;
int N = 0;
bool primenum(int num)
{
    int divisor = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            divisor++;
    }
    if (divisor == 2)
        return true;
    return false;
}
void sum(int n, int idx, int total)
{
    if (n == 3)
    {
        cout << total << endl;
        if (primenum(total))
            N++;
        return;
    }

    for (int i = idx + 1; i < number.size(); i++)
        sum(n + 1, i, number[i] + total);
}

int solution(vector<int> nums)
{
    number = nums;
    for (int i = 0; i < number.size(); i++)
        sum(1, i, number[i]);

    return N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v = {1, 2, 3, 4};
    solution(v);
    return 0;
}