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

vector<int> inorder, postorder;

//postorder구간:[a,b), inorder시작점: c, tree요소개수: n
void printPreOrder(int a, int b, int c, int n)
{
    const int N = n;

    if (n == 0)
        return;

    const int root = postorder[b - 1];
    cout << root << " ";
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin() - c;
    const int R = N - 1 - L;
    //cout << endl << L << " " << R << endl;
    printPreOrder(a, a + L, c, L);
    printPreOrder(a + L, a + N - 1, c + L + 1, R);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        inorder.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        postorder.push_back(tmp);
    }

    printPreOrder(0, n, 0, n);
    return 0;
}