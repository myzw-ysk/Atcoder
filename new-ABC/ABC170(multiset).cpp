#include<bits/stdc++.h>
using namespace std;
int main(){
    int x[6];
    for(int i=1;i<6;i++)cin >> x[i];
    for(int i=1;i<6;i++){
        if(x[i]==0){
            cout << i << endl;
            return 0;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    if(y>=2*x && y%2==0 && y<=4*x)cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,n;
    cin >> x >> n;
    if(n==0)cout << x << endl;
    else{
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    int flag=0;
    for(int i=0;i<105;i++){
        if(i==0){
            for(int j=0;j<n;j++){
                if(p[j]==x){
                    flag++;
                    break;
                }
            }
            if(flag==0){
                cout << x << endl;
                return 0;
            }
            else flag=0;
        }
        else{
            for(int j=0;j<n;j++){
                if(p[j]==x-i){
                    flag++;
                    break;
                }
            }
            if(flag==0){
                cout << x-i << endl;
                return 0;
            }
            else flag=0;
            for(int j=0;j<n;j++){
                if(p[j]==x+i){
                    flag++;
                    break;
                }
            }
            if(flag==0){
                cout << x+i << endl;
                return 0;
            }
            else flag=0;  
        }
    }
}
}
#include<bits/stdc++.h>
using namespace std;

int c[1000005];
int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=a[n-1];j+=a[i])c[j]++;
    }
    for(int i=0;i<n;i++)if(c[a[i]]==1)ans++;
    cout << ans << endl;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<multiset<int> > yo(200005);
    multiset<int> kyo;
    int n,q;
    cin >> n >> q;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        yo[b[i]].insert(a[i]);
    }
    for(auto u:yo)if(!u.empty())kyo.insert(*u.rbegin());
    for(int i=0;i<q;i++){
        int c,d;
        cin >> c >> d;
        c--;
        if(a[c]==*yo[b[c]].rbegin()){
            kyo.erase(kyo.find(a[c]));
            yo[b[c]].erase(yo[b[c]].find(a[c]));
            if(!yo[b[c]].empty())kyo.insert(*yo[b[c]].rbegin());
        }
        else yo[b[c]].erase(yo[b[c]].find(a[c]));
        if(yo[d].empty())kyo.insert(a[c]);
        else if(*yo[d].rbegin()<a[c]){
            kyo.erase(kyo.find(*yo[d].rbegin()));
            kyo.insert(a[c]);
        }
        yo[d].insert(a[c]);
        b[c]=d;
        cout << *kyo.begin() << endl;
    }
}



#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,int>;

const ll INF = 1e18;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  --si; --sj; --ti; --tj;
  vector<string> g(h);
  rep(i,h) cin >> g[i];

  auto toId = [&](int i, int j, int v) {
    return (i*w+j)*4+v;
  };
  auto modCeilK = [&](ll x) {
    return (x+k-1)/k*k;
  };

  vector<ll> dist(h*w*4, INF);//水かきの回数、すでに何マスその方向に進んだか
  priority_queue<LP, vector<LP>, greater<LP>> q;
  auto push = [&](int i, int j, int v, ll x) {
    int id = toId(i,j,v);
    if (dist[id] <= x) return;//距離が更新できない場合ははじく
    dist[id] = x;
    q.emplace(x,id);
  };
  rep(v,4) push(si, sj, v, 0);
  while (!q.empty()) {
    ll d = q.top().first;
    int id = q.top().second;
    q.pop();
    if (dist[id] != d) continue;
    int i = id/w/4;
    int j = id/4%w;
    int v = id%4;
    rep(nv,4) push(i,j,nv,modCeilK(d));
    {
      int ni = i+di[v], nj = j+dj[v];
      if (0 <= ni && ni < h && 0 <= nj && nj < w) {
        if (g[ni][nj] == '.') {
          push(ni,nj,v,d+1);
        }
      }
    }
  }

  ll ans = INF;
  rep(v,4) ans = min(ans, dist[toId(ti,tj,v)]);
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    ans = modCeilK(ans)/k;
    cout << ans << endl;
  }
  return 0;
}



