#include<bits/stdc++.h>
using namespace std;
int main(){
    char c;
    cin >> c;
    if(c-'a'>=0 && c-'a'<27)cout << "a" << endl;
    else cout << "A" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    sort(p,p+n);
    int ans=0;
    for(int i=0;i<k;i++)ans += p[i];
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    char c[100];
    int cou=0;
    while(n>0){
        c[cou]=('a'+(n+25)%26);
        if(n%26==0){n/=26; n-=1;}
        else n/=26;
        cou++;
    }
    for(int i=0;i<cou;i++)cout << c[cou-1-i];
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q,b,c;
    cin >> n;
    long long int sum=0;
    long long int a[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        mp[a[i]]++;
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> b >> c;
        sum += (c-b)*mp[b];
        mp[c]+=mp[b];
        mp[b]=0;
        cout << sum << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    int sum = a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i=0;i<n;i++)cout << (sum^a[i]) << " ";
}

#include<bits/stdc++.h>
using namespace std;

#define N 2000005
const long long int mod=1e9+7;
long long f[N],inv[N],p[N],ans=1;
long long int modpow(long long int x, long long int n){
    long res=1;
    for(; n>0; n>>=1) {
        if (n&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}
long long modinv(long long a) {
    return modpow(a, mod - 2);
}
long long int nCr(long long int n, long long int r){
    long res=1;
    for(long int i=0; i<r; ++i) res=res*(n-i)%mod;
    for(long int i=1; i<=r; ++i) res=res*modpow(i, mod-2)%mod;
    return res;
}
int main(){
    long long int k;
    cin >> k;
    string s;
    cin >> s;
    long long int n=s.length();
    long long int def=modpow(25LL,k);
    long long int tmp = (def*nCr(k+n-1LL,n-1LL))%mod;
    long long int ans = tmp;
    long long int inv=modinv(25LL);
    for(long long int i=1;i<=k;i++){
        tmp *= 26LL;
        tmp %= mod;
        tmp *= inv;
        tmp %= mod;       
        tmp *= modinv(k+n-i);
        tmp %= mod;
        if(i<k)tmp *= (k-i);
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;
}

//無理に逐次的に計算せず、テーブルを作ること。
//文字を逆にする痛恨のミス、なににイテレーションしたのかかくにんしろよ…
#include<bits/stdc++.h>
using namespace std;

const int N=2000005;
const long long int mod=1e9+7;
long long int f[N],inv[N],p[N],q[N],ans=0;

long long int modpow(long long int x, long long int n){
    long res=1;
    for(; n>0; n>>=1) {
        if (n&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n=s.length();
	f[0]=p[0]=q[0]=1;
	for(int i=1;i<=n+k;i++) f[i]=f[i-1]*i%mod;
	inv[n+k]=modpow(f[n+k],mod-2);//逆元はmod-2乗すればいいことが知られている
	for(int i=n+k;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	for(int i=1;i<=k;i++) p[i]=p[i-1]*25%mod,q[i]=q[i-1]*26%mod;
	for(int i=0;i<=k;i++){
		ans += p[k-i]*q[i]%mod*f[n+k-i-1]%mod*inv[n-1]%mod*inv[k-i]%mod;
        ans %=mod;
	}
	cout << ans << endl;
}
