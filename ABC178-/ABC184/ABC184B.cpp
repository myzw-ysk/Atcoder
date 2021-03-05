#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    string s;
    cin >> s;
    int ans=x;
    for(int i=0;i<n;i++){
        if(s[i]=='o')ans++;
        if(s[i]=='x' && ans>0)ans--;
    }
    cout << ans;
}