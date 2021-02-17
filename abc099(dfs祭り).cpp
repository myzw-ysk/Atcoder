#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n<=999)printf("ABC");
    else printf("ABD");
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int ans=-a;
    for(int i=0;i<b-a;i++)ans += i;
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int dfs(int N){
    if(N<=5)return mp[N]=N;
    else{
        if(mp[N]>0)return mp[N];
        else{
            int tmp=1e9;
            for(int i=1;i<=N;i*=6)tmp=min(tmp,dfs(N-i)+1);
            for(int i=1;i<=N;i*=9)tmp=min(tmp,dfs(N-i)+1);
            return mp[N]=tmp;
        }
    }
}
int main(){
    int n;
    cin >> n;
    cout << dfs(n) << endl;
}
#include<bits/stdc++.h>
using namespace std;

int n,c;
int w[3][35];
int d[35][35];
int ans;

void dfs(int now,int sum,int col1,int col2){
    for(int j=1;j<c+1;j++){
        if(j!=col1 && j!=col2){
            int tmp=0;
            for(int k=1;k<c+1;k++)tmp += w[now][k]*d[k-1][j-1];
            if(now==0)dfs(1,tmp,j,0);
            if(now==1)dfs(2,sum+tmp,col1,j);
            if(now==2)ans=min(ans,sum+tmp);
        }    
    }
}

int main(){
    cin >> n >> c;
    for(int i=0;i<c;i++)for(int j=0;j<c;j++)cin >> d[i][j];
    int e;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        cin >> e;
        w[(i+j+2)%3][e]++;
    }
    ans=1e9;
    dfs(0,0,0,0);
    cout << ans << endl;
}