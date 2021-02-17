#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    cin >> c;
    cout << c+c*c+c*c*c << endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int ans=0;
    for(int i=0;i<s.length();i++)if(s[i]!=t[i])ans++;
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
long long int A[200005],B[200005];
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    long long int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
        A[i+1] = A[i]+a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
        B[i+1] = B[i] + b[i];
    }
    int j=m;
    int ans=0;
    for(int i=0;i<n+1;i++){
        while(A[i]+B[j]>k && j>0)j--;
        if(A[i]+B[j]<=k)ans=max(ans,i+j);
    }
    cout << ans;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int64_t n;
    cin >> n;
    int64_t ans=0;
    int64_t tmp;
    for(int64_t i=1;i<=n;i++){
        tmp = n/i;
        ans += i*(tmp+1)*tmp/2;
    }
    cout << ans;
}


//ほうじょ原理を使うと複数の集合のw集合がだせるよ

#include<bits/stdc++.h>
using namespace std;

const int MAX = 500005;
const long long int mod = 1e9+7;
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
    int n,m;
    cin >> n >> m;
    COMinit();
    long long int ans = 0;
    for(int i=0;i<=n;i++){
        if(i%2==0)ans += COM(n,i)%mod*fac[m]%mod*finv[m-i]%mod*fac[m-i]%mod*fac[m-i]%mod*finv[m-n]%mod*finv[m-n]%mod;
        else ans += mod - COM(n,i)%mod*fac[m]%mod*finv[m-i]%mod*fac[m-i]%mod*fac[m-i]%mod*finv[m-n]%mod*finv[m-n]%mod;
        ans %= mod;
    }
    cout << ans;
}