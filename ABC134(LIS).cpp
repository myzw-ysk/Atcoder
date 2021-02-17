#A

#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
 
using namespace std;
 
int main(){
 int r;
 cin >> r;
 cout << 3*r*r << endl;
  return 0;
}

#B
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
 int hito;
 if(N%(2*D+1)==0){hito = N/(2*D+1);}
  else{hito=(N/(2*D+1))+1;}
 cout << hito << endl;
  return 0;
}

#c


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
 int j;
 for(i=0;i<N;++i){
     cin >> a[i];
   }
  int tmp = 0;
  int best;
  int hukusuu=0;
 for(i=0;i<1;++i){
   for(j=1;j<N;++j){
     if(tmp < a[j]){
       tmp = a[j];
       best = j;
       hukusuu = 0;}
     else if(tmp == a[j]){
       hukusuu++;}}
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


#D

#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int main(){
  int n;
  cin >> n;
  int tmp;
  int ans;
  int count=0;
  for(int i=1;i<n+1;i++)cin >> a[i];
  for(int i=n;i>0;i--){
    tmp=i;
    ans=0;
    while(tmp<=n){
      ans+=b[tmp];
      tmp+=i;
    }
    if(ans%2!=a[i]){
      b[i]++;
      count++;
    }
  }
  cout << count << endl;
  for(int i=1;i<n+1;i++)if(b[i]>0)cout << i <<endl;
}


//LISだね
//広義だったらupper、狭義だったらlowerでいける
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=1e9;
    for(int i=0;i<n;i++){
        cin >> a;
        a *= (-1);
        *upper_bound(dp,dp+n,a)=a;
    }
    cout << lower_bound(dp,dp+n,1e9)-dp;
}