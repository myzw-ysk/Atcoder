#A
だぶるくおがstring
シングルくおだとchar

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int K;
 int X;
 cin >> K >> X;
 if(500*K>=X){cout << "Yes" << endl;}
 if(500*K<X){cout << "No" << endl;}
  return 0;
}

#B
#include <bits/stdc++.h>
using namespace std;
 
int main(){
int N;
string S;
 cin >> N;
 cin >> S;
int i;
int count = 0;
for(i=0;i<N-2;i++){
    if(S[i]=='A'){
        if(S[i+1]=='B'){
            if(S[i+2]=='C'){
                count++;
            }
        }
    }
}
cout << count << endl;
  return 0;
}

#C

next_permutation(v.begin(), v.end())
これで順列の全部あげるやつができる


#include <bits/stdc++.h>
using namespace std;
 
int kaizyo(int n){
    if(n>0)return n*kaizyo(n-1);
    if(n==0)return 1;
}

int main(){
 int N;
 cin >> N;
 int p[N];
 int q[N];
 int i;
 for(i=0;i<N;++i){
   cin >> p[i];}
 for(i=0;i<N;++i){
   cin >> q[i];}
int pcount = 0;
int qcount = 0;
 for(i=0;i<N;++i){
  pcount += (p[i]-1)*kaizyo(N-i-1);
  qcount += (q[i]-1)*kaizyo(N-i-1);
  for(int j=0;j<N;j++){
      if(p[j]>p[i])p[j]--;
      if(q[j]>q[i])q[j]--;
  }
 }
 cout << abs(pcount-qcount) << endl;
}

#E
#逆からかえた法がはやいパターン
これだとコンビネーション計算まにあわないよ！151をみるとよい。
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int combination(long long int n,long long int r)
{
    if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return ((combination(n - 1, r - 1) + combination(n - 1, r))%mod);
}

long long int dob(long long int n){
    if(n==0)return (1);
    else{return (2*dob(n-1)%mod);}
}

int main(){
 long long int N;
 cin >> N;
 int c[N];
 int i;
 for(i=0;i<N;++i){
   cin >> c[i];}
long long int count = 0;
 for(i=0;i<N;++i){
  count += ((c[i]*(N-i)*dob(N-i-1))%mod);
  count %= mod;
  }
 cout << ((count*dob(N))%mod) << endl;
return 0;
}

#D
★いくつかの簡単な条件で分割して判定する
★今回の場合はakの倍数かとakの2で割れる回数
条件の整数問題的な吟味のみがキモの問題でした
最小公倍数最大公約数は標準らいぶらりにある


DとEは整数問題をさばく能力でしかない、純粋に考察力が落ちている…