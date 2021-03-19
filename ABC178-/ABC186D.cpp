#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int ans = 0;
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        ans += (2*(i+1) - 1 - n)*a[i];
    }
    ans += (n-1)*a[n-1];
    cout << ans;
}