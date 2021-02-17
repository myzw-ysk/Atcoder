//A
#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;

int dp[MAX];
int main(){
    int N;
    cin >> N;
    int i;
    int h[N];
    for(i=0;i<N;i++)cin >> h[i];
    for(i=0;i<N;i++){
        if(i==0)dp[i+1]=abs(h[i+1]-h[i])+dp[i];
        else{if(dp[i+1]>abs(h[i+1]-h[i])+dp[i])dp[i+1]=abs(h[i+1]-h[i])+dp[i];}
        dp[i+2]=abs(h[i+2]-h[i])+dp[i];
    }
    cout << dp[N-1] << endl;
}

//B
#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;

int dp[MAX];
int main(){
    int N,K;
    cin >> N >> K;
    int i,j;
    int h[N];
    for(i=0;i<N;i++)cin >> h[i];
    for(i=1;i<N+5;i++)dp[i]=1e9+7;
    for(i=0;i<N;i++)for(j=1;j<K+1;j++)if(dp[i+j]>abs(h[i+j]-h[i])+dp[i])dp[i+j]=abs(h[i+j]-h[i])+dp[i];
    cout << dp[N-1] << endl;
}

//c

#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;

int dp[MAX][3];
int main(){
    int N;
    cin >> N;
    int i,j;
    int a[3];
    for(i=0;i<N;i++){
        cin >> a[0] >> a[1] >> a[2];
        if(i==0)for(j=0;j<3;j++)dp[i][j]=a[j];
        else{
            dp[i][0]=a[0]+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=a[1]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=a[2]+max(dp[i-1][0],dp[i-1][1]);
            }}
    int ans=0;
    for(j=0;j<3;j++)if(ans<dp[N-1][j])ans=dp[N-1][j];
    cout << ans << endl;
}

//d//
//1回ずつしか選べないと考えるとかくのまあまあむずい
//ありうる遷移を全部重ね塗りするイメージかんぁ、明日Eで復習
#include <bits/stdc++.h>
using namespace std;
const int MAX=200005;

long long int dp[MAX];
int main(){
    int N,W;
    cin >> N >> W;
    long long int i,j;
    long long int ans=0;
    long long int w,v;
    for(i=0;i<N;i++){
        cin >> w >> v;
        for(j=W-w;j>=0;j--){
            if(dp[j+w]<v+dp[j])dp[j+w]=v+dp[j];
        }
    }
    cout << dp[W] << endl;
}

//E
//予想どおり価値ベースでdpするだけ
#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;

long long int dp[MAX];
int main(){
    long long int N,W;
    cin >> N >> W;
    long long int i,j;
    long long int ans=0;
    long long int w,v;
    long long int sum=0;
    for(i=1;i<MAX;i++)dp[i]=1e9+7;
    dp[0]=0;
    for(i=0;i<N;i++){
        cin >> w >> v;
        sum+=v;
        for(j=sum-v;j>=0;j--){
            if(dp[j+v]>w+dp[j])dp[j+v]=w+dp[j];
        }
    }
    for(i=1;i<MAX;i++)if(dp[i]<=W)ans=i;
    cout << ans << endl;
}

//F//
//ちげえよ！DPでできんだよ！！！最適アラインメント問題だよ
//https://qiita.com/_rdtr/items/c49aa20f8d48fbea8bd2
//https://naoya-2.hatenadiary.org/entry/20090328/1238251033
#include<bits/stdc++.h>
using namespace std;

const int MAX=3005;
int dp[MAX][MAX];
int main(){
	string s,t;
	cin >> s >> t;
	for(int i=0;i<s.size();i++)//まずはテーブル作り
		for(int j=0;j<t.size();j++)
			if(s[i]==t[j])
				dp[i+1][j+1]=dp[i][j]+1;
			else
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);//ジャンプがある前だったことだけ残す
	string ans;
	int i=s.size(),j=t.size();//後ろから飛んだとことを探しにいく
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){//一致した場合ひとつ前を探しに行く
			ans+=s[i-1];
			i--;
			j--;
		}else if(dp[i-1][j]>=dp[i][j-1])//ダメなら横にずれる
			i--;
		else//同様にずれる
			j--;
	}
	reverse(ans.begin(),ans.end());//逆引きしてるからひっくり返す
	cout<<ans<<endl;
}

