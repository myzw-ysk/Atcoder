//半分全列挙というらしい。
//結局2^40>2*2^20っていうのを利用して詰める

#include <bits/stdc++.h>
using namespace std;

long long int n,t;
long long int a[45];
long long int b[(1 << 21)];
long long int c[(1 << 21)];

int main(){
    cin >> n >> t;
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<(1 << n/2);i++){
        for(int j=0;j<n/2;j++){
            if(i & (1 << j))b[i]+=a[j];
        }
    }
    sort(b,b+(1 << n/2));
    for(int i=0;i<(1 << (n - n/2));i++){
        for(int j=0;j<n-n/2;j++){
            if(i & (1 << j))c[i]+=a[n/2+j];
        }
    }        
    sort(c,c+(1 << (n - n/2)));
    int x=(1 << (n-n/2))-1;
    long long int ans=0;
    for(int i=0;i<(1 << n/2);i++){
        while(b[i]+c[x]>t && x>0)x--;
        if(b[i]+c[x]==t){
            cout << t;
            return 0;
        }
        else if(b[i]+c[x]<t)ans=max(ans,b[i]+c[x]);
        else break;
    }
    cout << ans;
}