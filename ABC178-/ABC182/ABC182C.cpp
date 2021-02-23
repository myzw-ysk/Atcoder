#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<int,int> mp;
    for(int i=0;i<s.length();i++)mp[(s[i]-'0')%3]++;
    if(s.length()<3 && s.length()==mp[1])cout << -1;
    else if(s.length()<3 && s.length()==mp[2])cout << -1;
    else{
        int tmp = (max(mp[1],mp[2])-min(mp[1],mp[2]))%3;
        if(mp[1]>mp[2] && tmp==2 && mp[2]>0)tmp=1;
        if(mp[2]>mp[1] && tmp==1 && mp[1]>0)tmp=1;
        cout << tmp;
    }
}