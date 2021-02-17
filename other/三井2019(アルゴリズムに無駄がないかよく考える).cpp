#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >>a >> b >> c >> d;
    if(a!=c)cout << 1;
    else cout << 0;
}
//範囲は一番確実な範囲を取ろう
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        if((108*i)/100==n){
            cout << i;
            return 0;
        }
    }
    cout << ":(";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int num=x/100;
    if(x<=105*num)cout << 1;
    else cout << 0;
}
//char同士の足し算は定義されていないよ
#include<bits/stdc++.h>
using namespace std;
int c[30005][10];
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans=0;
    map<int,int> san;
    map<int,int> ni;
    map<char,int> ichi;
    for(int i=0;i<n-2;i++){
        if(ichi[s[i]]==0){
            ichi[s[i]]++;
            for(int j=i+1;j<n-1;j++){
                if(ni[(s[i]-'0')*10+(s[j]-'0')]==0){
                    ni[(s[i]-'0')*10+(s[j]-'0')]++;
                    for(int k=j+1;k<n;k++){
                        if(san[(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0')]==0){
                            ans++;
                            san[(s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0')]++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}

//沼にはまった再帰解法
//等号を2回以上続けたり、a==b-1みたいな表記がNGだったりといろいろ厳しいので
//極力避けるべき
//というか、分岐が6つ以上あるifは実装事故を起こしやすいから避けるべき
//本質は結局同じなやつの数なんだから下みたいな単純な積にすることができる。
//複雑に各システムを書くこと自体がリスク、そのアルゴリズムが本当に無駄を含んでいないかよく考える
#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
int a[100005];
long long int dp[100005];
int n;
void solve(int now,int x,int y,int z){
    if(now==n)return;
    else if(x==y && y==z && y==a[now]){
        dp[now]=(dp[now-1]*3LL)%mod;
        solve(now+1,x+1,y,z);
    }
    else if(x==y && y==a[now] && x!=z){
        dp[now]=(dp[now-1]*2LL)%mod;
        solve(now+1,x+1,y,z);        
    }
    else if(z==y && y==a[now] && x!=z){
        dp[now]=(dp[now-1]*2LL)%mod;
        solve(now+1,x,y+1,z);        
    }
    else if(z==x && x==a[now] && x!=y){
        dp[now]=(dp[now-1]*2LL)%mod;
        solve(now+1,x,y,z+1);        
    }
    else if(x==a[now]&& x!=z && x!=y){
        dp[now]=dp[now-1];
        solve(now+1,x+1,y,z);
    }
    else if(y==a[now] && x!=y && z!=y){
        dp[now]=dp[now-1];
        solve(now+1,x,y+1,z);
    }
    else if(z==a[now] && z!=y && z!=x){
        dp[now]=dp[now-1];
        solve(now+1,x,y,z+1);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    dp[0]=3;
    solve(1,1,0,0);
    cout << dp[n-1];
}

#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
int main(){
    int n;
    cin >> n;
    int a;
    long long int ans=1;
    int r=0; int g=0; int b=0;
    for(int i=0;i<n;i++){
        cin >> a;
        ans *= ((a==r)+(a==g)+(a==b));
        ans %=mod;
        if(a==r)r++;
        else if(a==g)g++;
        else b++;
    }
    cout << ans;
}


//算数だからEでじこってたならこっちでもよかった…？
//WAになったらまずは落ち着いてコーディングミスがないかさがそうね…
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t[2],a[2],b[2];
    for(int i=0;i<2;i++)cin >> t[i];
    for(int i=0;i<2;i++)cin >> a[i];
    for(int i=0;i<2;i++)cin >> b[i];
    long long int move=t[0]*(a[0]-b[0])+t[1]*(a[1]-b[1]);
    long long int MAX=max(max(0LL,t[0]*(a[0]-b[0])),move);
    long long int MIN=min(min(0LL,t[0]*(a[0]-b[0])),move);
    if(move==0)cout << "infinity";
    else{
        if(MIN==0 || MAX==0)cout << 0;
        else if(move>0 && (abs(MIN)%move)!=0)cout << 2*(abs(MIN)/move+1) - 1;
        else if(move>0 && (abs(MIN)%move)==0)cout << 2*(abs(MIN)/move+1) - 2;
        else if(move<0 && (MAX%abs(move))!=0)cout << 2*(MAX/abs(move)+1) - 1;
        else if(move<0 && (MAX%abs(move))==0)cout << 2*(MAX/abs(move)+1) - 2;
    }
}