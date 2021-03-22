#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double x[n],y[n];
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    int ans = 0;
    double tmp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            tmp=(y[j]-y[i])/(x[j]-x[i]);
            if(tmp<=1.0 && tmp>=-1.0)ans++;
        }
    }
    cout << ans;
}