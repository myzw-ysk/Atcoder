#include<bits/stdc++.h>
using namespace std;
int main(){
    int P,Q,R;
    cin >> P >> Q >> R;
    cout << min(min(P+Q,Q+R),R+P) << endl;
}
#include<bits/stdc++.h>
using namespace std;
int s[105];
int main(){
    int N;
    cin >> N;
    int w;
    int ans=1e9;
    int i;
    for(i=0;i<N;i++){
        cin >> w;
        s[i+1]=s[i]+w;}
    for(i=0;i<N;i++)ans=min(ans,abs(s[N]-2*s[i]));
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

const long long int mod=1e9+7;
long long int dp[100005];
int main(){
    int N,M;
    cin >> N >> M;
    int a;
    int i,j;
    for(i=0;i<M;i++){
        cin >> a;
        dp[a]=-1;}
    dp[0]=1;
    for(i=0;i<N;i++){
        if(dp[i+1]>=0 && dp[i]>0)dp[i+1]=(dp[i+1]+dp[i])%mod;
        if(dp[i+2]>=0 && dp[i]>0)dp[i+2]=(dp[i+2]+dp[i])%mod;
    }
    cout << dp[N] << endl;
}

#include <bits/stdc++.h>
using namespace std;

int tate[2005][2005];
int yoko[2005][2005];

int main(){
	int H,W;
    cin >> H >> W;
	char c[H][W];
    int i,j,k,l;
    int ans=0;
    int tmp;
    for(j=0;j<H;j++)for(i=0;i<W;i++)cin >> c[j][i];
    for(i=0;i<H;i++){
        tmp=0;
        for(j=0;j<W;j++){
            if(c[i][j]=='.')tmp++;
            else tmp=0;
            yoko[i][j]=tmp;
            }
        }
    for(i=0;i<H;i++){
        j=W-1;
        while(j>0){
            if(yoko[i][j]>yoko[i][j-1]){
                k=yoko[i][j];
                for(l=j-k+1;l<j;l++)yoko[i][l]=k;
                j-=k;
            }
            else j--;
            }
        }
    for(i=0;i<W;i++){
        tmp=0;
        for(j=0;j<H;j++){
            if(c[j][i]=='.')tmp++;
            else tmp=0;
            tate[j][i]=tmp;
            }
        }
	for(i=0;i<W;i++){
        j=H-1;
        while(j>0){
            if(tate[j][i]>tate[j-1][i]){
                k=tate[j][i];
                for(l=j-k+1;l<j;l++)tate[l][i]=k;
                j-=k;
            }
            else j--;
            }
        }
    for(i=0;i<H;i++)for(j=0;j<W;j++)ans=max(ans,yoko[i][j]+tate[i][j]-1);
    cout << ans << endl;
}

//二項係数でなんとかしようと思ったのは方針ミス
//結局桁数は10^5おーだーなんだからここは桁DPがベター
//A+BがAXORBになるのがどちらも1とはならない時というのはみえてた
//あとは桁DPでありがちな展開の繰り上がり管理だけすればよし
//桁DPだとわかればべつにむずかしくは…

#include<bits/stdc++.h>
using namespace std;

const long int mod = 1e9+7;
long int dp[100005][2];

int main(){
    string S;
    cin >> S;
    int i,j;
    int L=S.length();
    dp[0][0]=1;
    dp[0][1]=2;
    for(i=0;i<L-1;i++){
        dp[i+1][0]=(dp[i][0]*3)%mod;
        if(S[i+1]=='1'){
            dp[i+1][1]=(dp[i][1]*2)%mod;
            dp[i+1][0]=(dp[i+1][0]+dp[i][1])%mod;
        }
        else dp[i+1][1]=dp[i][1];
    }
    cout << (dp[L-1][0]+dp[L-1][1])%mod << endl;
}