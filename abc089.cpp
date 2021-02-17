#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << n/3 << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<char,int> mp;
    char c;
    for(int i=0;i<n;i++){
        cin >> c;
        mp[c]++;
    }
    int ans=0;
    for(auto u:mp)ans++;
    if(ans==3)cout << "Three";
    else cout << "Four";
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char,long long int> mp;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        mp[s[0]]++;
    }
    long long int ans=0;
    vector<char> v = {'M','A','R','C','H'};
    for(auto u:v){
        for(auto x:v){
            for(auto y:v){
                if(u!=x && u!=y && x!=y)ans += mp[u]*mp[x]*mp[y];
            }
        }
    }
    ans /= 6;
    cout << ans;
}

//dfsをかいてみて気づく、これ、累積和でよくね？
//dfsで無駄が出る場合もある
#include<bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;
long long int c[90005];
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    int a[h+1][w+1];
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        cin >> a[i][j];
        mp[a[i][j]]=make_pair(i,j);
    }
    for(int i=d+1;i<=h*w;i++){
        c[i]=c[i-d]+abs(mp[i].first-mp[i-d].first)+abs(mp[i].second-mp[i-d].second);
    }
    int q,l,r;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        cout << c[r]-c[l] << endl;
    } 
}