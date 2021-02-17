#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    cout << x+y/2 << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,a;
    cin >> n >> t >> a;
    double h;
    int ans=0;
    double tmp=1e9+1.0;
    for(int i=0;i<n;i++){
        cin >> h;
        if(abs((double)1.0*tmp-1.0*a)>abs(1.0*a-1.0*t+h*0.006)){
            ans=i+1;
            tmp=1.0*t-h*0.006;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int p,y;
    map<pair<int,int>,int> mp;
    pair<int,int> ans[m];
    vector<int> v[n+1];
    for(int i=0;i<m;i++){
        cin >> p >> y;
        mp[make_pair(p,y)]=i;
        v[p].push_back(y);
    }
    int it;
    for(int i=1;i<n+1;i++){
        it=1;
        sort(v[i].begin(),v[i].end());
        for(int u:v[i]){
            ans[mp[make_pair(i,u)]]=make_pair(i,it);
            it++;
        }
    }
    string S;
    for(int i=0;i<m;i++){
        it=10;
        for(int j=0;j<6;j++){
            S[5-j]=(ans[i].first%it)+'0';
            ans[i].first/=10;
        }
        for(int j=0;j<6;j++){
            S[11-j]=(ans[i].second%it)+'0';
            ans[i].second/=10;
        }
        for(int j=0;j<12;j++)cout << S[j];
        cout << endl;
    }
}
//なんとなくそんな気もしていたがDP...
//棒を置けるか同課の管理までしなきゃいけないのでDPとしてはかなり複雑
//棒の遷移まで含めて管理しているのがこのやり方
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int h, w, k;
int dp[105][10];

//dでそこに棒を置くかの管理をしている
void go(int a, int b, long long c, int d) {
	if (d >= w - 1)
		dp[a][b] = (dp[a][b] + c) % MOD;
	else {
		go(a, b, c, d + 1);
		if (d == b)
			go(a, b + 1, c, d + 2);
		else if (d + 1 == b)
			go(a, b - 1, c, d + 2);
		else
			go(a, b, c, d + 2);
	}
}

int main() {
	cin >> h >> k >> w;
	k--;
	dp[0][0] = 1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			go(i + 1, j, dp[i][j], 0);
	cout << dp[h][k] << endl;
	return 0;
}
