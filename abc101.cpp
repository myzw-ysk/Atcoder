#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+')ans++;
        else ans--;
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum=0;
    string s = to_string(n);
    for(int i=0;i<s.length();i++)sum += (s[i]-'0');
    if(n%sum==0)cout << "Yes" << endl;
    else cout << "No" << endl;
}
//結局1以外の要素を何回で全部つぶせるかに集約される
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    cout << (n-1)/(k-1)+((n-1)%(k-1)>0) << endl;
}