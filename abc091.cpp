#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b<c)cout << "No" << endl;
    else cout << "Yes" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    int n,m;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> s;
        mp[s]--;
    }
    int ans=0;
    for(auto u:mp)ans=max(ans,u.second);
    cout << ans << endl;
}
//xが小さいものから順に見ていくときにもう一方はyが大きいものから順に見ていけば
//小さいものからみていったうえで大きいものからもう一方は消せるのはアドが最大という考え方
#include<bits/stdc++.h>
using namespace std;
int c[105];
int main(){
    int n;
    cin >> n;
    pair<int,int> a[n];
    pair<int,int> b[n];
    for(int i=0;i<n;i++){
        cin >> a[i].second >> a[i].first;
        a[i].first *= -1;
    }
    for(int i=0;i<n;i++)cin >> b[i].first >> b[i].second;
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i].second<b[j].first && -a[i].first<b[j].second && c[j]==0){
                c[j]++;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;