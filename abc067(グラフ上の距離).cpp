#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a%3==0 || b%3==0 || (a+b)%3==0)cout << "Possible";
    else cout << "Impossible";
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int l[n];
    for(int i=0;i<n;i++)cin >> l[i];
    sort(l,l+n);
    int ans=0;
    for(int i=n-k;i<n;i++)ans+=l[i];
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    long long int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
        s[i+1]=s[i]+a[i];
    }
    long long int ans=1e18;
    for(int i=1;i<n;i++)ans=min(ans,abs(sum-s[i]*2));
    cout << ans;
}

//どちら側になるか、に着目するのはよかったけど
//近いってことは結局
//それぞれの始点からの距離が短いって読み替えることができるよね
//そうすればどこが中天になるかとかいちいち気にしなくてよくなる
#include <bits/stdc++.h>
using namespace std;
int n;
int b[100005];
int w[100005];
vector<int> v[100005];
void dfs_b(int now,int pre,int count){
    if(pre==-1)b[now]=count;
    for(auto u:v[now]){
        if(u!=pre){
            b[u]=count+1;
            dfs_b(u,now,count+1);
        }
    }
}
void dfs_w(int now,int pre,int count){
    if(pre==-1)w[now]=count;
    for(auto u:v[now]){
        if(u!=pre){
            w[u]=count+1;
            dfs_w(u,now,count+1);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    dfs_b(0,-1,0);
    dfs_w(n-1,-1,0);
    int bside=0;
    int wside=0;
    for(int i=0;i<n;i++){
        if(b[i]<=w[i])bside++;
        else wside++;
    }
    if(bside>wside)cout << "Fennec";
    else cout << "Snuke";
}