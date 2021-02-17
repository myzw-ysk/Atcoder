#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
#include<stdio.h>

using namespace std;

int main(){
 int n = 0;
 char s[3];
 char t[3];
 scanf("%s", s);
 scanf("%s", t);
 int i;
 for(i=0;i<3;i++){
  if(s[i]==t[i])n++;
  }
  cout << n << endl;
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
 int A;
 int B;
 cin >> A >> B;
 int ans;
 if(B<=A)ans=1;
 else{
   ans = 2 + (B-A)/(A-1);
   if((B-A)%(A-1)==0)ans--;
   }
 if(B==1)ans=0;
 cout << ans << endl;
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
 int i;
 for(i=0;i<N;++i){
     cin >> a[i];
   }
  int tmp = 0;
  int best = 0;
 for(i=0;i<N-1;++i){
   if(a[i]>=a[i+1])tmp++;
    else{
        best = max(best,tmp);
        tmp = 0;
    }
 }
   cout << tmp << endl;
 }
 if(a[0]>=tmp){
   for(i=1;i<N;++i){
     cout << a[0] << endl;
   }}
  else if(hukusuu>0){
    for(i=1;i<N;++i){
    cout << tmp << endl;
    }}
   else{
    for(i=1;i<N;++i){
    if(i!=best){cout << tmp << endl;}
      else{
        int newtmp = 0;
        for(j=0;j<N;++j){
          if(j!=best)newtmp=max(newtmp,a[j]);}
        cout << newtmp << endl;
      }
    }
   } 
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
 long N;
 cin >> N;
 long long int ans;
 ans = ((N-1)*N)/2;
 cout << ans << endl;
 return 0;
}

//全組み合わせについてBFSorDFSがセオリー
//トポロジカルソートがキーワード
//向きアリ経路なしグラフについて今回みたいにやじるしのもとにくるものを順番にあげていく
#include<bits/stdc++.h>
using namespace std;
  int n;
  int a[1007][1007],t[1007],p[1007];
  queue<int>q[2];
  int main(){
    cin>>n;
    for(int i=1;i<=n;++i)for(int j=1;j<n;++j)cin>>a[i][j];
    for(int i=1;i<=n;++i)q[0].push(i);
    int now=1;
    for(int day=1,tot=n*(n-1)/2;day<=n*(n-1)/2;++day){//最大のすべての日まで調べる
      now^=1;
      while(!q[now].empty()){
        int x=q[now].front();
        q[now].pop();
        int y=a[x][++t[x]];
        if(p[y]==x){
          tot--;
          q[1-now].push(x);
          q[1-now].push(y);
          p[x]=p[y]=0;
        }
        else
          p[x]=y;
        }
      if(!tot){
        cout<<day<<endl;
          return 0;
      }
    }
    cout<<-1<<endl;
    return 0;
    }
