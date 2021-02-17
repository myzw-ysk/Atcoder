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

long modpow(long a, long b)
{
	long res = 1;
	while (b > 0)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

long comb(long a,long b)
{
	long x = 1, y = 1;
	for (int i = 1; i <= b; i++)
	{
		x = x * (a - i + 1) % mod;
		y = y * i % mod;
  }
  return x * modpow(y, mod - 2) % mod;
}

int main()
{
	long N, A, B;
	cin >> N >> A >> B;
	long ans = modpow(2, N);
	ans--;
	ans -= comb(N, A);
	ans -= comb(N, B);
	while (ans < 0) ans += mod;
	cout << ans << "\n";
}



