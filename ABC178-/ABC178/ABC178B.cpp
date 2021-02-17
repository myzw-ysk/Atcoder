#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a[4];
    for(int i=0;i<4;i++){
        cin >> a[i];
    }
    long long int ans = -1e18;
    for(int i=0;i<2;i++){
        for(int j=2;j<4;j++)ans = max(ans,a[i]*a[j]);
    }
    if(ans<0 && (a[0]*a[1]<0 || a[2]*a[3]<0))ans=0;
    cout << ans;
}