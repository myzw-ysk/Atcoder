#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s[0]==s[2])cout << "Yes";
    else cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max(0,min(b,d)-max(a,c));
}
#include<bits/stdc++.h>
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
    int n;
    cin >> n;
    long long int t[n];
    for(int i=0;i<n;i++)cin >> t[i];
    if(n==1){
        cout << t[0];
        return 0;
    }
    long long int ans=t[0]/gcd(t[0],t[1])*t[1];
    for(int i=2;i<n;i++)ans=ans/gcd(ans,t[i])*t[i];
    cout << ans;
}


//テーブルつくれないと思ってた？作れるよ。だってどっちもkまでなんだから
//ていうか、N10^5なんだからテーブルつくらないと逐一だしてたらまにあわないよ？
#include<bits/stdc++.h>
using namespace std;
int n,k;
map<pair<int,int>,long long int> mp;
vector<int> v[100005];
long long int d[100005];
void solve(int now,int before,long long int dis){
    if(now==before){
        for(auto u:v[now]){
            d[u]=mp[make_pair(min(now,u),max(now,u))];
            solve(u,now,mp[make_pair(min(now,u),max(now,u))]);
        }
    }
    else{
        for(auto u:v[now]){
            if(u!=before){
                if(d[u]>dis+mp[make_pair(min(now,u),max(now,u))]){
                    d[u]=dis+mp[make_pair(min(now,u),max(now,u))];
                    solve(u,now,dis+mp[make_pair(min(now,u),max(now,u))]);
            }}
        }
    }
}

int main(){
    cin >> n;
    int a,b,c;
    for(int i=0;i<n-1;i++){
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        mp[make_pair(min(a,b),max(a,b))]=c;
    }
    int q;
    cin >> q >> k;
    for(int i=1;i<=n;i++)d[i]=1e18;
    solve(k,k,0);
    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        cout << d[x]+d[y] << endl;
    }
}