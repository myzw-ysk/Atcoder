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
 int C;
 cin >> A >> B >> C;
 if(A+B+C>21)cout << "bust" << endl;
  else cout << "win" << endl;
 return 0;
}

B

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
 int N = txt.length();
  int n = N/2;
  int i;
  char c;
  char d;
  int t = 0;
  for(i=0;i<n;i++){
   c = txt[i];
   d = txt[N-1-i];
   if(c!=d)t++;}
  cout << t << endl; 
  return 0;
}

D

#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<iterator>
#include<cmath>
#include<stdio.h>

using namespace std;

int main(){
int64_t N;
 cin >> N;
 int64_t a[N];
 int64_t sum = 0;
 int i;
 int j;
 int64_t bi = 1;
 int mod = 1e9 +7;
 for(i=0;i<N;++i){
     cin >> a[i];
   }
 for(i=0;i<61;++i){
    int64_t count = 0;
  for(j=0;j<N;++j){
    count += (a[j] % 2);
    a[j] /= 2;}
    sum = (sum + (((count * (N - count))%mod) * bi)%mod) %mod;
   bi = (bi * 2) %mod;
   }
  cout << sum%mod  << endl; 
  return 0;
}

#少しでも10^9を超える部分が出る計算をするときはint64_tをしましょう。



#C

#include <bits/stdc++.h>
using namespace std;
 
int N;
int A[20];
int x[20][20];
int y[20][20];
 
int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}
 
void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        for(int j = 1; j <= A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    int ans = 0;
    for(int bits = 1; bits < (1 << N); bits++) {
        bool ok = true;
        for(int i = 1; i <= N; i++) {
            if(!(bits & (1 << (i-1)))) continue;
            for(int j = 1; j <= A[i]; j++) {
                if(((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) ok = false;
            }
        }
        if(ok) ans = max(ans, counter(bits));
    }
    cout << ans << endl;
    return;
}
 
int main() {
    solve();
    return 0;
}