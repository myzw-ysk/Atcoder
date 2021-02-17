#a
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
 if((A+B)%2==0){
 cout << (A+B)/2 << endl;}
  else{
    cout << "IMPOSSIBLE" << endl;}
  return 0;
}



#b
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
 int count = 0;
 for(i=0;i<N;++i){
   cin >> p[i];}
 for(i=0;i<N;++i){
 if(p[i]!=i+1)count++;}
 if(count>2){
 cout << "NO" << endl;}
 else{
   cout << "YES" << endl;}
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
 int a[N+1] = {0};
 int b[N] = {0};
 int i;
 long long int sum = 0;
 for(i=0;i<N+1;++i){
     cin >> a[i];
   }
  for(i=0;i<N;++i){
     cin >> b[i];
   }
  for(i=N-1;i>-1;--i){
    if(a[i+1]>=b[i]){
      sum += b[i];}
    else{
      sum += a[i+1];
      if(a[i]<=b[i]-a[i+1]){
        sum += a[i];
        a[i] = 0;}
      else{
        sum += (b[i] - a[i+1]);
        a[i] -= (b[i] - a[i+1]);}
    }
  }
  cout << sum << endl;
  return 0;
}



#D
#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
long long int dp[100005][13];
int main(){
  string S;
  cin >> S;
  if(S[0]!='?')dp[0][(S[0]-'0')]++;
  else for(int k=0;k<10;k++)dp[0][k]++;
  for(int i=1;i<S.length();i++){
    for(int j=0;j<13;j++){
      if(S[i]!='?'){
        dp[i][((j*10)%13+(S[i]-'0')%13)%13]+=dp[i-1][j];
        dp[i][((j*10)%13+(S[i]-'0')%13)%13]%=mod;
      }
      else{
        for(int k=0;k<10;k++){
          dp[i][((j*10)%13+k%13)%13]+=dp[i-1][j];
          dp[i][((j*10)%13+k%13)%13]%=mod;
        }
      }
    }
  }
  cout << dp[S.length()-1][5] << endl;
}