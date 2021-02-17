#include <bits/stdc++.h>
using namespace std;
int main(){
    int d,t,s;
    cin >> d >> t >> s;
    if(s*t>=d)cout << "Yes";
    else cout << "No";
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int ans=1e5;
    for(int i=0;i<s.length()-t.length()+1;i++){
        int tmp=0;
        for(int j=0;j<t.length();j++)if(s[i+j]!=t[j])tmp++;
        ans=min(tmp,ans);
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1]=(s[i]+a[i])%mod;
    }
    long long int ans=0;
    long long int tmp;
    for(int i=0;i<n-1;i++){
        tmp = (a[i]*(s[n]-s[i+1]))%mod;
        ans += tmp%mod;
        ans %= mod;
    }
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1]=(s[i]+a[i])%mod;
    }
    long long int ans=0;
    long long int tmp;
    for(int i=0;i<n-1;i++){
        tmp = (a[i]*(s[n]-s[i+1]+mod))%mod;
        ans += tmp%mod;
        ans %= mod;
    }
    cout << ans;
}

#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par; 
    UnionFind(int N) : par(N) { 
        for(int i = 0; i < N; i++) par[i] = i;
    }
    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return; 
        par[rx] = ry; 
    }
    void reset(int n){ 
        for(int i=0;i<n;i++)par[i] = root(par[i]);
    }
    bool con(int x,int y){
        return par[x]==par[y];
    }
    int solve(int n){
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[par[i]]++;
        }
        int ans=0;
        for(auto u:mp)ans=max(ans,u.second);
        return ans;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind tree(n);
  int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        tree.unite(x-1, y-1);
    }
    tree.reset(n);
    cout << tree.solve(n);
}


//E
//エラスト利用した素因数分解
//osa_k法というらしい
//http://tutuz.hateblo.jp/entry/2018/10/03/074039

#include <bits/stdc++.h>
using namespace std;
int c[1000005];

//n以下の整数について最小の素因数を求めた結果の配列を返す
//min_factor[i]はiを割り切る最小の数（iの素因数のうち最小のもの）
//min_factor[i] == iならiは素数（i=0, 1のときを除く）
vector<int> sieve(int n){
    //素数候補を管理する配列
    vector<int> min_factor(n+1);
    //2以上の数を一度素数候補に入れる
    for(int i = 0; i <= n; i++) min_factor[i] = i;
    //それぞれの数について最小の素因数を求める
    for(int i = 2; i*i <= n; i++){
        if(min_factor[i] == i){
            for(int j = 2; i*j <= n; j++){
                if(min_factor[i*j] > i){
                    min_factor[i*j] = i;
                }
            }
        }
    }
    return min_factor;
}

//配列min_factorを使ってmを素因数分解する
//配列ansにはmの素因数が小さい順に格納される
vector<int> factor(vector<int> &min_factor, int m){
    vector<int> ans;
    while(m > 1){
        ans.push_back(min_factor[m]);
        m /= min_factor[m];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    vector<int> min_factor = sieve(a[n-1]);
    int flag=0;
    for(int i=0;i<n;i++){
        vector<int> ans = factor(min_factor, a[i]);
        int pre=1;
        for(auto u:ans){
            if(u!=pre)c[u]++;
            if(c[u]==n){
                cout << "not coprime";
                return 0;
            }
            if(c[u]>1)flag++;
            pre=u;
        }
    }
    if(flag==0){
        cout << "pairwise coprime";
        return 0;
    }
    else{
        cout << "setwise coprime";
        return 0;
    }
}

