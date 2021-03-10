//何がコーナーケースになっているのかコードをよんで精査せよ。

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    if(m==0){cout << 1; return 0;}
    if(n==m){cout << 0; return 0;}
    int a[m];
    for(int i=0;i<m;i++)cin >> a[i];
    sort(a,a+m);
    int s[m+1];
    s[0]=a[0]-1;
    s[m]=n-a[m-1];
    int k=1e9;
    if(s[0]*s[m]>0)k=min(s[0],s[m]);
    else if(s[0]>0)k=s[0];
    else if(s[m]>0)k=s[m];
    for(int i=1;i<m;i++){
        s[i]=a[i]-a[i-1]-1;
        if(s[i]>0)k=min(k,s[i]);
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        ans+=s[i]/k+(s[i]%k!=0);
    }
    cout << ans;
}