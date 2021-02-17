#include <bits/stdc++.h>
using namespace std;

int main(){
    int r;
    cin >> r;
    cout << r*r << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    if(N%2==1)cout << "No" << endl;
    else{
    int i;
    int flag = 0; 
    for(i=0;i<N/2;i++)if(S[i]!=S[i+N/2])flag++;
    if(flag>0)cout << "No" << endl;
    else{cout << "Yes" << endl;}
    }
}

//nextperしようとしたのは完全に方針ミス
//こういうミスをなくして問題文をおちついてながめよう

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int x[N],y[N];
    int i,j;
    double ans=0;
    double tmp;
    for(i=0;i<N;i++)cin >> x[i] >> y[i];
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
        tmp=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
        ans+=tmp;
    }}
    cout << fixed << setprecision(16);
    cout << (double)ans*2.0/(N*1.0) << endl;
    }

//型を合わせてもダメならコーナーケースがどこならでるか具体的な数字で考えよ
#include <bits/stdc++.h>
using namespace std;

const long int mod=1e9+7;
long modpow(long x, long n){
    long res=1;
    for(; n>0; n>>=1) {
        if (n&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}
long nCr(long n, long r){
    long res=1;
    for(long int i=0; i<r; ++i) res=res*(n-i)%mod;
    for(long int i=1; i<=r; ++i) res=res*modpow(i, mod-2)%mod;
    return res;
}
int main(){
    long int X,Y;
    cin >> X >> Y;
    if((X+Y)%3!=0)cout << 0 << endl;
    else{
        long int dev = 3;
        long int num = (X+Y)/dev;
        long int x = X-num;
        long int y = Y-num;
        if(x<0 || y<0)cout << 0 << endl;
        else{cout << nCr(num,x)<<endl;}
    }
}

//せっかく値が小さいんだからメモ化してなにかを進めてほしかったことを組みとるべき
//最後に食べる料理だけ別枠でそれ以外についてはナップザックという曲者
//そこで最後以外を食べるためのナップザック+最後の形に持ち込む
//そのために今回は1~i番目とi+1~N番目に分けてDP
//というのが一つの手
//もうひとつは貪欲法的に最後はどうせ一番時間かかるやつっしょ、とソートして決め打ち
//もう一つは最後に食べるものをflagで管理するもの(汎用性がたかい考え方)

#include <bits/stdc++.h>
using namespace std;
const int MAX=6005;

int dp[MAX][2];
int main(){
    int N,T;
    cin >> N >> T;
    int i,j;
    int ans=0;
    int tmp;
    int a,b;
    for(i=0;i<N;i++){
        cin >> a >> b;
        for(j=T-1;j>=0;j--){
            if(j+a<=T-1){
                dp[j+a][0]=max(dp[j+a][0],dp[j][0]+b);
                dp[j+a][1]=max(dp[j+a][1],dp[j][1]+b);
                }
            dp[j][1]=max(dp[j][1],dp[j][0]+b);
            }
        }
    for(i=0;i<MAX;i++)if(dp[i][1]>ans)ans=dp[i][1];
    cout << ans << endl;
}