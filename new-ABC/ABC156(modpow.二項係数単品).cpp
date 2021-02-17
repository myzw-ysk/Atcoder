#include <bits/stdc++.h>
using namespace std;
 
int main(){
int N;
int R;
cin >> N >> R;
 if(N>=10)cout << R << endl;
 else{cout << R+(100*(10-N)) << endl;}
}


#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i=0;
int N;
int K;
cin >> N >> K;
while(N!=0){
    N/=K;
    i++;
}
cout << i << endl;
}

//整数値限定だから平均とは限らない、100までであることを考えて全探索が正解
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int i;
 int j;
 cin >> N;
 int p[N];
for(i=0;i<N;i++)cin >> p[i];
 int tmp;
 int tmpsum = 100*100*10000;
 int sum;
for(i=1;i<101;++i){
 sum = 0;
 for(j=0;j<N;j++)sum += (p[j]-i)*(p[j]-i);
 if(sum<tmpsum){
     tmp=i;
     tmpsum = sum;
}}
 cout << tmpsum << endl;
}



#include <bits/stdc++.h>
using namespace std;

const long mod = 1e9+7;

long modpow(long a, long b){
	long res = 1;
	while (b > 0){
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

long comb(long a,long b){
	if(a<=0 || b<=0)return 1;
	long x = 1, y = 1;
	for (int i = 1; i <= b; i++){
		x = x * (a - i + 1) % mod;
		y = y * i % mod;
  }
  return x * modpow(y, mod - 2) % mod;
}

int main(){
	long N, A, B;
	cin >> N >> A >> B;
	long ans = modpow(2, N);
	ans--;
	ans += mod - comb(N, A);
	ans %=mod;
	ans += mod - comb(N, B);
	ans %= mod;
	cout << ans << endl;
}


//まずでかい場合を除外して、次にある特定の個数の場合を考えて…
//といった感じに順番に詰めていく
#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const int MAX = 4000005;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int main(){
	long long int n,k;
	cin >> n >> k;
	COMinit();
	if(k>=n-1){
		cout << COM(n+n-1,n);
	}
	else{
		long long int ans=1;
		for(int i=1;i<=k;i++){
			ans+= (COM(n,i)*COM(n-1,i)%mod);
			ans %= mod;
		}
		cout << ans;
	}
}