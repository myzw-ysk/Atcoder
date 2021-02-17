#include<bits/stdc++.h>
using namespace std;
int main(){
    int K,A,B;
    cin >> K;
    cin >> A >> B;
    int a = (A-1)/K;
    int b = B/K;
    if(b-a>0)cout << "OK" << endl;
    else cout << "NG" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x;
    cin >> x;
    long long int ans = 0;
    long long int mon = 100;
    while(mon<x){
        mon = 1.01*mon;
        ans++;
    }
    cout << ans << endl;
}
//全探索ってわかっててもどこで全探索したらいいのかわからないつらさ
#include<bits/stdc++.h>
using namespace std;
int N,M,Q;
int a[50],b[50],c[50],d[50];
int ans;
int A[10];
void dfs(int id,int pre){
    //終了条件(恥まで到達)
	if(id==N){
		int now=0;
		for(int i=0;i<Q;i++)if(A[b[i]-1]-A[a[i]-1]==c[i])now+=d[i];
		if(ans<now)ans=now;
	}
	else{
        //その場所の値を決めて次の値を決めるDFSをする
		for(int i=pre;i<=M;i++){
			A[id]=i;
			dfs(id+1,i);
		}
	}
}
int main(){
	cin>>N>>M>>Q;
	for(int i=0;i<Q;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
	dfs(0,1);
	cout<<ans<<endl;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b,n;
    cin >> a >> b >> n;
    long long int ans;
    if(b==1)cout << 0 << endl;
    else if(n>=b){
        double fl=(double)((b-1)*1.0/b*1.0);
        fl *= (a*1.0);
        ans = fl; 
    cout << ans << endl;        
    }
    else{
        double fl=(double)(n*1.0/b*1.0);
        fl *= (a*1.0);
        ans = fl; 
    cout << ans << endl;
    }
}
