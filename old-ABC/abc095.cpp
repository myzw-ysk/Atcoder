#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans=0;
    for(int i=0;i<3;i++)if(S[i]=='o')ans++;
    cout << 700+100*ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    int m[n];
    int ans=n;
    for(int i=0;i<n;i++)cin >> m[i];
    for(int i=0;i<n;i++)x-=m[i];
    sort(m,m+n);
    ans += x/m[0];
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c)cout << a*x+b*y << endl;
    else{
        if(x<=y)cout << x*2*c+min((y-x)*b,(y-x)*2*c) << endl;
        else cout << y*2*c+min((x-y)*a,(x-y)*2*c) << endl;
    }
}

//ごたごたするのを逐一最大を取っておくことで解決
#include <bits/stdc++.h>
#define N 100010
#define INF 1e18
using namespace std;
long long n,k,x[N],v[N],a[N]={},b[N]={},c[N]={},d[N]={};
long long vtl=0,vtr=0,ans=-INF,i;
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++)cin>>x[i]>>v[i];
	for(i=0;i<n;i++){
		vtl+=v[i];
		vtr+=v[n-i-1];
		a[i+1]=max(a[i],vtl-x[i]);//片道版
		b[i+1]=max(b[i],vtl-x[i]*2);//往復版
		c[n-i-1]=max(c[n-i],vtr-(k-x[n-i-1]));
		d[n-i-1]=max(d[n-i],vtr-(k-x[n-i-1])*2);
	}
	for(i=0;i<=n;i++)ans=max(ans,max(a[i]+d[i],b[i]+c[i]));
	cout<<ans<<endl;
	return 0;
}
