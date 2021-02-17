#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(abs(a-b)<= d && abs(b-c)<=d)cout << "Yes" << endl;
    else if(abs(a-c)<=d)cout << "Yes" << endl;
    else cout << "No" << endl; 
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int ans=1;
    for(int i=2;i*i<=x;i++){
        int tmp=i;
        while(tmp*i<=x)tmp*=i;
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}
//辞書順で上位だけなら後ろはいらない
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    string s;
    int k;
    cin >> s >> k;
    for(int i=0;i<s.length();i++){
        string t;
        for(int j=i;j<min(i+k,(int)s.length());j++){
            t.push_back(s[j]);
            mp[t]++;
        }
    }
    int c=0;
    for(auto u:mp){
        c++;
        if(c==k){
            cout << u.first << endl;
            return 0;
        }
    }
}

//交換可能が連鎖している状態はUFで捉えられる
//何を使えばいいのかが一番むずかった
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
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind tree(n);
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        tree.unite(x-1, y-1);
    }
    tree.reset(n);
    int ans=0;
    for(int i=0;i<n;i++)ans += tree.con(i,p[i]-1);
    cout << ans << endl;
}