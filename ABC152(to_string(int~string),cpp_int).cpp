#A

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int a;
 long long int b;
 cin >> a >> b;
 long long int c = 0;
 if(a>b){
     for(int i=0;i<a;i++){
         c += b;
         if(i!=a-1)c *= 10;
     }
 }
 else{
      for(int i=0;i<b;i++){
         c += a;
         if(i!=b-1)c *= 10;
     }    
 }

 cout << c << endl;
  return 0;
}

#C

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 cin >> N;
 int a[N];
 int i;
 for(i=0;i<N;++i){
   cin >> a[i];}
int count = 0;
int min = 1000000;
 for(i=0;i<N;++i){
    if(min>a[i]){count++;
    min = a[i];}
 }

     cout << count << endl;
 }


#D
#include <bits/stdc++.h>
using namespace std;

int c[10][10];
int main(){
    int n;
    cin >> n;
    int ans=0;
    string S;
    for(int i=1;i<=n;i++){
        S=to_string(i);
        c[S[0]-'0'][S[S.length()-1]-'0']++;
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            ans+=c[i][j]*c[j][i];
        }
    }
    cout << ans << endl;
}


//https://qiita.com/tubo28/items/fa8ee013390184b0ba18
//素因数だと丁寧にくまないと微妙にまにあわない(7乗オーダー)
//なので思い切って多売長整数

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;


cpp_int gcd(cpp_int x, cpp_int y){
 cpp_int tmp;
 cpp_int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}
int main(){
    cpp_int mod = 1000000007;
    int n;
    cin >> n;
    cpp_int a;
    cpp_int ans=0;
    cpp_int GCD=1;
    cpp_int LCM=1;
    cpp_int tmp;
    for(int i=0;i<n;i++){
        cin >> a;
        GCD=gcd(LCM,a);
        tmp=LCM/GCD;
        ans *= a/GCD % mod;
        ans += tmp;
        ans %= mod;
        LCM = a * tmp;
    }
    cout << ans << endl;
}

int64_t modpow(int64_t a, int64_t b){
	int64_t res = 1;
	while (b > 0){
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}