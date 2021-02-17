#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a%2==1 && b%2==1)cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    string s,t;
    int n;
    cin >> n;
    cin >> t;
    mp[t]++;
    int flag=0;
    for(int i=1;i<n;i++){
        cin >> s;
        if(s[0]!=t[t.length()-1] || mp[s]>0)flag++;
        mp[s]++;
        t=s;
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}

#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y){
 long long int tmp;
 long long int r;
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
    int n,x;
    cin >> n >> x;
    int a;
    int b[n];
    for(int i=0;i<n;i++){
        cin >> a;
        b[i]=abs(a-x);
    }

    if(n>1){
    int ans=gcd(b[0],b[1]);
    for(int i=2;i<n;i++)ans=gcd(ans,b[i]);
    cout << ans << endl;
    }
    else cout << b[0] << endl;
}

//この解法は天才すぎる
//結局ひとふでがきに沿って操作していって、奇数の時だけ拾って、いらないときはすてる
//別に最速であることは求められていないので網羅的にできるこの手が最強
#include<bits/stdc++.h>
using namespace std;
int a[505][505];
vector<pair<pair<int,int>,pair<int,int>>> ans;

int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> a[i][j];
    int i=0; int j=0;
    int solve=0;
        while(i<h && j>=0 && j<w){
            if(i==h-1 && ((i%2==0 && j==w-1) || (i%2==1 && j==0)) )break;
            else if(i%2==0 && j<w-1){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i,j+1)));
                    a[i][j+1]++;
                }
                j++;
            }
            else if(i%2==0 && j==w-1){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
                    a[i+1][j]++;
                }
                i++;
            }
            else if(i%2==1 && j>0){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i,j-1)));
                    a[i][j-1]++;
                }
                j--;
            }
            else if(i%2==1 && j==0){
                if(a[i][j]%2==1){
                    solve++;
                    ans.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
                    a[i+1][j]++;
                }
                i++;
            }            
        }
    cout << ans.size() << endl;
    for(auto u:ans)cout << u.first.first+1 << " " << u.first.second+1 << " " << u.second.first+1 <<" "<< u.second.second+1 << endl;
}

//天才解法:全部恥に寄せて、恥の時は下に寄せる
#include <cstdio>
int h, w, k, x[505][505];
int a[250005],b[250005],c[250005],d[250005];
int main() {
	int i, j;
	scanf("%d%d", &h, &w);
	for(i=1; i<=h; i++) for(j=1; j<=w; j++) scanf("%d", &x[i][j]);
	for(i=1; i<=h; i++) for(j=1; j<=w; j++) if(x[i][j]%2) {
		if(j!=w) x[i][j+1]++, a[k]=i, b[k]=j, c[k]=i, d[k]=j+1, k++;
		else if(i!=h) x[i+1][j]++, a[k]=i, b[k]=j, c[k]=i+1, d[k]=j, k++;
	}
	printf("%d\n", k);
	for(i=0; i<k; i++) printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
	return 0;
}

//着眼点としては結局最短である必要がないんだから奇数のものを一か所に集めていこうというのが大事だった