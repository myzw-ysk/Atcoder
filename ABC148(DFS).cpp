#A 数入力パターン
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int A;
 int B;
 cin >> A >> B;
 int C = A+B;
 if(C==4)C=2;
 if(C==5)C=1;
 cout << C << endl;
  return 0;
}


#B 文字入力パターン
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 cin >> N;
string S;
string T;
 cin >> S >> T;
  int i;
  char c;
  char d;
  for(i=0;i<N;i++){
   c = S[i];
   d = T[i];
   cout << c << d;} 
  return 0;
}

#C
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int A;
 long long int B;
 cin >> A >> B;
long long int C = A * B;
 long long int tmp;
 long long int r;
 if(A < B){
    tmp = A;
    A = B;
    B = tmp;
  }
  r = A % B;
  while(r!=0){
    A = B;
    B = r;
    r = A % B;
  }
  cout << C/B << endl;
  return 0;
}

 
#E
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int N;
 cin >> N;
 if(N%2==1)cout << 0 << endl;
 else if(N<10)cout << 0 << endl;
 else{
     long long int count = 0;
     int i;
     int j;
     long long int M;
     for(i=1;i<19;i++){
         N /= 10;
         count += N;
         M = N;
         j = 0; 
         while(M!=0){
             j++;
             M /= 5;
             if(M%2==1)count += (M/2 + 1);
             if(M%2==0)count += M/2;  
         }
     } 
     cout << count << endl;
 }
 return 0;
}

#D
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 cin >> N;
 int A[N];
 int i;
 for(i=0;i<N;++i){
   cin >> A[i];}
int count = 0;
int ser = 1;
 for(i=0;i<N;++i){
  if(A[i] != ser)count++;
  else if(A[i] == ser)ser++;
 }
 if(ser==1)cout << -1 << endl;
 else{
     cout << count << endl;
 }
}

#F
#深さ優先探索
#bits/stdc++.hにはたいがいのヘッダが組み込まれている
#ので今後はこれを使いたい
#https://img.atcoder.jp/abc148/editorial.pdf
#https://qiita.com/drken/items/4a7869c5e304883f539b
グラフ問題退治をかんがえると上のリンクがいい？


#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
vector<int> to[100005];
int n;
 
vector<int> dist;
void dfs(int v, int d=0, int p=-1) {
  dist[v] = d;
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u,d+1,v);
  }
}
vector<int> calcDist(int s) {
  dist = vector<int>(n);
  dfs(s);
  return dist;
}
 
int main() {
  cin >> n;
  int s, t;
  cin >> s >> t;
  --s; --t;
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
 
  vector<int> distS = calcDist(s);
  vector<int> distT = calcDist(t);
 
  int mx = 0;
  rep(i,n) {
    if (distS[i] < distT[i]) {
      mx = max(mx, distT[i]);
    }
  }
  int ans = mx-1;
  cout << ans << endl;
  return 0;
}