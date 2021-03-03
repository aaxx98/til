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

int solution(int N, int number){
    vector<set<int>> arr(9);
    for(int i=1;i<=8;i++){
        int nnn = 0;
        int n = i;
        while(n--){
            nnn += N*pow(10, n);
        }
        if(nnn==number) return i;
        arr[i].insert(nnn);
    }
    for(int i=2;i<=8;i++){
        for(int j=1;j<i;j++){
            for(int x: arr[j]){
                for(int y: arr[i-j]){
                    if(y!=0) arr[i].insert(x/y);
                    arr[i].insert(x*y);
                    arr[i].insert(x+y);
                    arr[i].insert(x-y);
                }
            }
        }
        if(arr[i].find(number) != arr[i].end()) return i;
    }
    return -1;
}


int main(){
    cout << solution(5,12);
    cout <<solution(2,11);
    
    cout <<solution(6,6);
    return 0;
} 