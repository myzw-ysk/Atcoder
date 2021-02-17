#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << a*b << endl;
}

#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    cpp_int ans=1;
    int zero=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==0)zero++;
    }
    if(zero>0){
        cout << 0 << endl;
        return 0;
    }
    else{
    for(int i=0;i<n;i++){
        ans *= a[i];
        if(ans>1000000000000000000){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    long double a,b;
    cin >> a >> b;
    cout << (long long int)(1.0*a*b*1.0) << endl;
}
#include<bits/stdc++.h>
using namespace std;

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
    int64_t n;
    cin >> n;
    int64_t ans=0;
    int64_t tmp;
    int64_t e;
    for(auto p : prime_factor(n)){
        tmp=1;
        e=p.second;
        while(tmp<=e){
            e-=tmp;
            ans++;
            tmp++;
        }
    }
    cout << ans << endl;
}
//それぞれの真ん中がわかったら奇数ならそのまま差をとればいいけど
//偶数の場合は1/2刻みになるからそれぞれの中央値で考えなきゃならない
//だから真ん中の左右側両方を使う
//今回は真ん中をソートするだけで使えるんだからつかおうね…
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    if(n%2==1)cout << b[n/2]-a[n/2]+1 << endl;
    else cout << b[n/2]+b[n/2-1]-a[n/2]-a[n/2-1]+1 << endl;
}

//複雑に見えるけど結局やることは和についてみるナップザックだよね
//左側でどこまでみてるか、右側で和の管理
//上の組み合わせは鉄板の1つ！！！！！
#include<bits/stdc++.h>
using namespace std;
const long long int mod=998244353;
int a[3005];
long long int dp[3005][3005];

int main(){
    int n,s;
    cin >> n >> s;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<s;j++){
            dp[i+1][j] += 2*dp[i][j];//それだけを取るパターンと新しくきたのもとるパターン
            dp[i+1] %= mod;
            if(j+A[i]<=s){
                dp[i+1][j+a[i]] += dp[i][j];
                dp[i+1][j+a[i]] %= mod;
            }
        }
    }
    cout << dp[n][s] << endl;
}



//今回はダメな解法:FFT
//結局実質N*4096*log(4096)なので無理でした(かん)
//やはり10^8オーダーはきつい(ある程度でかいとTLE)
//畳み込みは畳み込み数回で決着がつくときげんていだなぁ…
//いらない部分は完全に切り捨てる、中途半端に残さないこと。
//FFTは2のべき乗次にしないといけない、塚使わない部分は0埋めする

#include<bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

const int sz=4096;//最大が3000だからこれくらいは必要になってしまう
const long long int mod=998244353;
void fft(vector<complex<long double>>&a,int inverse){
  int n=a.size();
  if(n==1)return;
  vector<complex<long double>>va,vb;
  for(int i=0;i<n/2;i++){
    va.push_back(a[2*i]);
    vb.push_back(a[2*i+1]);
  }
  fft(va,inverse);fft(vb,inverse);
  complex<long double>now=1,zeta=polar(1.0,inverse*2.0*acos(-1)/n);
  for(int i=0;i<n;i++){
    a[i]=va[i%(n/2)]+now*vb[i%(n/2)];
    now*=zeta;
  }
}

int main(){
    int n,s;
    cin >> n >> s;
    int A;
    vector<complex<long double>>a(sz,0);
    cin >> A;
    a[0]=2; 
    if(A<=s)a[A]=1;
    for(int i=1;i<n;i++){
        cin >> A;
        if(A<=s){
            vector<complex<long double>>b(sz,0);
            b[0]=2; b[A]=1;
            fft(a,1); fft(b,1);
            for(int i=0;i<sz;i++)a[i]=a[i]*b[i];
            fft(a,-1);
            for(int i=0;i<sz;i++){
                if(i<=s)a[i]=((long long int)round(a[i].real()/a.size()))%mod;
                else a[i]=0;
            }
        }
        else for(int i=0;i<=s;i++)a[i]=(((long long int)(a[i].real()*2))%mod);
    }
    cout << (long long int)a[s].real() << endl;
}
