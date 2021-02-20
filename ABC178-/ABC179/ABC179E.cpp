#include <bits/stdc++.h>
using namespace std;

long long int memo[100005];
int main(){
    long long int n,m,x;
    cin >> n >> x >> m;
    map<long long int,int> mp;
    mp[x]=1;
    memo[1]=x;
    long long int i;
    for(i=1;i<n;i++){
        if(mp[(x*x)%m]!=0)break;
        else{
            x=(x*x)%m;
            mp[x]=i+1;
            memo[i+1]=memo[i]+x;
        }
    }
    if(i==n){
        cout << memo[n];
        return 0;
    }
    else{
        long long int loop = i - mp[(x*x)%m] + 1;
        long long int tail = mp[(x*x)%m] - 1;
        cout << ((n-tail)/loop)*(memo[i]-memo[tail]) 
        + memo[((n-tail)%loop)+tail];

    }
}

//デバッグの方針はおかしいと思うところを一つ一つ出力してみるのがきほんだよね・