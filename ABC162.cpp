#include<bits/stdc++.h>
using namespace std;
int main(){
string S;
cin >> S;
int i;
int flag=0;
for(i=0;i<3;i++)if(S[i]=='7')flag++;
if(flag>0)cout << "Yes" << endl;
else cout << "No" << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int N;
    long long int i;
    long long int sum=0;
    cin >> N;
    for(i=1;i<N+1;i++)if((i%3 != 0) && (i%5 != 0))sum+=i;
    cout << sum << endl;
}

#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
 int tmp;
 int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}

int main(){
    int K;
    cin >> K;
    int i,j,k,l,m;
    int ans =0;
    for(i=1;i<K+1;i++){
        for(j=1;j<K+1;j++){
            l=gcd(i,j);
            for(k=1;k<K+1;k++){
                m=gcd(k,l);
                ans += m;
            }
        }
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;

long long int r[4005];
long long int g[4005];
long long int b[4005];

int main(){
    int N;
    int i,j;
    string S;
    cin >> N;
    cin >> S;
    long long int count=0;
    long long int ans=0;
    if(S[N-1]=='B')b[N-1]=1;
    if(S[N-1]=='G')g[N-1]=1;
    if(S[N-1]=='R')r[N-1]=1;
    for(i=1;i<N;i++){
        if(S[N-1-i]=='B')b[N-1-i]=b[N-i]+1;
        else b[N-1-i]=b[N-i];
        if(S[N-1-i]=='G')g[N-1-i]=g[N-i]+1;
        else g[N-1-i]=g[N-i];
        if(S[N-1-i]=='R')r[N-1-i]=r[N-i]+1;
        else r[N-1-i]=r[N-i];
    }
    for(i=0;i<N-2;i++){
        for(j=i+1;j<N-1;j++){
            if(S[j]!=S[i]){
            if(S[i]!='R'&&S[j]!='R') ans += r[j];
            if(S[i]!='G'&&S[j]!='G') ans += g[j];
            if(S[i]!='B'&&S[j]!='B') ans += b[j];
            if(2*j-i<N)if(S[2*j-i]!=S[i] && S[2*j-i]!=S[j])count++;
        }}
    }
cout << ans-count << endl;
}

//整数問題、やはり落ち着いて本質を考察する時間が欲しいよな
//まずはそれぞれの約数を尻から探していくのが一番
//3乗オーダーじゃなくすためにはあとは
//逐一もとめるところから、条件を満たすものを探していくという視点の
//変換はよく使いがち

#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;

long long int modpow(long long int x,long long int n){
    long long int res=1;
    for(; n>0; n>>=1) {
        if (n&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

long long int num[100005];
int main(){
    long long int N,K;
    cin >> N >> K;
    long long int i,j;
    long long int ans=0;
    for(i=K;i>0;i--){
        num[i]=modpow(ceil(K/i),N);
        for(j=2;j<=ceil(K/i);j++){
            num[i] += (mod - num[i*j]);
            num[i] %= mod;
        }
        ans += num[i]*i;
        ans %= mod;
    }
    cout << ans << endl;
}


//DPは結局なんだかんだ時間がかかるからそれまでをはやときしないと
//実装できない…

#include<bits/stdc++.h>
using namespace std;

long long int dp[200005][3];
int main(){
int N;
cin >> N;
long long int a[N];
int i,j;
for(i=0;i<N;i++)cin >> a[i];
if(N%2==0){
    dp[0][0]=a[0];
    dp[1][1]=a[1];
    for(i=2;i<N;i+=2){
        for(j=0;j<2;j++){
            dp[i][j]=dp[i-2][j]+a[i];
            dp[i+1][j]=dp[i-1][j]+a[i+1];
        }
        dp[i+1][1]=max(dp[i-2][0]+a[i+1],dp[i+1][1]);
    }
    long long int ans=max(dp[N-2][0],dp[N-1][1]);
    cout << ans << endl;
}
else{
    dp[0][0]=a[0];
    dp[1][1]=a[1];
    for(i=2;i<N;i+=2){
        for(j=0;j<3;j++){
            dp[i][j]=dp[i-2][j]+a[i];
            dp[i+1][j]=dp[i-1][j]+a[i+1];
        }
        dp[i+1][1]=max(dp[i-2][0]+a[i+1],dp[i+1][1]);
        if(i>=4)dp[i][2]=max(max(dp[i-4][0]+a[i],dp[i-3][1]+a[i]),dp[i][2]);
    }
    long long int ans=max(max(dp[N-3][0],dp[N-2][1]),dp[N-1][2]);
    cout << ans << endl;    
}
}