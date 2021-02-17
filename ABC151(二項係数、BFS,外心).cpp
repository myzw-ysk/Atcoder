#A
次の文字を打つのは+1してやるでけでよい

#include <bits/stdc++.h>
using namespace std;
 
int main(){
char c;
 cin >> c;
 c += 1 ;
cout << c;
  return 0;
}


#B
条件をもらさないでくれ…

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int K;
 int M;
 cin >> N >> K >> M;
 int A[N-1];
 int i;
 for(i=0;i<N-1;++i){
   cin >> A[i];}
int count = 0;
 for(i=0;i<N-1;++i){
  count += A[i];
 }
 if(count>=M*N)cout << 0 << endl;
 else if(count+K>=M*N)cout << M*N-count << endl;
 else{
     cout << -1 << endl;
 }
}


#C
一度WAされたら条件の漏れがないか丁寧に問題文を読み直す。

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int M;
 cin >> N >> M;
 if(M==0)cout << 0 << " " << 0 << endl;
 else{
 int p[M];
 int a[N]={0};
 int b[N]={0};
 int i;
 for(i=0;i<M;++i){
     string ans;
   cin >> p[i] >> ans;
   if(ans=="AC")a[p[i]-1]++;
   if(ans=="WA" && a[p[i]-1]<1)b[p[i]-1]++;
   }
int count = 0;
int coun = 0;
 for(i=0;i<N;++i){
  if(a[i]>0){count++;
coun+=b[i];}
 }
cout << count << " " << coun << endl;
 }
}

//スタートをかえるごとにスコアをリセットしなきゃなところ以外は普通のDFS
#D
#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    char c[21][21];
    int check[21][21];
    int i,j;
    queue<pair<int,int>> que;
    cin >> H >> W;
    int ans = 0;
    for(i=0;i<H;i++)for(j=0;j<W;j++)cin >> c[i][j];
    for(i=0;i<H;i++)for(j=0;j<W;j++){
        if(c[i][j]=='#')continue;
        else{
        for(int k=0;k<H;k++)for(int l=0;l<W;l++)check[k][l]=-1e9;
        check[i][j]=0;
        que.push(pair<int,int> (i,j));
        	while(!que.empty()){
		        int x = que.front().first;
		        int y = que.front().second;
		        int dx[4] = {1,-1,0,0};
		        int dy[4] = {0,0,1,-1};
		        que.pop();
		        for(int k=0;k<4;k++){
			        if(c[x+dx[k]][y+dy[k]]=='.' && check[x+dx[k]][y+dy[k]]==-1e9){
				        check[x+dx[k]][y+dy[k]]=check[x][y]+1;
				        que.push(pair<int,int> (x+dx[k],y+dy[k]));
			    }
		        }
	        }
    for(int k=0;k<H;k++)for(int l=0;l<W;l++)if(check[k][l]>ans)ans=check[k][l];
    }}
    cout << ans << endl;
}



#E


#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int mod = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){

COMinit();

 long long int N;
 long long int K;
 cin >> N >> K;
 if(K==1)cout << 0 << endl;
 else{
 long long int a[N];
 long long int i;
 for(i=0;i<N;++i){
   cin >> a[i];
   }

sort(a,a+N);
long long int count = 0;
long long int com = 1;
 for(i=0;i<N-K+1;i++){
     count+=(((a[K-1+i]-a[N-K-i])*COM(i+K-1,K-1))%mod);
     count %= mod;
     com *= (K+i);
     com /= (i+1);
     com %= mod;
 }
cout << count%mod << endl;
 }
}


//外心の求め方
//あと外接円の半径を求めるだけだったら正弦と予言の組み合わせで行ける
//実際の解法は2つか3つと接するときに最大だからその中心点候補全部についてしらべればよい
//意外と簡単なので幾何は思いついたら計算法をぐぐるとよい
#include <bits/stdc++.h>
using namespace std;

int x[55],y[55];
double distance(int I,int J){
    return sqrt((x[I]-x[J])*(x[I]-x[J])+(y[I]-y[J])*(y[I]-y[J]));
}

int main(){
    int n;
    cin >> n;
    double ans=1e9;
    double tmp;
    double a,b,c;
    double A,B,C;
    queue<pair<double,double>> q;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            else{
                for(int k=0;k<n;k++){
                    if(i==k || j==k)q.push(make_pair((x[i]+x[j])/2.0,(y[i]+y[j])/2.0));
                    else{
                        a=distance(i,j);
                        b=distance(k,j);
                        c=distance(i,k);
                        if(a+b>c && a+c>b && b+c>a){
                            A=sin(2.0*acos((b*b+c*c-a*a)/(2.0*b*c)));
                            B=sin(2.0*acos((a*a+c*c-b*b)/(2.0*a*c)));
                            C=sin(2.0*acos((a*a+b*b-c*c)/(2.0*a*b)));
                            q.push(make_pair((A*x[k]+B*x[i]+C*x[j])/(A+B+C),(A*y[k]+B*y[i]+C*y[j])/(A+B+C)));
                        }
                    }
            }}
        }
    }
    while(!q.empty()){
        tmp=0;
        for(int i=0;i<n;i++)tmp=max(tmp,sqrt((x[i]-q.front().first)*(x[i]-q.front().first)+(y[i]-q.front().second)*(y[i]-q.front().second)));
        ans=min(tmp,ans);
        q.pop();
    }
    cout << fixed << setprecision(16);
    cout << ans << endl;
}