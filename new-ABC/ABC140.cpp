#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
 
using namespace std;
 
int main(){
 int N;
 cin >> N;
 cout << N*N*N << endl;
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
 cin >> N;
 int a[N];
 int b[N];
 int c[N-1];
 int i;
 for(i=0;i<N;++i){
     cin >> a[i];
   }
 for(i=0;i<N;++i){
     cin >> b[i];
   }
 for(i=0;i<N-1;++i){
     cin >> c[i];
   }
  int sum = 0;
 for(i=0;i<N;++i){
   sum += b[a[i]-1];
   if(i>0){
    if(a[i-1] == a[i]-1){
       sum += c[a[i-1]-1];
       }}
 }
        cout << sum << endl;
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
 cin >> N;
 int a[N];
 int b[N-1];
 int i;
 int sum = 0;
 for(i=0;i<N-1;++i){
     cin >> b[i];
   }
 if(N==2)cout << b[0]*2 << endl;
 else{
  sum += b[0];
  for(i=1;i<N-1;++i){
   sum += min(b[i-1],b[i]);}
  sum += b[N-2];
  cout << sum << endl;
 }
 return 0;
}

//D
//やることはしんぷるだけどかくのは大変
#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K;
  string S;
  cin >> N >> K;
  cin >> S;
  int rev=0;
  for(int i=1;i<N;i++)if(S[i-1]!=S[i])rev++;
  cout << N-1+min(0,-rev+K*2) << endl;
}

#いー
いやあ、これはなにいってんのかわからん。
ミソとしては最大値がPiになる個数の和という表現に持っていきたいんだろうけど
そのインデックスの作り方が理解を超越している
インデックスをうまく活用して計算量を減らすっていうのは
計算まにあわん、みたいなのの基本戦略にはなりそう。

#えふ
まあ察していた通り黄構造、むり～。
そーとして、気に割り当てていく感じ。

#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>

using namespace std;


int main(){
 int N;
 cin >> N;
 int p[N];
 int i;
 int top;
 int sec;
 int sum = 0;
 for(i=0;i<N;++i){
     cin >> p[i];
   }
 int L;
 int R;
 for(L=0;L<N-1;++L){
  for(R=L+1;R<N;++R){
    if(R==L+1){
     top = max(p[L],p[R]);
     sec = min(p[L],p[R]);
     sum += sec;
    }
    else if(sec==N-1){
        sum += (N-1)*(N-L-(R-1));
        break;
    }
    else{
     if(p[R] > top){
      sec = top;
      top = p[R];   
     }
     else if(p[R] > sec){
      sec = p[R];
     }
     sum += sec;
    }
    }
  }
  cout << sum << endl;
 return 0;
}
