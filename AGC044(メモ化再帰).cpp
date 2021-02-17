#include <bits/stdc++.h>
#define INF 1000000000000000000LL
using namespace std;

long long int n,a,b,c,d;
map <long long int,long long int> dp;

long long int dfs(long long int N){
    if(N==0)return 0;
    else if(dp.find(N)!=dp.end())return dp[N];
    else{
    long long int ret=INF;
    vector<long long int> v={-N%2,2-(N%2),-N%3,3-(N%3),-N%5,5-(N%5)};
    if(INF/d>N)ret=N*d;
    for(int u:v){
        if((N+u)%2==0&&N+u>=0&&(N+u)/2<N&&abs(u)<2)ret=min(ret,dfs((N+u)/2)+a+d*abs(u));
        if((N+u)%3==0&&N+u>=0&&(N+u)/3<N&&abs(u)<3)ret=min(ret,dfs((N+u)/3)+b+d*abs(u));
        if((N+u)%5==0&&N+u>=0&&(N+u)/5<N&&abs(u)<5)ret=min(ret,dfs((N+u)/5)+c+d*abs(u));
    }
	return dp[N]=ret;
}}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> a >> b >> c >> d;
        dp.clear();
        cout << dfs(n) << endl;
    }
}



#include <bits/stdc++.h>
using namespace std;
int c[250005];
int main(){
    int n;
    cin >> n;
    if(n==2)cout << 0 << endl;
    else{
    int a[n*n];
    int p;
    for(int i=0;i<n*n;i++){
        cin >> p;
        a[p]=i+1;
    }
    int ans=0;
    for(int j=2;j<n;j+=2){
        for()
    }
    cout << ans << endl;
}}
