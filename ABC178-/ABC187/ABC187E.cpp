#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(200005); //要素数指定しないと怒られます
vector<int> par(200005, -1); // par[v]: 頂点 v の親
vector<long long int> add(200005, 0); // vectorはこの書式ですべて埋められる

//クエリ処理とは行ってもだすのは最終的な合計だけだし、シンプルな木構造
//累積和でかいけつしてあげられるよね

void dfs(int u, int p){
    par[u] = p;
    if (p != -1) add[u] += add[p];
    for (auto nv: v[u]) {
        if (nv == p) continue;
        dfs(nv, u);
    }
}

int main(){
    int n;
    cin >> n;

    pair<int,int> path[n]
    int a,b;

    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        --a; --b;
        path[i]=make_pair(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

// DFS (根付き木にするのと、累積和をとるのを使い回す)
    int root = 0;
    dfs(root, -1);

    int q;
    cin >> q;

    int t,e,x;
    long long int solve = 0;
    
    for(int i=0;i<q;i++){
        cin >> t >> e >> x;
        --e;
        a = path[e].first; b = path[e].second;
        if(t==1)swap(a,b);

        if(par[b]==a)add[b]+=x;
        else add[a] -= x,solve += x; //2の場合を逆に解釈した
    }
    dfs(root,-1);
    for(int i=0;i<n;i++)cout << add[i]+solve << endl;
}