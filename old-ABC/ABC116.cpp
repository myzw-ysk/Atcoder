#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    for(int i=0;i<3;i++)cin >> a[i];
    sort(a,a+3);
    cout << a[0]*a[1]/2 << endl;
}
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
    cin >> a[0];
    int ans;
    for(int i=1;i<1e6+1;i++){
        if(a[i-1]%2==0)a[i]=a[i-1]/2;
        else a[i]=3*a[i-1]+1;
        if(b[a[i]]>0||a[i]==a[0]){
            ans=i; break;
        }
        b[a[i]]=i;
    }
    cout << ans+1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
int h[101];
int main(){
    int n;
    cin >> n;
    int MAX=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> h[i];
        MAX=max(h[i],MAX);
    }
    int tmp;
    for(int i=1;i<=MAX;i++){
        if(h[0]>=i)tmp=1;
        else tmp=0;
        for(int j=1;j<n;j++){
            if(h[j-1]<i&&h[j]>=i)tmp++;
        }
        ans+=tmp;
    }
    cout << ans << endl;
}

//priority_queueつかえばよかったなぁ。
//まあできたのなら、よし！
#include <bits/stdc++.h>
using namespace std;

pair<int64_t,int> p[100005];
map<int,int> c;
map<int,int> w;
int main(){
    int n,k;
    cin >> n >> k;
    int t;
    int64_t d;
    int64_t whole=0;
    for(int i=0;i<n;i++){
        cin >> t >> d;
        p[i]=make_pair(d,t);
        if(w[t]==0)whole++;
        w[t]++;    
    }
    sort(p,p+n);
    int64_t ans=0;
    int64_t var=0;
    for(int i=0;i<k;i++){
        ans+=p[n-1-i].first;
        c[p[n-1-i].second]++;
        if(c[p[n-1-i].second]==1)var++;
    }
    ans+=var*var;
    int loop=min(k-var,whole-var);
    if(loop==0)cout << ans <<endl;
    else{
        vector<int64_t> L;
        vector<int64_t> S;
        int j=0;
        for(int i=0;i<k;i++){
            if(c[p[n-k+i].second]>1){
                L.push_back(p[n-k+i].first);
                c[p[n-k+i].second]--;
                j++;
            }
            if(j==loop)break;
        }
        loop=min(j,loop);
        j=0;
        for(int i=0;i<n-k;i++){
            if(c[p[n-k-1-i].second]==0){
                S.push_back(p[n-k-1-i].first);
                c[p[n-k-1-i].second]++;
                j++;
            }
            if(j==loop)break;
        }
        loop=min(j,loop);
        int64_t neo=ans;
        int64_t tmp=0;
        for(int i=1;i<loop+1;i++){
            tmp+=(S.at(i-1)-L.at(i-1));
            neo=max(neo,ans+tmp+2*var*i+i*i);
        }
        cout << neo << endl;
    }
}