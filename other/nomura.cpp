#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int n,a[N];
ll s[N],ans,no=1;
int main(){
	cin>>n;
	for (int i=0;i<=n;i++)cin>>a[i];
	for (int i=n;i>=0;i--)s[i]=s[i+1]+a[i];//末尾からの累積和
	for (int i=0;i<=n;i++){
		ans+=no;
		no=no-a[i];
		if (no<0){puts("-1");return 0;}
		no=min(no*2,s[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
//んん～これだったらちゃれんじしてもよかったような…
//先っちょがなんこあるかで管理