//G//
//テーブルを作ってさおのノードから行ける最大値を記録していく感じ
//DFSでもいけそうな印象はある
#include<bits/stdc++.h>
using namespace std;

int N,M,X,Y
int dp[100010];
vector<int> e[100010];

int M(int i){
  if(dp[i]!=0) return dp[i];
  int s=e[i].size(),k=1;
  for(int j=0;j<N;j++)k=max(k,1+M(e[i][j]));
  dp[i]=k;
  return k;
}

int main(){
  cin>>N>>M;
  int i;
  for(i=0;i<M;i++){
      cin>>X>>Y;
      e[X].push_back(Y);}//有効だから一方向だけ
  int ans=0;
  for(i=1;i<N+1;i++)ans=max(ans,M(i));
  cout<<ans-1<<endl;
}

//H
//きかれているのが何通りか？だからDPがいいけど、これもDFSでとけそう
#include<bits/stdc++.h>
using namespace std;

long long int dp[1005][1005];
char S[1005][1005];
const long long int mod=1e9+7;
int main(){
    int i,j;
    int H,W;
    cin >> H >> W;
    for(i=0;i<H;i++)for(j=0;j<W;j++)cin >> S[i][j];
    dp[0][0]=1;
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            dp[i][j]%=mod;
            if(S[i+1][j]=='.')dp[i+1][j]+=dp[i][j];
            if(S[i][j+1]=='.')dp[i][j+1]+=dp[i][j];            
        }
    }
    cout << dp[i-1][j-1] << endl;
}

//i
//遷移が簡単、スタートの値を忘れないように気を付ける
#include<bits/stdc++.h>
using namespace std;

double dp[3005][3005];
int main(){
    int i,j;
    int N;
    cin >> N;
    double p[N];
    for(i=0;i<N;i++)cin >> p[i];
    dp[0][0]=1.00000;
    for(j=0;j<N;j++){
        for(i=0;i<j+1;i++){
            dp[i][j+1]+=dp[i][j]*(1-p[j]);
            dp[i+1][j+1]+=dp[i][j]*p[j];       
        }
    }
    double ans=0.00000;
    for(i=N/2+1;i<N+1;i++)ans+=dp[i][N];
    cout << fixed << setprecision(16);
    cout << ans << endl;
}

//j
//すべての数に目をつけるのはわるくないけど、それでは減り具合が管理できない
//ここでするべきは残りの寿司の数が何個の皿が何枚あるか
//しかも遷移を書くのもかなり難しい(が、上までわかれば遷移関係を落ち着いてかいてやるだけ)
//難しいのはループの回し方、またしてもメモか再帰
//https://qiita.com/drken/items/03c7db44ccd27820ea0d
#include<bits/stdc++.h>
using namespace std;

int N;
double dp[305][305][305];
int a[305];
int b[3];

double ans(int x,int y,int z){
    if(dp[x][y][z]>=0)return dp[x][y][z];//すでにメモ済み
    if(x==0 && y==0 && z==0) return 0.0;//全部0なら一回もやらんくてよい
    double res = 0.0;
    if(x>0)res+=ans(x-1,y,z)*x;
    if(y>0)res+=ans(x+1,y-1,z)*y;
    if(z>0)res+=ans(x,y+1,z-1)*z;
    res+=N;
    res*=1.0/(x+y+z);//式変形の結果
    return dp[x][y][z]=res;//結果のメモ
}

int main(){
    int i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> a[i];
        b[a[i]-1]++;
    }
    memset(dp, -1, sizeof(dp)); //初期化
    cout << fixed << setprecision(16);
    cout << ans(b[0],b[1],b[2]) << endl;
}

//k
//遷移のイメージはできたけど内容物をどうするかが…
//-1でだったら太郎の負け、1だったら勝ち、0は未記入で
#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5+10;
int dp[MAX];
int main(){
    int N,K,i,j;
    cin >> N >> K;
    int a[N];
    int flag;
    for(i=0;i<N;i++)cin >> a[i];
    for(i=0;i<a[0];i++)dp[i]=-1;
    for(i=a[0];i<K+1;i++){
        flag=0;
        for(j=0;j<N;j++){
            if(i<a[j])break;//領域外にでないようにちゃんと止める
            else if(dp[i-a[j]]==-1){
               flag++;
               break;
            }
            }
        if(flag>0)dp[i]=1;
        else{dp[i]=-1;} 
        }
    if(dp[K]==1)cout << "First" << endl;
    else cout << "Second" << endl;
}

