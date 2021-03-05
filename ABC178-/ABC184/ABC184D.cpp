#include <bits/stdc++.h>
using namespace std;

double dp[105][105][105];

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    dp[a][b][c]=1;
    for(int i=a;i<100;i++){
        for(int j=b;j<100;j++){
            for(int k=c;k<100;k++){
                dp[i+1][j][k]+=((double)i/(double)(i+j+k))*dp[i][j][k];
                dp[i][j+1][k]+=((double)j/(double)(i+j+k))*dp[i][j][k];
                dp[i][j][k+1]+=((double)k/(double)(i+j+k))*dp[i][j][k];
            }
        }
    }
    double ans = 0; 
    for(int i=a;i<=100;i++){
        for(int j=b;j<=100;j++){
            for(int k=c;k<=100;k++){
                if(i==100 || j==100 || k==100)ans += (double)(i+j+k-a-b-c)*dp[i][j][k];
            }
        }
    }  
    cout << fixed << setprecision(16);
    cout << ans;
}