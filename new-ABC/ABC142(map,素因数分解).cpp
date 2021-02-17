#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin >> N;
int odd = (N+1)/2;
cout << fixed << setprecision(16);
cout << (double)1.0*odd/(N*1.0) << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin >> N >> K;
    int h[N];
    int i;
    for(i=0;i<N;i++)cin >> h[i];
    int sum =0;
    for(i=0;i<N;i++)if(h[i]>=K)sum++;
    cout << sum << endl;
}

//mapで
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int a;
    int i;
    map<int,int>mp;
    for(i=0;i<N;i++){
        cin>>a;
        mp[a]=i+1;
    }
    for(i=1;i<N+1;i++)cout << mp[i] << endl;
}


//問題文はよく読みましょう
//素因数分解や素数テーブルは探せばちゃんとある
//今回は結局素数の約数の数だけみればよかった
//mapの使い方を理解したのはでかかった
#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int x, long long int y){
 long long int tmp;
 long long int r;
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

map< int64_t, int64_t > prime_factor(int64_t n) {
  map< int64_t, int64_t > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n]++;
  return ret;
}

int main(){
    int64_t A,B;
    cin >> A >> B;
    int64_t G= gcd(A,B);
    int64_t loop=0;
    for(auto p : prime_factor(G))loop++;
    cout << loop+1 << endl;
}

//未だに書き方がわからないものの1つ、bitDP
//鍵も結局ビットで表現できる⇐これが頭良かった。
//これのおかげでこれまでのかつ今回のがj|cの形で表せた。
//ビットを使った蛙飛びDPだった…
//もう一本のbitDPもりべんじしよう
#include <bits/stdc++.h>
using namespace std;

long long int dp[1005][(1<<12)+5];
int main(){
  int n,m;
  cin >> n >> m;//見栄を張らずにループで埋める
  for(int i=0;i<1005;i++)for(int j=0;j<(1<<12)+5;j++)dp[i][j]=1e18;
  dp[0][0]=0;
  long long int a;
  int b,c,d;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    c=0;
    for(int j=0;j<b;j++){
      cin >> d;
      c+=(1<<(d-1));
    }
    for(int j=0;j<(1<<n);j++){//最初に埋めた分を小さくできそうなら更新する
      if(dp[i+1][j]>dp[i][j])dp[i+1][j]=dp[i][j];
      if(dp[i+1][j|c]>dp[i][j]+a)dp[i+1][j|c]=dp[i][j]+a;
    }
  }
  if(dp[m][(1<<n)-1]==1e18)cout << -1 << endl;
  else cout << dp[m][(1<<n)-1] << endl;
}

