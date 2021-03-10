//i色出ているときにi+1色目までの期待値を考えれば自明。
//分割して考えましょう。

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double ans=0;
    for(int i=1;i<n;i++){
        ans += ((double)(n)/(double)(i));
    }
    cout << fixed << setprecision(16);
    cout << ans;
}