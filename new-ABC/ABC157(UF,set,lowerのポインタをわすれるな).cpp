#include <bits/stdc++.h>
using namespace std;
 
int main(){
int N;
cin >> N;
 if((N%2)==1)cout << N/2 + 1 << endl;
 else{cout << N/2 << endl;}
}


#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int i;
 int j;
 int k;
 int a[3][3];
 int c[3][3];
 for(i=0;i<3;i++){
     for(j=0;j<3;j++){
         cin >> a[i][j];
        c[i][j]=0;
     }
 }
 cin >> N;
 int b[N];
for(i=0;i<N;i++){
    cin >> b[i];
    for(j=0;j<3;j++){
        for(k=0;k<3;k++){
            if(a[j][k]==b[i])c[j][k]=1;
     }
 }}
 int flag=0;
if(c[0][0]==1 && c[1][1]==1 && c[2][2]==1)flag++;
if(c[2][0]==1 && c[1][1]==1 && c[0][2]==1)flag++;
 for(i=0;i<3;i++){
    if(c[0][i]==1 && c[1][i]==1 && c[2][i]==1){
        flag++;
        break;
    }
    else if(c[i][0]==1 && c[i][1]==1 && c[i][2]==1){
        flag++;
        break;
    }
 }
 if(flag>0)cout << "Yes" << endl;
 else{cout << "No" << endl;}

}


//完全に盲点だったが頭から全探索してすべての条件を満たすか確認すればよい
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int M;
 cin >> N >> M;
 int s[M];
 int c[M];
 int i;
 int j;
 for(i=0;i<M;i++)cin >> s[i] >> c[i];
 int ans=0;
 int flag=0;
  for(i=0;i<M;i++){
    if(((s[i]==1) && (c[i]==0)) && (N!=1)){
          flag++;
          break;
    }
 }
 for(i=0;i<M-1;i++){
     for(j=i+1;j<M;j++){
         if((s[i]==s[j]) && (c[i]!=c[j]) ){
             flag++;
             break;
         }
     }
 }
 if(flag>0)cout << "-1" << endl;
 else{
    int a;
    int b;
    for(i=0;i<M;i++){
        a=c[i];
        b=ans;
        for(j=0;j<N-s[i];j++)b/=10;
        b = (b%10);
        if(b!=a){
            for(j=0;j<N-s[i];j++)a*=10;
            ans+=a;
        }
    }
    int c=1;
    for(j=0;j<N-1;j++)c*=10;
    if(N==1&&ans==0)cout << ans << endl;
    else{
    if(c>ans)ans+=c;
 cout << ans << endl;
 }}
}

//そもそも友達の友達の友達でもオーケーだからつながってる島全体から直接つながってるやつを削る
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    map<int,int> num; 
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
    void solve(int n){
        for(int j=0;j<n;j++)num[par[j]]++;
    }
    int ans(int i){
        return (num[par[i]]-1);
    }
};
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    UnionFind tree(n);
    int a,b;
    vector<int> v[n];
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        tree.unite(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    tree.reset(n);
    tree.solve(n);
    for(int i=0;i<k;i++){
        int c,d;
        cin >> c >> d;
        c--; d--;
        if(tree.con(c,d)){
            v[c].push_back(d);
            v[d].push_back(c);
        }
    }
    for(int i=0;i<n;i++)cout << tree.ans(i)-(int)v[i].size() << " ";
}



//勘通りsetを使って管理することになるけど
//今回は結局種類が知りたいから文字ごとにsetを作る
//何番目かでsetを作ればたしかにかぶりを気にする必要もない
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,q;
  string s;
  cin >> n >> s >> q;
  set<int> alpha[26];
  for(int i=0;i<n;i++)alpha[(int)(s[i]-'a')].insert(i);
  for(int i=0;i<q;i++){
      int t;
      cin >> t;
      if(t==1){
        int I;
        char c;
        cin >> I >> c;
        I--;
        if(s[I]!=c){
            alpha[(int)(s[I]-'a')].erase(I);
            alpha[(int)(c-'a')].insert(I);
            s[I]=c;
        }
      }
      else{
        int l,r;
        cin >> l >> r;
        l--; r--;
        int ans=0;
        for(int j=0;j<26;j++){
            auto u = alpha[j].lower_bound(l);
            if(u!=alpha[j].end() && *u<=r)ans++;
        }
        cout << ans << endl;
      }
  }
}