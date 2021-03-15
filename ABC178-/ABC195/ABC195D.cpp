#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    int w,v;
    pair<int,int> nimotu[n];
    for(int i=0;i<n;i++){
        cin >> w >> v;
        nimotu[i]=make_pair(v,w);
    }
    sort(nimotu,nimotu+n);
    int x[m];
    for(int i=0;i<m;i++)cin >> x[i];
    for(int i=0;i<q;i++){
        vector<int> tmp;
        int l,r;
        cin >> l >> r;
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i<l || i>r)tmp.push_back(x[i-1]);
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<n;i++){
            if(lower_bound(tmp.begin(),tmp.end(),nimotu[n-i-1].second) != tmp.end()){
                ans += nimotu[n-i-1].first;
                tmp.erase(lower_bound(tmp.begin(),tmp.end(),nimotu[n-i-1].second));
                if(tmp.empty())break;
            }
        }
        cout << ans << endl;
    }

}