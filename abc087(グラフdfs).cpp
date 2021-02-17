#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,a,b;
    cin >> x >> a >> b;
    cout << (x-a)%b << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                if(500*i+100*j+50*k==x)ans++;
            }
        }
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
int ans[2][105];
int main(){
    int n;
    cin >> n;
    int a[2][n];
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin >> a[i][j];
    ans[0][0]=a[0][0];
    ans[1][0]=a[1][0]+a[0][0];
    if(n==1)cout << ans[1][0];
    else{
        for(int i=0;i<2;i++){
            for(int j=0;j<n-1;j++){
                if(i==0)ans[i][j+1]=ans[i][j]+a[i][j+1];
                else ans[i][j+1]=max(ans[i-1][j+1],ans[i][j])+a[i][j+1];
            }
        }
        cout << ans[1][n-1];
    }
}

//重み付きのグラフを使うというカンはあたり
//そのグラフについてdfsをしていく
#include<bits/stdc++.h>
using namespace std;

struct edge {
    int to, cost;
};

vector<edge> G[200010];//グラフを表現
bool vis[100010];//埋めたかどうかの判定
int d[100010];//距離の値

bool dfs(int v, int dist) {
    if (vis[v]) {
        if (d[v] != dist) {
            return true;
        }
        else {
            return false;
        }
    }
    vis[v] = true;
    d[v] = dist;
    for (int i = 0; i < (int)G[v].size(); i++) {
        if (dfs(G[v][i].to, d[v] + G[v][i].cost)) {
            return true;//その頂点における判定で一つでも矛盾があれば、全てtrueを返して強制終了。
        }
        //何も矛盾が無ければ次のリストを見る。
    }
    return false;//連結している頂点が最後まで探索できたという証。
}


int main(){
    int n,m;
    cin >> n >> m;
    if(m==0){
        cout << "Yes";
        return 0;
    }
    else{
        int l,r,d;
        for(int i=0;i<m;i++){
            cin >> l >> r >> d;
            l--; r--;
            G[l].push_back({r,d});
            G[r].push_back({l,-d});
        }
        for (int i=0;i<n;i++){//連結していない頂点があった場合に探索していく
            if (!vis[i] && dfs(i, 0)) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
}
