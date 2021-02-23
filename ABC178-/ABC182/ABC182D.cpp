#include <bits/stdc++.h>
using namespace std;

long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    long long int ans = 0;
    long long int tmp = 0;
    long long int peak = 0;
    long long int now = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1] = s[i] + a[i];
        tmp += a[i];
        peak = max(peak,tmp); 
        ans = max(ans,now+peak);
        now += s[i+1];
    }
    cout << ans;
}