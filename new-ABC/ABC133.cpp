#A
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
 
using namespace std;
 
int main(){
 int N;
 int A;
 int B;
 cin >> N >> A >> B;
 cout << min(N*A,B) << endl;
  return 0;
}

#B
#stringstreamがなくても行列使えるよ
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>

using namespace std;

int main(){
 int N;
 int D;
 cin >> N >> D;
 int x[N][D];
 int i;
 int j;
 for(i=0;i<N;++i){
   for(j=0;j<D;++j){
     cin >> x[i][j];
   }}
  int count = 0;
  int sum = 0;
  int k;
 for(i=0;i<N;++i){
   for(j=i+1;j<N;++j){
     sum = 0;
     for(k=0;k<D;++k){
       sum += (x[i][k] - x[j][k])*(x[i][k] - x[j][k]);
     }
     if(abs(sqrt(sum)-(int)sqrt(sum)) == 0)count++;
   }
 }
  cout << count;
 return 0;
}


#C
#longを使うのがみそでした
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
 
using namespace std;
 
int main(){
 long int L;
 long int R;
 long int m = 2019;
 long int i,j;
 cin >> L >> R;
 if(R-L>= 2019)m=0;
else{for(i=L;i<=R;i++){
  for(j=i+1;j<=R;j++){
    m = min(m,((i*j)%2019));
  }}
 }
 cout << m << endl; 
}

#D 

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int i;
 cin >> N;
 int a[N];
 long long int odd=0;
 for(i=0;i<N;i++)cin >> a[i];
 for(i=0;i<(N-1)/2;i++){
   odd += a[2*i];
   odd -= a[2*i+1];
 }
 odd += a[N-1];
 for(i=0;i<(N-1)/2;i++){
   cout << odd << " " << 2*a[2*i]-odd << " ";
   odd -= 2*a[2*i];
   odd += 2*a[2*i+1];
   }
 cout << odd << endl;
 }

#E 
//DFSを特訓せよ。
//今回はそこのやつが使える色を吐いていく
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int mod = 1000000007;
vector<int> v[MAX];

long long int dfs(int now,int from,int color){
  int canuse;
  if(from==-1)canuse=color-1;
  else{canuse=color-2;}
  if(color<(int)v[now].size())return 0;
  else{
  long long int co_no_iro = 1;
	for (int i=0;i<(int)v[now].size();i++){
    if(v[now].at(i)==from)continue;
    else{
		co_no_iro *= canuse;
    canuse--;
    co_no_iro %= mod;
		}}
 	for (int i=0;i<(int)v[now].size();i++){
    if(v[now].at(i)==from)continue;
    else{
		co_no_iro *= dfs(v[now].at(i),now,color);
    co_no_iro %= mod;
		}}
  return co_no_iro;
	}
}
int main(){
  int N,K;
	cin >> N >> K;
  int a,b;
  long long int ans =0;
	for(int i=0;i<N-1;i++){
		cin >> a >> b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	ans = K * dfs(0,-1,K);
  ans %= mod;
	cout<< ans <<endl;
}
 //一番最初は区別するために-1