#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int flag=0;
    map<char,int> m;
    for(int i=0;i<4;i++)m[S[i]]++;
    for(auto p : m)flag++;
    if(flag==2)cout << "Yes" << endl;
    else cout << "No" << endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int p[n];
    int i;
    for(i=0;i<n;i++)cin >> p[i];
    int flag=0;
    for(i=1;i<n-1;i++)if((p[i]>p[i-1] && p[i+1]>p[i])||(p[i]>p[i+1] && p[i-1]>p[i]))flag++;
    cout << flag << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int d[N];
    int i;
    for(i=0;i<N;i++)cin >> d[i];
    sort(d,d+N);
    cout << d[N/2]-d[N/2-1] << endl;
}

//重複組み合わせ
//https://math.nakaken88.com/textbook/expert-combination-with-repetition/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 4005;
const int mod = 1000000007;
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
    int i,N,K;
    long long int ans;
    cin >> N >> K;
    for(i=1;i<K+1;i++){
        ans=(COM(K-1,i-1)*COM(N-K+1,i))%mod;
        cout << ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

vector<int> to[200005];
int check[200005];
queue<int> q;
int S,T;

void kkp(int v){
    for(int u : to[v]){
        for(int w : to[u]){
            for(int x : to[w]){
                if(check[x]==0){
                    q.push(x);
                    check[x]++;
                }
                if(check[T-1]>0)break;
            }
            if(check[T-1]>0)break;
            }
        if(check[T-1]>0)break;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    int i,j,u,v;
    for(i=0;i<M;i++){
        cin >> u >> v;
        to[u-1].push_back(v-1);
    }
    cin >> S >> T;
    kkp(S-1);
    if(check[T-1]>0)cout << 1 << endl;
    else{
        int flag=2;
        int tmp=q.size();
        int count=0;
        while(!q.empty()){
            kkp(q.front());
            q.pop();
            count++;
            if(check[T-1]>0)break;
            if(tmp==count){
                flag++;
                count=0;
                tmp=q.size();
            }
        }
        if(check[T-1]>0)cout << flag << endl;
        else cout << -1 << endl;
}}

