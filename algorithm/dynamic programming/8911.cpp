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

int n;
int x, y;
int Xmax, Ymax;
int Xmin, Ymin;
int dir = 0;

int main(){
    cin >> n;
    string tmp;
    while(n--){
        cin >> tmp;
        for(int i=0;i<tmp.length();i++){
            char& ret = tmp[i];
            if(ret=='L') dir = (dir+1)%4;
            else if(ret=='R') dir = (dir+3)%4;
            else if(ret=='F') {
                switch(dir){
                    case 0: y ++; break;
                    case 1: x ++; break;
                    case 2: y --; break;
                    case 3: x --; break;
                }
                Xmax = max(x, Xmax);
                Ymax = max(y, Ymax);
                Xmin = min(x, Xmin);
                Ymin = min(y, Ymin);
            }
            else {
                switch(dir){
                    case 0: y --; break;
                    case 1: x --; break;
                    case 2: y ++; break;
                    case 3: x ++; break;
                }
                Xmax = max(x, Xmax);
                Ymax = max(y, Ymax);
                Xmin = min(x, Xmin);
                Ymin = min(y, Ymin);
            }
            //cout<<x<<" "<<y<<endl;
        }
        cout<< abs(Xmax-Xmin) * abs(Ymax-Ymin) <<"\n";
        x=0, y=0, Xmax=0, Xmin=0, Ymax=0, Ymin=0;
    }
    return 0;
}