#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,g,b;
    cin >> r >> g >>b;
    if((g*10+b)%4==0)cout << "YES";
    else cout << "NO";
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >>a[i];
    sort(a,a+n);
    cout << a[n-1]-a[0]; 
}
//問題文をちゃんと読むこと。
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >>a[i];
        if(a[i]>3200)a[i]=3200;
        mp[(a[i]/400)]++;
    }
    int ans=0;
    for(int i=0;i<8;i++)ans+=(mp[i] > 0);
    cout << max(ans,1) << " " << ans + mp[8];
}
//ブラケットの扱いは山のイメージ
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tmp=0;
    int MIN=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(' && tmp>=0)tmp++;
        else if(s[i]=='(' && tmp<0){
            MIN-=tmp;
            tmp=1;
        }
        else tmp--;
    }
    if(tmp<0)MIN-=tmp;
    for(int i=0;i<MIN;i++)cout << "(";
    cout << s;
    for(int i=0;i<tmp;i++)cout << ")";
}