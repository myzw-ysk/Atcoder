#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    if(a*n<=b)cout << a*n << endl;
    else cout << b << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s = to_string(n);
    int sum=0;
    for(int i=0;i<s.length();i++)sum+=(s[i]-'0');
    if(n%sum==0)cout << "Yes";
    else cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int f[n][5][2];
    int p[n][11];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<2;k++)cin >> f[i][j][k];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++)cin >> p[i][j];
    }
    int ans=-1e9;
    for(int i=1;i<(1 << 10);i++){
        int tmp=0;
        for(int j=0;j<n;j++){
            int count=0;
            for(int k=0;k<10;k++){
                if( ((i & (1 << k))>0) && f[j][k/2][k%2])count++;
            }
            tmp+=p[j][count];
        }
        ans=max(ans,tmp);
    }
    cout << ans;
}
//オシャンなgreedy解法
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin >> n >> c;
    int ans=1;//n=1のケースがあるからだ！
    pair<pair<int,int>,int> p[n];
    for(int i=0;i<n;i++)cin >> p[i].first.first >> p[i].first.second >> p[i].second;
    sort(p,p+n);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(p[0].first.second,p[0].second));
    for(int i=1;i<n;i++){
        vector<pair<int,int> > tmp;
        while(q.top().first<p[i].first.first && !q.empty())q.pop();
        while((q.top().first==p[i].first.first && q.top().second<=p[i].second) && !q.empty()){
            if(q.top().second<p[i].second)tmp.push_back(make_pair(q.top().first,q.top().second));
            q.pop();
        }
        for(auto u:tmp)q.push(u);
        q.push(make_pair(p[i].first.second,p[i].second));
        ans=max(ans,(int)q.size());
    }
    cout << ans;
}