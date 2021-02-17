#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
#include<stdio.h>

using namespace std;

int main(){
 string txt;
 cin >> txt;
  if(txt=="Sunny")cout << "Cloudy" << endl;
  if(txt=="Cloudy")cout << "Rainy" << endl;
  if(txt=="Rainy")cout << "Sunny" << endl;
  return 0;
}


#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
#include<stdio.h>

using namespace std;

int main(){
string txt;
 cin >> txt;
 int n = txt.length();
 int i;
 char c;
 int t = 0;
 for(i=0;i<n;i++){
  c = txt[i];
  if((i%2==0 && c=='L') || (i%2==1 && c=='R')){
      cout << "No" << endl;
      t++;
      break;
  }}
  if(t==0)cout << "Yes" << endl;
  return 0;
}

#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
 
using namespace std;
 
int main(){
 int N;
 int K;
 int Q;
 cin >> N >> K >> Q;
 int A[Q];
 int B[N] = {};
 int i;
 for(i=0;i<Q;++i){
   cin >> A[i];}
 for(i=0;i<Q;++i){
 B[A[i]-1]++;
 }
 for(i=0;i<N;++i){
    if(K - Q + B[i] >0)cout << "Yes" << endl;
    else cout << "No" << endl;
 }
  return 0;
}


#でぃー
和を取るときはlonglongだようああああああああああああ
優先度付ききゅーってやつを使うらしい。
はやい話がヒープソートを実装してくれる空間らしい。
これはつかいこなせるとべんりだね(通常O(N)なのがO(logN)になる)
https://qiita.com/y_shindoh/items/17d9fa334a2cb8e74bfa
#昇順降順はこれでできる
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
#include <cstdio>
#include <queue>
 
using namespace std;
 
int main(){
 int N;
 int M;
 cin >> N >> M;
 int A[N];
 int i;
 int tmp;
priority_queue<int> q;
 for(i=0;i<N;++i){
   cin >> A[i];
   q.push(A[i]);}

for(i=0;i<M;++i){
    tmp = q.top()/2;
    q.pop();
    q.push(tmp);
}
 long long int count = 0;
 while(!q.empty()){
    count += q.top();
    q.pop();
 }
 cout << count << endl;
  return 0;
}
 
これだとO(NM)

//実はDPでも溶けるけどせっかくなので文字列処理の勉強をする
//解法1:Z-algorithm(最長共通接頭辞)
//それぞれのiについてSと S[i,|S|]の
//最長共通接頭辞の長さを記録した配列を線形時間で構築するアルゴリズム
//最長接頭辞:頭から数えて共通の部分の最大
//これを使えばたしかにいける
#include<bits/stdc++.h>
using namespace std;
vector< int > z_algorithm(const string &s) {
  vector< int > prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans=0;
  for(int i=0;i<n;i++){
    string t = s.substr(i);//部分文字列の作成
    auto lcp = z_algorithm(t);//テーブルの作成
    for(int j=0;j<t.size();j++){
      int l = min(lcp[j],j);//被っちゃだめだからminを取っている
      ans = max(l,ans);
    }
  }
 cout << ans; 
}

//Suffixarray(接頭辞配列)とローリングハッシュと最長回分は別の機会に…
//特にSuffixarrayは今回と同じように最長接頭辞(LCP)を扱うのに適している
//テンプレートはココ
//https://ei1333.github.io/luzhiled/