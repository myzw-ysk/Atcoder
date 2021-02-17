#include <bits/stdc++.h>
using namespace std;
 
int main(){
int A;
int B;
string S;
string T;
string U;
 cin >> S >> T;
 cin >> A >> B;
 cin >> U;
 if(U==S)cout << A-1 << " " << B << endl;
 else{cout << A << " " << B-1 << endl;}
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
string S;
 cin >> S;
for(i=0;i<S.length();i++){
    cout << 'x';
}
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
int j;
int N;
int count = 0;
cin >> N;
int A[N];
for(i=0;i<N;i++)cin >> A[i];
sort(A,A+N);
for(i=0;i<N-1;i++){
     if(A[i]==A[i+1]){
         count++;
         break;
     }
 }
if(count>0)cout << "NO" << endl;
else{cout << "YES"<< endl;}
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int K;
 int i;
 int tmp=0;
 double tmpval;
 cin >> N >> K;
 int p[N];
 int sum[N+1];
 sum[0]=0;
for(i=0;i<N;i++){
    cin >> p[i];
    sum[i+1]=sum[i]+p[i];
}
for(i=K;i<N+1;++i){
if(sum[i]-sum[i-K]>tmp)tmp=sum[i]-sum[i-K];
   }
tmpval = (tmp + K)/2.0;
 cout << setprecision(11) << tmpval << endl;
 }


//多分DPだなぁって思ったが場合分けで突っ張ってしまった…(がK=3がしんどすぎる)
//最後のしんどいあたりだけでもDPで書いてしまうのが正解だったかも
//構造を落ち着いてとらえれば十分に行けたけど…DPしってる人は即通せることをかんがえるとなぁ


#include <bits/stdc++.h>
using namespace std;
 
int main(){
 string N;
 int K;
 int i;
 cin >> N >> K;
 long long int ans = 0;
 if(K==1){
     ans = (N.length()-1)*9 + (N[0]-'0');
 }
else if(K==2){
    ans = ((N.length()-1)*(N.length()-2)*81/2);
    ans += (N[0]-'0'-1)*(N.length()-1)*9;
    int find = 0;
    for(i=1;i<N.length();i++){
        if(N[i]-'0'>0){
            find=i;
            break;
        }
    }
    if(find>0)ans += (N.length()-find-1)*9+(N[find]-'0');
}
else if(K==3){
    ans = ((N.length()-1)*(N.length()-2)*(N.length()-3)*243/2);
    ans += (N[0]-'0'-1)*((N.length()-1)*(N.length()-2)*81/2);
    int find1=0;
    int find2=0;
    for(i=1;i<N.length();i++){
        if(find1==0 && N[i]-'0'>0)find1=i;
        else if(find1>0 && N[i]-'0'){
            find2=i;
            break;
        }}
    if(find1>0){
        ans+=(N.length()-find1-1)*(N.length()-find1-2)*81/2;
        ans+=(N[find1]-'0'-1)*(N.length()-find1-1)*9;
        if(find2>0)ans+=(N.length()-find2-1)*9+(N[find2]-'0');
}}
cout << ans << endl;
}


//二項係数の計算だけでなくもうひとひねりあるのがこの問題のネック
//Nが6乗オーダーだから二重はダメ、ここで問題から二項係数の性質をひねり出す
//modで引き算するときはマイナスにならないようにmodをたすこと
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000005;
const int mod = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){
COMinit();
 int i;
 int r1;
 int r2;
 int c1;
 int c2;
 long long int ans = 0;
 cin >> r1 >> c1 >> r2 >> c2;
 for(i=r1;i<r2+1;i++){
         ans += COM(i+c2+1,c2)+(mod-COM(i+c1,c1-1));
         ans %= mod;
 }
cout << ans << endl;
}