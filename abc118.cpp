#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(b%a==0)cout << a+b << endl;
    else cout << b-a << endl;
}
#include <bits/stdc++.h>
using namespace std;
int ans[31];
int main(){
    int n,m;
    cin >> n >> m;
    int k;
    int a;
    for(int i=0;i<n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> a;
            ans[a-1]++;
        }
    }
    int count=0;
    for(int i=0;i<m;i++)if(ans[i]==n)count++;
    cout << count << endl;
}
#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
 int tmp;
 int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int ans;
    ans=gcd(a[0],a[1]);
    for(int i=2;i<n;i++)ans=gcd(ans,a[i]);
    cout << ans << endl;
}


//dpで直に答えを作ることはできなくても桁数は決めれる
//遷移の差でその数字が使えるのかを決め打ちできる、天才か？
//メモリ破壊されていて最後のほうの挙動がおかしい、負のアクセスや多重再帰は極力避ける
#include <bits/stdc++.h>
using namespace std;
int a[10]={0,2,5,5,4,5,6,3,7,6};
int b[10];
int dp[10005];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)cin >> b[i];
    sort(b,b+m);
    dp[1]=-1e9;
    for(int i=2;i<n+1;i++){
        for(int j=0;j<m;j++){
            if(i-a[b[j]]>=0)dp[i]=max(dp[i],dp[i-a[b[j]]]+1);
        }
        if(dp[i]==0)dp[i]=-1e9;
    }
    int num=0;
    int ma=n;
    int A;
    string S;
    while(num<dp[n]){
        for(int i=m-1;i>=0;i--){
            A=max(ma-a[b[i]],0);
            if(dp[A]==dp[ma]-1){
                S[num]=('0'+b[i]);
                ma-=a[b[i]];
                break;
            }}
        cout << dp[0] << endl;
        num++;
    }
    for(int i=0;i<num;i++)cout << S[i];       
}

