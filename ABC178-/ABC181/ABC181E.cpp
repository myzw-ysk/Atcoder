#include <bits/stdc++.h>
using namespace std;

long long int odd[100005];
long long int even[100005];

int main(){
    int n,m;
    cin >> n >> m;
    long long int h[n];
    for(int i=0;i<n;i++)cin >> h[i];
    sort(h,h+n);
    long long int w[m];
    for(int i=0;i<m;i++)cin >> w[i];
    sort(w,w+m);
    for(int i=0;i<n/2;i++){
        odd[i+1] = odd[i] + h[2*i+1] - h[2*i];
        even[i+1] = even[i] + h[2*i+2] - h[2*i+1]
    }
    int mushi = 0;
    long long int ans = 0;
    long long int tmp;
    //for(int i=0;i<m;i++){
    //    while(w[i]<h[mushi] && mushi < n)mushi++;
    //    tmp = min(odd[mushi/2]+even[mushi/2]+);
        ans = min(ans,tmp);
    }
    cout << ans;
}