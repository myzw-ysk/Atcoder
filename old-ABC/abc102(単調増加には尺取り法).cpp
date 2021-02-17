#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n%2==0)cout << n << endl;
    else cout << 2*n << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    cout << abs(a[n-1]-a[0]) << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    long long int a[n];
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        cin >> a[i];
        a[i] -= (i+1);
        sum += a[i];
    }
    sort(a,a+n);
    long long int tmp=0;
    long long int ans=1e18;
    for(long long int i=0;i<n;i++){
        tmp += a[i];
        ans=min(ans,sum+(2*(i+1)-n)*a[i]-2*tmp);
    }
    cout << ans << endl;
}

//単調増加にはにぶたん以外に尺取りがある。
//分けてからの計算量は実はたかが知れているからにブタンするまでもない
//単調増加には尺取りのほうが鉄板
#include<bits/stdc++.h>
using namespace std;
long long int s[200005];
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }
    int x,y;
    long long int ans=1e18;
    long long int SUMA,SUMB,SUMC,SUMD;
    x=0; y=2;
    for(int i=2;i<n-1;i++){
        while(s[i]-s[x]>s[x])x++;
        while(s[n]-s[y]>s[y]-s[i])y++;
        for(int j=0;j<2;j++)for(int k=0;k<2;k++){
            SUMA=s[x-j]; SUMB=s[i]-s[x-j];
            SUMC=s[n]-s[y-k]; SUMD=s[y-k]-s[i];
            ans=min(ans,max(max(SUMA,SUMB),max(SUMC,SUMD))-min(min(SUMA,SUMB),min(SUMC,SUMD)));
        }
    }
    cout << ans << endl;
}