//L
//両端から外すときはqequeを使おう
//だがしかし。毎回とにかくでかい値をとっていくだけでは勝てるとは限らない
//そこでやはりテーブルをつくるしかない
//どうdpをくむか？
//各区間について値がどうなるかを計算して拡張していく
//https://qiita.com/drken/items/4e1bcf8413af16cb62da
#include<bits/stdc++.h>
using namespace std;

long long int dp[3010][3010];
int main(){
    long long int N;
    cin >> N;
    long long int i,j;
    long long int a[N];
    for(i=0;i<N;i++)cin >> a[i];
    for(i=1;i<N+1;i++){//長さでループ
        for(j=0;j<N+1-i;j++){//ここまでの偶奇関係でif文にする
            if((N-i)%2==0)dp[j][i+j]=max(dp[j][j+i-1]+a[i+j-1],dp[j+1][i+j]+a[j]);
            else dp[j][i+j]=min(dp[j][j+i-1]-a[i+j-1],dp[j+1][i+j]-a[j]);
        }
    }
    cout << dp[0][N] << endl;
}

//M
//さっきとおなじような感じで部分的な区間での結果を出して広げていく
//始点をさっきみたいに広げる必要はないので0に固定してやればその分スペースが浮く
//あとは累積はで計算減らすのもネック
//が、なんか合わない… ずれるポイントはどこ…(コーナーがでた)
//https://scrapbox.io/esaka-sandbox/Educational_DP_Contest_%2F_DP_%E3%81%BE%E3%81%A8%E3%82%81%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88_-_M_-_Candies
#include<bits/stdc++.h>
using namespace std;

long long int dp[100005][101];
long long int DP[100005][101];
const long long int mod=1e9+7;
int main(){
    int N,K;
    cin >> N >> K;
    int i,j;
    int a[N];
    for(i=0;i<N;i++)cin >> a[i];
    for(i=0;i<N;i++){
        dp[0][i]=1;
        DP[1][i]=1;}
    for(i=1;i<K+1;i++){
        if(i<=a[0])dp[i][0]=1;
        DP[i+1][0]=dp[i][0]+DP[i][0];}
    for(i=1;i<K+1;i++){
        for(j=1;j<N;j++){
            dp[i][j]=(DP[i+1][j-1]-DP[max(0,i-a[j])][j-1])%mod;
            DP[i+1][j]=(dp[i][j]+DP[i][j])%mod;
            }
    }
    cout << dp[K][N-1] << endl;
}

//N
//これまた部分列の解(累積和)をだしてそこにさらに足していくスタイル
#include<bits/stdc++.h>
using namespace std;

long long int dp[405][405];
long long int sum[405];
int main(){
    int N;
    cin >> N;
    int i,j,k;
    long long int a[N];
    long long int tmp;
    for(i=0;i<N;i++)cin >> a[i];
    for(i=1;i<N+1;i++)sum[i] = sum[i-1] + a[i-1];
    for(i=1;i<N;i++){
        for(j=0;j<N-i;j++){
            tmp=0;
            for(k=0;k<i;k++){
                if(k==0)tmp=dp[j][j+k]+dp[j+k+1][j+i];
                else tmp=min(tmp,dp[j][j+k]+dp[j+k+1][j+i]);
            }
            dp[j][j+i]=sum[j+i+1]-sum[j]+tmp;
            }
        }
    cout << dp[0][N-1] << endl;
}

//O
//いわゆるビットDP
//遷移がややむずい
#include<bits/stdc++.h>
using namespace std;

long long int dp[(1 << 21)];
const long long int mod=1e9+7;
int main(){
    int N;
    cin >> N;
    int i,j,k;
    long long int a[N][N];
    for(i=0;i<N;i++)for(j=0;j<N;j++)cin >> a[i][j];
    for(i=0;i<(1 << N);i++){
        int pos = __builtin_popcount(i) - 1;//1の本数の数
        for(j=0;j<N;j++){
            if ((i & (1<<j)) && a[pos][j]){
                dp[i] += dp[i^(1<<j)];//XORでそれまでの分を足す
                dp[i] %= mod;
            }
        }
    }
    cout << dp[(1<<N)-1] << endl;
}


