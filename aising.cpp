#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,d;
    cin >> l >> r >> d;
    int ans=0;
    for(int i=l;i<=r;i++){
        if(i%d==0)ans++;
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i%2==0 && a[i]%2==1)ans++;
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int x=1;x<=100;x++){
        for(int y=1;y<=100;y++){
            for(int z=1;z<=100;z++){
                mp[x*x+y*y+z*z+x*y+y*z+z*x]++;
            }
        }
    }
    for(int i=1;i<=n;i++)cout << mp[i] << endl;
}
#include<bits/stdc++.h>
using namespace std;
long modpow(long a, long b,long mod){
	long res = 1;
	while (b > 0){
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}
int main(){
    int n;
    string s;
    cin >> n >> s;
    int one=0;
    for(int i=0;i<n;i++)if(s[i]=='1')one++;
    long plus[n+1];
    long minus[n+1];
    long sum_plus=0;
    long sum_minus=0;
    for(long i=0;i<n;i++){
        if(one!=n){
            plus[i]=modpow(2L,i,(long)(one+1));
            if(s[n-1-i]=='1')sum_plus=(sum_plus+plus[i])%((long)(one+1));
        }
        if(one>1){
            minus[i]=modpow(2L,i,(long)(one-1));
            if(s[n-1-i]=='1')sum_minus=(sum_minus+minus[i])%((long)(one-1));
        }
    }
    for(int i=0;i<n;i++){
        long tmp;
        int ans=0;
        if(s[i]=='0'){
            tmp = (sum_plus + plus[n-1-i])%((long)(one+1));
            ans++;
            while(tmp>0){
                tmp = tmp % __builtin_popcount((int)tmp);
                ans++;
            }
            cout << ans << endl;
        }
        else{
            if(one==1)cout << 0 << endl;
            else{
            tmp = (sum_minus + one - 1 - minus[n-1-i])%((long)(one-1));
            ans++;
            while(tmp>0){
                tmp = tmp % __builtin_popcount((int)tmp);
                ans++;
            }
            cout << ans << endl;
            }
        }
    }
}

//EFともに解きなおす価値のある問題
//vectorだったらmakepairしなくても時価に行ける(emplaceなら)
//いわゆるタスクスケジューリングマトロイドで、締め切りに近いやつから優先度付きqに順に詰めてって
//ただしオーバーしたときはqの中にある中でちっさいやつを消して詰めていくスタイル。
//↑このキューのおかげで無駄がなくなっている
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        long long int ans=0;
        vector<pair<int,long long int> > left;
        vector<pair<int,long long int> > right;       
        for(int j=0;j<n;j++){
            int k;
            long long int l,r;
            cin >> k >> l >> r;
            k;
            if(l>r){
                ans+=r;
                left.emplace_back(k,l-r);
            }
            else if(r>l){
                ans+=l;
                right.emplace_back(n-k,r-l);
            }
            else ans+=l;
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        priority_queue<long long int,vector<long long int>,greater<long long int>> q;
        for(auto u:left){
            q.emplace(u.second);
		    ans+=u.second;
		    while(q.size()>u.first) ans-=q.top(), q.pop();
        }
        while(!q.empty())q.pop();
        for(auto u:right){
            q.emplace(u.second);
		    ans+=u.second;
		    while(q.size()>u.first) ans-=q.top(), q.pop();
        }
        cout << ans << endl;
    }
}



//書き方自体参考になるので残しておく
lint solve(vector<pair<int,int>> a){
	sort(a.begin(),a.end());
	lint ans=0;
	priority_queue<int,vector<int>,greater<>> Q;
	for(auto [k,d]:a){
		Q.emplace(d);
		ans+=d;
		while(Q.size()>k) ans-=Q.top(), Q.pop();
	}
	return ans;
}


