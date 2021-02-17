#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << (a+b+1)/2;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    sort(s.begin(),s.end());
    if(s<t)cout << "Yes";
    else cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<=n)mp[a[i]]++;
        else ans++;
    }
    for(int i=1;i<=n;i++){
        if(mp[i]>i)ans+=(mp[i]-i);
        else if(mp[i]<i)ans+=mp[i];
    }
    cout << ans;
}

//数の範囲が狭いならナップザック的なノリでDPしたればええやん？
//全パターンが無理ならナップザックしかない
//配列の添え字が0を下回る場合は素直に場合分けをしよう
#include<bits/stdc++.h>
using namespace std;
bool dp_x[8005][16005];
bool dp_y[8005][16005];
int main(){
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    long unsigned int i=0;
    int vx=0,vy=0;
    vector<int> v_x;
    vector<int> v_y;
    while(s[i]=='F' && i<s.length()){
        vx++;
        i++;
    }
    if(i==s.length()){
        if(vx==x && vy==y)cout << "Yes";
        else cout << "No";
        return 0;
    }
    int tmp_v=0;
    int tmp_s=0;
    while(i<s.length()){
        if(s[i]=='T'){
            if(s[i-1]=='F'){
                if(tmp_s%2==0)v_x.push_back(tmp_v);
                else v_y.push_back(tmp_v);
                tmp_v=0;
            }
            tmp_s++;
        }
        else tmp_v++;
        i++;
    }
    if(tmp_s%2==0)v_x.push_back(tmp_v);
    else v_y.push_back(tmp_v);
    dp_x[0][vx+s.length()]=true;
    dp_y[0][vy+s.length()]=true;
    for(i=1;i<=v_x.size();i++){
        for(int j=0;j<=2*s.length();j++){
            if(j-v_x[i-1]>=0)dp_x[i][j]=dp_x[i-1][j+v_x[i-1]]|dp_x[i-1][j-v_x[i-1]];
            else dp_x[i][j]=dp_x[i-1][j+v_x[i-1]];
        }
    }
    for(i=1;i<=v_y.size();i++){
        for(int j=0;j<=2*s.length();j++){
            if(j-v_y[i-1]>=0)dp_y[i][j]=dp_y[i-1][j+v_y[i-1]]|dp_y[i-1][j-v_y[i-1]];
            else dp_y[i][j]=dp_y[i-1][j+v_y[i-1]];
        }
    }
    if(dp_x[v_x.size()][x+s.length()]==true &&  dp_y[v_y.size()][y+s.length()]==true)cout << "Yes";
    else cout << "No";
}