#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n%10==3)cout << "bon" << endl;
    else if(n%10==0 || n%10==1 || n%10==6 || n%10==8)cout << "pon" << endl;
    else cout << "hon" << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    string S;
    cin >> k >> S;
    if(S.length()<=k)cout << S << endl;
    else{
        for(int i=0;i<k;i++)cout << S[i];
        cout << "..." << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    double a,b,h,m;
    cin >> a >> b >> h >> m;
    double c;
    c = sqrt(a*a+b*b-2*a*b*cos(2*M_PI*(1.0*h*60-1.0*11*m)/(12*60*1.0)));
    cout << fixed << setprecision(16);
    cout << c << endl;
}
//ifでくくれる部分はくくって計算量を減らす
#include <bits/stdc++.h>
using namespace std;

vector<int> v[100005];
int c[100005];

int main(){
    int n,m;
    cin >> n >> m;
    queue<pair<int,int>> q;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    for(int u:v[1])q.push(make_pair(u,1));
    while(!q.empty()){
        if(c[q.front().first]==0){
            c[q.front().first]=q.front().second;
            for(int u:v[q.front().first]){
                if(u!=q.front().second && c[u]==0){
                q.push(make_pair(u,q.front().first));
                }
            }
        }
        q.pop();
    }
    cout << "Yes" << endl;
    for(int i=2;i<n+1;i++)cout << c[i] << endl;
}

//long doubleで処理するのは0が入っていた場合を考えると危険
//既約分数にして整数のペアにするのが正解
//mapをautoで回してfirst,secondで取り出すのは汎用性高そう
//数え上げは1個以上取り出し型×1個以上の取り出し方×それ以外の取り出し方
//数え上げにも連想配列の作り方にも一工夫いるのがさすがあおdiffってかんじ

#include <bits/stdc++.h>
using namespace std;

long long int c[200005];
const long long int mod=1e9+7;

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
    if(n==1)cout << n << endl;
    else{
    long long int a[n],b[n];
    map<pair<long long int,long long int>,long long int> mp;
    long double tmp;
    long long int ans=1;
    for(int i=0;i<n;i++){
        ans*=2;
        ans%=mod;
        c[i+1]=ans;
    }
    ans--;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        mp[tmp]++;      
    }
    long long int t;
    for(auto x:mp){
        if(x.first>=0)break;
        if(mp[-1.0/x.first]>0){
        t=((c[x.second]-1)*(c[mp[-1.0/x.first]]-1))%mod;
        t=(t*(c[n-x.second-mp[-1.0/x.first]]))%mod;
        ans+=(mod-t);
        ans%=mod;
        }
    }
    cout << ans << endl;
}}
