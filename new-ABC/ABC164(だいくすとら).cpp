#include<bits/stdc++.h>
using namespace std;
int main(){
    int S,W;
    cin >> S >> W;
    if(W>=S)cout << "unsafe" << endl;
    else cout << "safe" << endl;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    if((C+B-1)/B<=(A+D-1)/D)cout << "Yes" << endl;
    else cout << "No" << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int i;
    string S;
    map<string,int> mp;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> S;
        mp[S]++;
    }
    int ans=0;
    for(auto u : mp)ans++;
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

long int c[2020];
int main(){
    string S;
    cin >> S;
    int N=S.length();
    int i,j;
    long int ans=0;
    long int pow=10;
    long int sum=S[N-1]-'0';
    c[sum]++;
    for(i=1;i<N;i++){
        sum=(sum+(S[N-1-i]-'0')*pow)%2019;
        c[sum]++;
        pow=(pow*10)%2019;
    }
    for(i=1;i<2019;i++)ans+=(c[i]*(c[i]-1))/2;
    ans+=c[0]+(c[0]*(c[0]-1))/2;
    cout << ans << endl;
}


#include<bits/stdc++.h>
using namespace std;
long long dp[53][2503];//町の数,銀貨の数
vector<pair<long long,pair<long long,long long> > >v[53]; //町の数だけ
int main(){
    long long n,m,s;
	cout >> n >> m >> s;
	s=min(s,n*50); //最大でもAの最大値×50しかいらないから
	while(m--){
		long long x,y,a,b;
        cin >> x >> y >> a >> b;
		v[x-1].push_back(make_pair(y-1,make_pair(-a,b)));//こちらは銀貨が減るからマイナス
		v[y-1].push_back(make_pair(x-1,make_pair(-a,b)));//つながってるまち,コイン,時間
	}
	memset(dp,31,sizeof(dp));
	for(long long i=0;i<n;i++){
		long long c,d;
        cin>>c>>d;
		v[i].push_back(make_pair(i,make_pair(c,d)));//銀貨が増えるからプラス
	}
	priority_queue<pair<long long,pair<long long,long long> > >Q;//ここに優先度付きキューを用意しておく大工の始まり
	Q.push(make_pair(0,make_pair(0,s)));//今の町、今の時間、今のコイン
	dp[0][s]=0;
	while(Q.size()){
		long long tm=Q.top().first;
        long long ct=Q.top().second.first;
        long long cn=Q.top().second.second;
        Q.pop();
		for(long long i=0;i<v[ct].size();i++){
			long long nct=v[ct][i].first;//次のまち
            long long ntm=tm-v[ct][i].second.second;//かかってる時間のマイナス(優先度付きの逆表現)
            long long ncoi=v[ct][i].second.first+cn;//次のコイン
			if(ncoi<0)continue;//妙なことになったらとばす
			if(ncoi>n*50)continue;//妙なことになったらとばす
			ncoi=min(ncoi,n*50);//ふえすぎたらここで戻す
			if(dp[nct][ncoi]>-ntm){//より早く行けるのがみつかったら更新する
				dp[nct][ncoi]=-ntm; 
				Q.push(make_pair(ntm,make_pair(nct,ncoi)));//つぎとして入れる
			}
		}
	}
	for(long long i=1;i<n;i++){
		long long ans=LONG_LONG_MAX; //とにかくでかい値の仮置き
		for(long long j=0;j<=n*50;j++)ans=min(ans,dp[i][j]);//ルートはコインの枚数がおぼえている…
		cout<<ans<<endl;
	}
}
