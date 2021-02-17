#include <bits/stdc++.h>
using namespace std;

long long int mx[2],my[2];
int main(){
    int n;
    cin >> n;
    long long int x[n],y[n];
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    mx[0]=x[0]-y[0]; my[0]=x[0]-y[0];
    mx[1]=x[0]+y[0]; my[1]=x[0]+y[0];
    for(int i=1;i<n;i++){
        mx[0]=max(mx[0],x[i]-y[i]);
        mx[1]=max(mx[1],x[i]+y[i]);
        my[0]=min(my[0],x[i]-y[i]);
        my[1]=min(my[1],x[i]+y[i]);
    }
    cout << max(mx[0]-my[0],mx[1]-my[1]);
}

// https://naoyat.hatenablog.jp/entry/k-dimension-manhattan-distance