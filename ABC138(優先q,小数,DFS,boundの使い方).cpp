#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    string s;
    cin >> a;
    cin >> s;
    if(a>=3200)cout << s << endl;
    else cout << "red" << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    double sum=0;
    int N;
    cin >> N;
    int i;
    int a[N];
    for(i=0;i<N;i++)cin >>a[i];
    for(i=0;i<N;i++)sum += 1.0/(double)(1.0*a[i]);
      cout << fixed << setprecision(16);
      cout << 1.0/sum << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int v;
    int i,j,k;
    double tmp1,tmp2;
    priority_queue<double,vector<double>,greater<double>> q;
    for(i=0;i<N;++i){
        cin >> v;
        q.push(v);}
    for(i=0;i<N-1;++i){
        tmp1 = (double)1.0*q.top()/2.0;
        q.pop();
        tmp2 = (double)1.0*q.top()/2.0;
        q.pop();
        q.push(tmp1+tmp2);
    }
    cout << fixed << setprecision(16);
    cout << q.top() << endl;
}

//やってたら冷え確定、E問題みたいなののほうが得意だしワンちゃんあった説はあるが
//木構造への苦手意識をそいで起きたい
//dfsのなかには極力ループをかかえないように…
//根での値をだせば、それを使ってっだせる、要は累積和的なノリでいける
//根よりも下、っていうのを枝に足しておくというので再現できるを
//直線のケースでイメージするのは賢い
//ちょくせんだったらどうなるかは汎用性がたかそう

#include<bits/stdc++.h>
using namespace std;

vector<int> to[200005];
long long int mp[200005];
long long int ans[200005];

void dfs(int v,int p=-1) {
  ans[v]+=mp[v];  
  for (int u : to[v]) {
    if (u != p){
    ans[u]+=ans[v];
    dfs(u,v); 
  }}}

int main(){
    int N,Q;
    cin >> N >> Q;
    long long int x;
    int a,b,p,i;
    for(i=0;i<N-1;i++){
        cin >> a >> b;
        to[a-1].push_back(b-1);
        to[b-1].push_back(a-1);
    }
    for(i=0;i<Q;i++){
        cin >> p >> x;
        mp[p-1]+=x;
    }
    dfs(0);
    for(i=0;i<N-1;i++)cout << ans[i] << " ";
    cout << ans[N-1] << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;
    vector<long long int> v[26];
    for(int i=0;i<(int)s.length();i++)v[(int)(s[i]-'a')].push_back(i);
    long long int ans=0;
    long long int tmp=0;
    int start=0;
    if(s[0]==t[0])start=1;
    for(int i=start;i<(int)t.length();i++){
        if(v[(int)(t[i]-'a')].size()==0){
            cout << -1;
            return 0;
        }
        int u = upper_bound(v[(int)(t[i]-'a')].begin(),v[(int)(t[i]-'a')].end(),tmp)-v[(int)(t[i]-'a')].begin();
        if(u<(int)v[(int)(t[i]-'a')].size()){
            ans+=v[(int)(t[i]-'a')].at(u)-tmp;
            tmp=v[(int)(t[i]-'a')].at(u);
        }
        else{
            ans+=(long long int)s.length()-tmp+v[(int)(t[i]-'a')].at(0);
            tmp=v[(int)(t[i]-'a')].at(0);
        }
    }
    cout << ans+1;
}