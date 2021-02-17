#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >>a >> b;
    cout << max(a+b,max(a-b,a*b)) << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int x[27];
    int y[27];
    int ans=0;
    for(int i=1;i<n;i++){
        int tmp=0;
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        for(int j=0;j<i;j++)x[(s[j]-'a')]++;
        for(int j=i;j<n;j++)y[(s[j]-'a')]++;
        for(int j=0;j<26;j++)if(x[j]>0 && y[j]>0)tmp++;
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
int e[300005];
int w[300005];
int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        w[i+1]=w[i]+(s[i]=='W');
        e[n-i-1]=e[n-i]+(s[n-i-1]=='E');
    }
    int ans=1e9;
    for(int i=0;i<n;i++){
        ans=min(ans,w[i]+e[i+1]);
    }
    cout << ans << endl;
}

//xorの逆元はxorで計算できる
//累積xorはxorで計算できる
//ならしゃくとれるやん？
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long long int r=0;
    long long int p=a[0]; long long int x=a[0];
    long long int ans=0;
    for(long long int l=0;l<n;l++){
        while(p==x && r<n){
            r++;
            if(r<n){
                p+=a[r]; x^=a[r];
            }
        }
        ans+=(r-l);
        p-=a[l]; x^=a[l];
    }
    cout << ans;
}