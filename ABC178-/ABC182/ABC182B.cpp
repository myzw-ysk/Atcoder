#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int ans=0;
    int solve;
    for(int i=2;i<=a[n-1];i++){
        int tmp = 0;
        for(int j=0;j<n;j++)if(a[j]%i==0)tmp++;
        if(tmp>=ans){
            ans=max(ans,tmp);
            solve=i;
        }
        if(ans==n){
            cout << i;
            return 0;
        }
    }
    cout << solve;
}