//添え字ミスが目立った回だった、やっぱり疲れている…？
//メンタルの管理を大切に

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b)cout << c;
    else if(b==c) cout << a;
    else cout << b;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    char c[h][w];
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> c[i][j];
    int dy[8]={-1,-1,-1,0,0,1,1,1};
    int dx[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
        if(c[i][j]=='#')cout << "#";
        else{
            int tmp=0;
            for(int k=0;k<8;k++){
                if(i+dy[k]>=0 && i+dy[k]<h && j+dx[k]>=0 && j+dx[k]<w){
                    if(c[i+dy[k]][j+dx[k]]=='#')tmp++;
                }
            }
            cout << tmp;
        }
    }
    cout << endl;
}
}

//迷っている時間が無駄だった、UFでいけると思ったら信じて実装しきる
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    void rereset(int n){ 
        for(int i=0;i<n;i++)par[i] = i;
    }
    void reset(int n){ 
        for(int i=0;i<n;i++)par[i] = root(par[i]);
    }
    bool solve(int n) {
        int num=0; 
        for(int i=0;i<n;i++)if(par[i]==par[0])num++;
        return num==n;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    int a,b;
    pair<int,int> p[m];
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        p[i]=make_pair(a,b);
    }
    UnionFind tree(n);   
    int ans=0;
    for(int i=0;i<m;i++){
        tree.rereset(n);
        for(int j=0;j<m;j++)if(j!=i)tree.unite(p[j].first,p[j].second);
        tree.reset(n);
        ans += (1-tree.solve(n));
    }
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    long long int x[n],y[n];
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    long long int ans=5e18;
    if(k==2){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans=min(ans,abs(x[i]-x[j])*abs(y[i]-y[j]));
            }
        }
        cout << ans;
    }
    else if(k==3){
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int l=j+1;l<n;l++){
                    long long int MAX=max(x[i],max(x[j],x[l]));
                    long long int MAY=max(y[i],max(y[j],y[l]));
                    long long int MIX=min(x[i],min(x[j],x[l]));
                    long long int MIY=min(y[i],min(y[j],y[l]));
                    ans=min(ans,(MAX-MIX)*(MAY-MIY));                    
                }
            }
        }
        cout << ans;
    }
    else{
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int l=j+1;l<n-1;l++){
                    for(int m=l+1;m<n;m++){
                        long long int MAX=max(max(x[i],x[m]),max(x[j],x[l]));
                        long long int MAY=max(max(y[i],y[m]),max(y[j],y[l]));
                        long long int MIX=min(min(x[i],x[m]),min(x[j],x[l]));
                        long long int MIY=min(min(y[i],y[m]),min(y[j],y[l]));
                        int count=0;
                        for(int a=0;a<n;a++)if(x[a]<=MAX && x[a]>=MIX && y[a]<=MAY && y[a]>=MIY)count++;
                        if(count>=k)ans=min(ans,(MAX-MIX)*(MAY-MIY));
                    }
                }
            }
        }
        cout << ans;
    }    
}