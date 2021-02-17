#include <bits/stdc++.h>
using namespace std;
 
int main(){
int A;
int B;
 cin >> A >> B;
 if(A>=13)cout<< B << endl;
 else if(A>=6)cout << B/2 << endl;
 else{cout << 0 << endl;}
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
int r;
int D;
int x[11];
 cin >> r >> D >> x[0];
for(i=1;i<11;i++){
  x[i]=r*x[i-1]-D;
  cout << x[i] << endl;
}
}

//0のケースをもらしたのが痛い、確認してな

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
int N;
int M;
cin >> N >> M;
int L[M];
int R[M];
for(i=0;i<M;i++)cin >> L[i] >> R[i];
int Max=L[0];
int Min=R[0];
for(i=1;i<M;i++){
  Min=min(Min,R[i]);
  Max=max(Max,L[i]);}
  if(Min>=Max)cout << Min-Max+1 << endl;
  else{cout << 0 <<endl;}
}

//何回も同じことをやるのを避けるっていう考え方が大事、そのために今回は最大でカードの入れ替えをN回しかしないためには
//どうするかという切り口でかえる

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i,j;
int N;
int M;
cin >> N >> M;
int A,B,C;
priority_queue<int,vector<int>,greater<int>> q;
for(i=0;i<N;i++){
  cin >> A;
  q.push(A);}
for(i=0;i<M;i++){
  cin >> B >> C;
  for(j=0;j<B;++j){
    if(C>q.top()){
      q.pop();
      q.push(C);}
    else if(C<=q.top())break;
  }}
 long long int count = 0;
 while(!q.empty()){
    count += q.top();
    q.pop();
 }
 cout << count << endl;
  return 0;
}
//これだと最悪計算時間がNMになってしまってダメ

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i,j;
int N;
int M;
cin >> N >> M;
int A,B,C;
priority_queue<int> q;
pair<int,int> CB[M];
for(i=0;i<N;i++){
  cin >> A;
  q.push(A);}
for(i=0;i<M;i++){
  cin >> B >> C;
  CB[i]=make_pair(C,B);}
sort(CB,CB+M);
int count = 0;
for(j=M-1;j>=0;j--){
  tie(C,B)=CB[j];
  while(B!=0){
    q.push(C);
    B--;
    count++;
    if(count>=N)break;
  }
  if(count>=N)break;
}
long long int ans = 0;
for(i=0;i<N;i++){
    ans += q.top();
    q.pop();
 }
 cout << ans << endl;
  return 0;
}


//XとYが独立でその組み合わせをもとめるという見立てまでは悪くなかった
//その見立ての下で各XYでそれぞれどういう変化をするのか具体的な数字で扱って見抜くまでやらなきゃだめだった
//予想通り今回は二項係数ゲー
//というか、この手の和はわりと二項係数げーだな…
//Kこ選ぶのも結局ある組を選んだ時にほかのをどこに置くかに集約される、まさに類題解いたまんま
//そのぶんたされるってやつ

#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;
const int mod = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){

COMinit();

 long long int N;
 long long int M;
 long long int K;
 cin >> N >> M >> K;
int i,j;
long long int count = 0;
 for(i=1;i<N;i++){
     count+=(i*(M*((M*(((N-i)*COM(N*M-2,K-2))%mod))%mod)%mod))%mod;
     count %= mod;
 }
  for(i=1;i<M;i++){
     count+=(i*(N*((N*(((M-i)*COM(N*M-2,K-2))%mod))%mod)%mod))%mod;
     count %= mod;
 }
cout << count%mod << endl;
 }
}


//絶対値の和の最小を取るのは中央値
//奇数の場合は左側の値
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int sum=0;
  long long int tmp=0;
  long long int mid;
  vector <long long int> v;
  int q;
  cin >> q;
  long long int a,b,c;
  cin >> a >> b >> c;
  sum+=(b+c);
  v.push_back(b);
  tmp+=b;
  mid = b;
  for(int i=0;i<q-1;i++){
    cin >> a;
    if(a==1){
      cin >> b >> c;
      sum+=(b+c);
      v.insert(upper_bound(v.begin(),v.end(),b),b);
      if(mid>=b){
        if(v.size()%2==0)tmp -= mid;
        tmp += b;
        mid=v[(v.size()-1)/2];
      }
      else{
        if(v.size()%2)tmp += v[(v.size()-1)/2];
        mid=v[(v.size()-1)/2];
      }
    }
    else cout << v[(v.size()-1)/2] <<" "<<((long long int)v.size()%2)*v[(v.size()-1)/2]+sum - 2*tmp << endl;
  }
}