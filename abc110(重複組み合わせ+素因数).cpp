#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==max(a,max(b,c)))cout << a*10+b+c << endl;
    else if(b==max(a,max(b,c)))cout << b*10+a+c << endl;
    else if(c==max(a,max(b,c)))cout << c*10+a+b << endl;
}

#include <bits/stdc++.h>
using namespace std;
    int main(){
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        int a[n],b[m];
        for(int i=0;i<n;i++)cin >> a[i];
        for(int j=0;j<m;j++)cin >> b[j];
        sort(a,a+n);
        sort(b,b+m);
        int flag=0;
        if(b[0]>a[n-1]){
            for(int i=a[n-1]+1;i<=b[0];i++){
                if(i>x && i<=y)flag++;
            }
            if(flag>0)cout << "No War" << endl;
            else cout << "War" << endl;
        }
        else cout << "War" << endl;
    }

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    map<int,int> mp_s;
    map<int,int> mp_p;
    int s_num;
    int t_num;
    int flag=0;
    for(int i=0;i<s.length();i++){
        s_num=s[i]-'a'+1;
        t_num=t[i]-'a'+1;
        if(mp_s[s_num]==0)mp_s[s_num]=t_num;
        else if(mp_s[s_num]!=t_num)flag++;
        if(mp_p[t_num]==0)mp_p[t_num]=s_num;
        else if(mp_p[t_num]!=s_num)flag++;
        if(flag>0)break;
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}

#include <bits/stdc++.h>
using namespace std;
const int64_t mod=1e9+7;

map< int64_t, int64_t > prime_factor(int64_t n) {
  map< int64_t, int64_t > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n]++;
  return ret;
}
const int MAX = 200005;
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
    int64_t n,m;
    cin >> n >> m;
    COMinit();
    int64_t ans=1;
    for(auto u:prime_factor(m)){
        ans*=COM(n+u.second-1,u.second);
        ans%=mod;
    }
    cout << ans << endl;
}