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

int t, k;
int file[500];
int price[501]; //file 누적합
int cache[500][500]; //누적 비용

int sumPrice(int s, int e){
    int& ret = cache[s][e];
    if(ret != -1) return ret;

    if(s == e) return ret = 0;
    if(s+1 == e) return ret = file[s] + file[e];

    ret = 987654321;
    for(int i=s; i<e; i++){
        ret = min(ret, sumPrice(s,i)+sumPrice(i+1,e));
    }
    //cout<< s << " " << e << " " << ret + price[e+1] - price[s] << endl;
    return ret = ret + price[e+1] - price[s];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>t;
    while(t--){
        cin>>k;
        memset(cache, -1, sizeof(cache));
        for(int i=0;i<k;i++){
            cin>>file[i];
            price[i+1] = file[i] + price[i];
        }
        cout<<sumPrice(0,k-1)<<"\n";
    }
    return 0;
}