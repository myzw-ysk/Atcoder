#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S=="SUN")cout << 7 << endl;
    else if(S=="MON")cout << 6 << endl;
    else if(S=="TUE")cout << 5 << endl;
    else if(S=="WED")cout << 4 << endl;
    else if(S=="THU")cout << 3 << endl;
    else if(S=="FRI")cout << 2 << endl;
    else if(S=="SAT")cout << 1 << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    int A[S.length()];
    for(int i=0;i<S.length();i++){
        A[i]=S[i]-'A';
        A[i] = (A[i]+N)%26;
        S[i] = 'A'+A[i];
    }
    cout << S << endl;
}

//1e9オーダーは全探索不可
//結果なんかうまくいったけどうまくいかなくてもおかしくない解法だった
//桁数を絞って、そこについて調べた
//単調増加を利用するのが味噌、二分探索がベスト
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int A,B,X;
    cin >> A >> B >> X;
    long long int i;
    long long int d=1;
    long long int tmp=1;
    long long int ans = 0;
    while(tmp<1e9+1){
        if(X>=A*tmp+B*d){
            tmp*=10;
            d++;
        }
        else{
            d--;
            break;
        }
    }
    if(d==0)cout << ans << endl;
    else{
        for(i=tmp/10;i<tmp;i++){
            if(i>1e9)break;
            else if(X>=A*i+B*d)ans=i;
            else break;
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector<int> v[MAX];
int c[MAX];
int col[MAX];
vector<pair<int,int>> eg;

int main(){
  int N;
	cin >> N;
  int a,b;
    queue<pair<int,int>> que;
	for(int i=0;i<N-1;i++){
		cin >> a >> b;
        eg.push_back(pair<int,int> (a-1,b-1)); //順番保存用
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
	}

  int K=0;
  map<pair<int,int>,int> I; //各エッジの色管理
  vector<int> cs(N,0); // color of edge between its parent

  vector<int> used(N,0);//,を打つのは初期値指定
  queue<int> que;//親ノードごとにBFSしていく、たしかにノードごとに見ていけば飛ばすことはないな
  used[0]=1;//0はもうみましたよマーク
  que.emplace(0);
  while(!que.empty()){
    int x=que.front();
    que.pop();
    if(K<(int)v[x].size()) K=v[x].size();
    int cur=1;
    for(int u:v[x]){
      if(used[u]) continue;//いれていればとばし
      if(cur==cs[x]) cur++;
      cs[u]=I[make_pair(u,x)]=I[make_pair(x,u)]=cur++;
      used[u]=1;
      que.emplace(u);
    }
  }
  cout<<K<<endl;
  for(auto p:vp) cout<<I[p]<<endl;
  return 0;
}


//累積和への着目と式変形という鉄板なんだけど…
//なんか±がうまくいかん…
//もう一回用リベンジ
#include<bits/stdc++.h>
using namespace std;
int cnt[200003],n,k;
long long ans;
map<int,int>mp;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cnt[i]=(cnt[i-1]+a-1)%k;
	}
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=k)mp[cnt[i-k]]--;
		ans+=mp[cnt[i]],mp[cnt[i]]++;
	}
	cout<<ans;
}

//ただのDFSではとけないこの問題…
//それだとN^2かかってしまう
//でめが小さい順ならば後ろででかいやつをつかっているとみるべき
//どうせ目の和はおんなじなんだからね
#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
vector<int> ans;

int main(){
	cin>>n>>m>>s;
	int j;
	for(int i=n;i>0;i-=j) {
		for(j=m;j>0;--j) {
			if(i-j<0||s[i-j]=='1') continue;
			ans.push_back(j);//とにかく後ろにでかいやつをガンガンつめていけばよい
			break;
		}
		if(j==0) {
			printf("-1");
			return 0;
		}
	}
	for(int i=ans.size()-1;i>-1;--i) printf("%d ",ans[i]);
}


