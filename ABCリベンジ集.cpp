//ABC146-D
#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;
vector<int> g[100005];
int c[100005];
int N;
void dfs(int now,int pre,int num){
    if(num==N-1)return;
    else{
        int K=0;
        int count=num;
        for(int u:g[now]){
            if(u!=pre){
                K++;
                if(c[m[make_pair(min(pre,now),max(pre,now))]]==K)K++;
                if(c[m[make_pair(min(u,now),max(u,now))]]==0){
                    c[m[make_pair(min(u,now),max(u,now))]]=K;
                    count++;
                }
            }
        }
        for(int u:g[now]){
            if(u!=pre)dfs(u,now,count);
        }
    }}


int main(){
    int a,b;
    cin >> N;
    for(int i=1;i<N;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        m[make_pair(a,b)]=i;
    }
    dfs(1,-1,0);
    int ans=0;
    for(int i=1;i<N;i++)ans=max(ans,c[i]);
    cout << ans << endl;
    for(int i=1;i<N;i++)cout << c[i] << endl;
}

//ABC147-C

#include <bits/stdc++.h>
using namespace std;

int x[20][20],y[20][20];

int main(){ 
    int n;
    cin>>n;
    int c[n];
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<a[i];j++){
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        int tmp=__builtin_popcount(i);
        int flag=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))c[j]=1;
            else c[j]=0;
        }
        for(int i=0;i<n;i++){
            if(c[i]==1){
                for(int j=0;j<a[i];j++){
                    if(c[x[i][j]]==0 && y[i][j]==1)flag++;
                    else if(c[x[i][j]]==1 && y[i][j]==0)flag++;
            }}
        }
        if(flag==0)ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}



//ABC165-C
#include <bits/stdc++.h>
using namespace std;

int a[55],b[55],c[55],d[55];
int e[11];
int ans;
int n,m,q;

void solve(int number,int tmp){
    if(number==n){
        int answer=0;
        for(int i=0;i<q;i++){
            if(e[b[i]-1]-e[a[i]-1]==c[i])answer+=d[i];
        }
        ans=max(ans,answer);        
    }
    else{
        for(int i=tmp;i<m+1;i++){
            e[number]=i;
            solve(number+1,i);
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i=0;i<q;i++)cin >> a[i] >> b[i] >> c[i] >> d[i];
    ans=0;
    solve(0,1);
    cout << ans << endl;
}

//ABC170-E
//特定の1つだけ消したいときはイテレータを使うこと

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

//ABC134-E

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=1e9;
    for(int i=0;i<n;i++){
        cin >> a;
        a *= (-1);
        *upper_bound(dp,dp+n,a)=a;
    }
    cout << lower_bound(dp,dp+n,1e9)-dp;
}

//ABC098-D

//xorの逆元はxorで計算できる
//累積xorはxorで計算できる
//ならしゃくとれるやん？
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long long int r=0;
    long long int p=a[0]; long long int x=a[0];
    long long int ans=0;
    for(long long int l=0;l<n;l++){
        while(p==x && r<n){
            r++;
            if(r<n){
                p+=a[r]; x^=a[r];
            }
        }
        ans+=(r-l);
        p-=a[l]; x^=a[l];
    }
    cout << ans;
}


//ABC113-D
//フィボナッチっぽくかけたけど係数がびみょうにあわない…
//もう一度やりなおしかなぁ…
#include <bits/stdc++.h>
using namespace std;

const long long int mod = 1e9+7;
long long int dp[100][10];
long long int bow[10][10][2];
long long int non[10][10][2];
int main(){
    int h,w,k;
    cin >> h >> w >> k;
    if(w==1){
        cout << 1;
        return 0;
    }
    for(int i=0;i<w;i++){
        non[i][0][0]=1;
        for(int j=0;j<w-1;j++){
            non[i][j+1][0]+=non[i][j][0];
            if((j+1)!=i)non[i][j+1][0]+=non[i][j][1];
            if(j!=i)non[i][j+1][1]+=non[i][j][0];
        }
    }
    for(int i=0;i<w;i++){
        bow[i][0][0]=1;
        for(int j=0;j<w-1;j++){
            if(j!=i)bow[i][j+1][0]+=bow[i][j][0];
            if(j!=i)bow[i][j+1][0]+=bow[i][j][1];
            bow[i][j+1][1]+=bow[i][j][0];
        }
    }
    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dp[i+1][j]+=dp[i][j]*(non[j][w-1][0]+non[j][w-1][1]);//引いていい棒の本数
            if(j<w-1)dp[i+1][j+1]+=dp[i][j]*(bow[j][w-1][0]+bow[j][w-1][1]);//引いていい棒の本数
            if(j>0)dp[i+1][j-1]+=dp[i][j]*(bow[j-1][w-1][0]+bow[j-1][w-1][1]);//引いていい棒の本数
        }
        for(int j=0;j<w;j++)dp[i+1][j]%=mod;
    }
    cout << dp[h][k-1];
}
