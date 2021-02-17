#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if(abs(x-a)<abs(x-b))cout << "A";
    else cout << "B";
}
#include<bits/stdc++.h>
using namespace std;
int c[26];
int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++)c[(s[i]-'a')]++;
    for(int i=0;i<26;i++){
        if(c[i]==0){
            cout << (char)('a'+i);
            return 0;
        }
    }
    cout << "None";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a;
    map<long long int,int> mp;
    for(int i=0;i<n;i++){
        cin >> a;
        a *= (-1);
        mp[a]++;
    }
    long long int tmp=0;
    for(auto u:mp){
        if(u.second>=4){
            if(tmp<0){
                cout << tmp*u.first;
                return 0;
            }
            else{
                cout << u.first*u.first;
                return 0;
            }
        }
        else if(u.second>=2){
            if(tmp<0){
                cout << tmp*u.first;
                return 0;
            }
            else tmp=u.first;
        }
    }
    cout << 0;
}
//DFSでグラフに変換するなんて高尚なことをしなくても
//くっつき方のパターンは数が知れているのだからDPライクな遷移を書けばとける
//緑でもDPは出ます。書き方をわすれていませんか？
//まずはここのケースをイメージするのはきょうプロのきほんです。
#include<bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
int n;
char c[2][55];

int main(){
    cin >> n;
    if(n==1){
        cout << 3;
        return 0;
    }
    char c[2][n];
    long long int ans=1;
    for(int i=0;i<2;i++)for(int j=0;j<n;j++)cin >> c[i][j];
    int j=0;
    while(j<n){
        if(j==0){
            if(c[0][0]==c[1][0]){
                ans*=3;
                j++;
            }
            else{
                ans*=6;
                j+=2;
            }
        }
        else{
            if(c[0][j]==c[1][j]){
                if(c[0][j-1]==c[1][j-1]){
                    ans*=2;
                    ans%=mod;
                    j++;
                }
                else j++;
            }
            else{
                if(c[0][j-1]==c[1][j-1]){
                    ans*=2;
                    ans%=mod;
                    j+=2;
                    }
                else{
                    ans*=3;
                    ans%=mod;
                    j+=2;                           
                    }
            }
        }
    }
    cout << ans;
}