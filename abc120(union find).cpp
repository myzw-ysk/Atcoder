#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(b/a,c) << endl;
}
#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y){
 long long int tmp;
 long long int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}
int main(){
    long long int a,b,k;
    cin >> a >> b >> k;
    long long int ans;
    ans=gcd(a,b);
    int count=0;
    for(long long int i=ans;i>0;i--){
        if(ans%i==0)count++;
        if(count==k){
            ans=i;
            break;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int b=0;
    int w=0;
    for(int i=0;i<S.length();i++){
        if(S[i]=='0')w++;
        else b++;
    }
    cout << min(b,w)*2 << endl;
}

https://drken1215.hatenablog.com/entry/2019/03/03/224600
https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396

#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
int a[100005],b[100005];
long long int c[100005];
int n,m;
vector<int> sima[100005];
int num;
long long int uni_fi(int now){
        if(mp[a[now]]+mp[b[now]]==0){
            mp[a[now]]=num;
            mp[b[now]]=num;
            sima[num].push_back(a[now]);
            sima[num].push_back(b[now]);
            num++;
            return c[now]+1;
        }
        else if(mp[a[now]]==0 || mp[b[now]]==0){
            if(mp[a[now]]==0 && mp[b[now]]>0){
                mp[a[now]]=mp[b[now]];
                sima[mp[b[now]]].push_back(a[now]);
                long long int tmp=sima[mp[b[now]]].size();
                return c[now]+tmp-1;
            }
            else{
                mp[b[now]]=mp[a[now]];
                sima[mp[a[now]]].push_back(b[now]);
                long long int tmp=sima[mp[a[now]]].size();
                return c[now]+tmp-1;
            }
        }
        else if(mp[a[now]]==mp[b[now]])return c[now];
        else{
            long long int tmp=sima[max(mp[a[now]],mp[b[now]])].size();
            long long int tmp2=sima[min(mp[a[now]],mp[b[now]])].size();
            for(int u:sima[max(mp[a[now]],mp[b[now]])]){
                mp[u]=min(mp[a[now]],mp[b[now]]);
                sima[min(mp[a[now]],mp[b[now]])].push_back(u);                
            }
            return c[now]+tmp*tmp2;       
        }
        }

int main(){
    cin >> n >> m;
    for(int i=1;i<m+1;i++)cin >> a[i] >> b[i];
    num=1;
    for(int i=m;i>0;i--)c[i-1]=uni_fi(i);
    for(int i=1;i<m+1;i++)cout << c[0]-c[i] << endl;
}

//Ex. ATC001
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind tree(N);

    for(int i = 0; i < Q; i++) {
        int p, x, y;
        cin >> p >> x >> y;
        if(p==0){
            tree.unite(x, y); // xの木とyの木を併合する
        }else{
            if(tree.same(x, y)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
