//累積和を使ったDPであることは自明
//それぞれの方向ごとに累積和を用意するのがミソ

#include <bits/stdc++.h>
using namespace std;

char s[2005][2005];
long long int dp[2005][2005];
long long int X[2005][2005];
long long int Y[2005][2005];
long long int Z[2005][2005];
const long long int mod = 1e9+7;

int main(){
    int h,w;
    cin >> h >> w;
    dp[0][0]=1;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> s[i][j];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                if(i>0){
                    Y[i][j] += Y[i-1][j] + dp[i-1][j];
                    Y[i][j] %= mod;
                }                
                if(j>0){
                    X[i][j] += X[i][j-1] + dp[i][j-1];
                    X[i][j] %= mod;
                }         
                if(i>0 && j>0){
                    Z[i][j] += Z[i-1][j-1] + dp[i-1][j-1];
                    Z[i][j] %= mod;
                }                
            }
            dp[i][j] += X[i][j] + Y[i][j] + Z[i][j];
            dp[i][j] %= mod;
        }
    }
    cout << dp[h-1][w-1];
}

