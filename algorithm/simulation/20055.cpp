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
int belt[200], robot[200];
int n, k;
int cnt = 0;

int front = 0, rear;

void round()
{
    front = (front + 2 * n - 1) % (n * 2);
    rear = (rear + 2 * n - 1) % (n * 2);
    //cout << front << " " << rear << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rear = n - 1;
    for (int i = 0; i < 2 * n; i++)
        cin >> belt[i];

    int turn = 1;
    while (true)
    {
        //1.벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다. 내리는 위치에 있는 로봇은 내린다.
        robot[rear] = 0;
        round();
        robot[rear] = 0;
        //2.가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        //로봇이 이동하기 위해서는 로봇이 내리는 위치가 아니고, 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        for (int i = n - 1; i > 0; i--)
        {
            int pre = (front + i - 1) % (n * 2), now = (front + i) % (n * 2);
            if (robot[now] == 0 && robot[pre] && belt[now] > 0)
            {
                belt[now]--;
                if (belt[now] <= 0)
                    cnt++;
                robot[now] = 1;
                robot[pre] = 0;
            }
        }
        //3.올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        if (belt[front] > 0)
        {
            robot[front] = 1;
            belt[front]--;
            if (belt[front] <= 0)
                cnt++;
        }

        for (int i = 0; i < n * 2; i++)
        {
            int now = (front + i) % (n * 2);
            cout << robot[now] << " ";
        }
        cout << endl;
        for (int i = 0; i < n * 2; i++)
        {
            int now = (front + i) % (n * 2);
            cout << belt[now] << " ";
        }
        cout << endl;
        cout << endl;

        //4.내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
        if (cnt >= k)
            break;
        turn++;
    }
    cout << turn;
    return 0;
}