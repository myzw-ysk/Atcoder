#include <bits/stdc++.h>
using namespace std;
int main(){
    string S,T;
    cin >> S >> T;
    if(S+T[S.length()]==T)cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int A,B,C,K;
    cin >> A >> B >> C >> K;
    if(K<A)cout << K << endl;
    else if(K<A+B)cout << A << endl;
    else cout << A-(K-A-B) << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int c[n];
    int a[n][m];
    for(int i=0;i<n;i++){
        cin >> c[i];
        for(int j=0;j<m;j++)cin >> a[i][j];
    }
    int ans=1e9;
    int tmp;
    int flag;
    int T[m];
    for(int i=0;i<(1 << n);i++){
        flag=0;
        tmp=0;
        memset(T,0,sizeof(T));
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                for(int k=0;k<m;k++)T[k]+=a[j][k];
                tmp+=c[j];
            }
        }
            for(int k=0;k<m;k++)if(T[k]<x)flag++;
            if(flag==0)ans=min(ans,tmp);
        }
    if(ans==1e9)cout << -1 << endl;
    else cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
long long int c[200005];
int main(){
    int n;
    long long int k;
    cin >> n >> k;
    int a[n+1];
    for(int i=1;i<n+1;i++)cin >> a[i];
    int now=1;
    long long int count=0;
    long long int loop;
    long long int bef;
    while(1){
        if((count>0 && now==1) || c[now]>0){
            loop=count-c[now];
            bef=c[now];
            break;
        }
        else{
            c[now]=count;
            now=a[now];
            count++;
        }
        if(count==k)break;
    }
    if(count==k)cout << now << endl;
    else{
        long long int ans=(k-bef)%loop;
        while(ans>0){
            now=a[now];
            ans--;
        }
        cout << now << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
const long long int mod=998244353;
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
    COMinit();
    int N,K;
    long long int M;
    cin >> N >> M >> K;
    long long int ans=0;
    long long int tmp=M;
    int x=1;
    while(x<N-K){
        tmp*=(M-1);
        tmp%=mod;
        x++;
    }
    for(int i=K;i>=0;i--){
        ans+=(tmp*COM(N-1,i));
        ans%=mod;
        tmp*=(M-1);
        tmp%=mod;
    }
    cout << ans << endl;
}