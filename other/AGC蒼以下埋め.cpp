///AGC43-A
#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
char c[105][105];

int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j];
        }
    }
    if(c[0][0]=='#')dp[0][0]=1;
    for(int i=0;i<h;i++){
        if(i>0){
            if(c[i-1][0]=='.' && c[i][0]=='#')dp[i][0]=dp[i-1][0]+1;
            else dp[i][0]=dp[i-1][0];
        }
        for(int j=0;j<w-1;j++){
            if(i==0){
                if(c[i][j]=='.' && c[i][j+1]=='#')dp[i][j+1]=dp[i][j]+1;
                else dp[i][j+1]=dp[i][j];
            }
            else{
                if(c[i][j+1]=='.')dp[i][j+1]=min(dp[i][j],dp[i-1][j+1]);
                else dp[i][j+1]=min(dp[i][j]+(c[i][j]=='.'),dp[i-1][j+1]+(c[i-1][j+1]=='.'));
            }
        }
    }
    cout << dp[h-1][w-1] << endl;    
}
//AGC41-B
//考察のポイント:上位Pは確実に入れる
//それ以外が入れるのはP-1個の下に滑り込める場合だ
//じゃあどうやったら滑り込めるか？それはP-1個に投票したうえでほかのに投票したところで追い抜かれないやつだ

#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
    int n,m,v,p;
    cin >> n >> m >> v >> p;
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int ans=p;
    long long int s=a[n-p+1];
    for(int i=n-p;i>0;i--) {
  	    if (a[i]+m<a[n-p+1])break;
  	    s+=a[i];
  	    int t=v-(p+i-2);//横の投げていい票
  	    if (t<=0||(long long)(a[i]+m)*(n-p-i+2)-s>=(long long)m*t) ans++;//右の定式化がむずい
  	    else break;
  }
    cout << ans << endl;
}
