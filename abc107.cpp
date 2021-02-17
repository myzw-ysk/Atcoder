#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin >> n >> i;
    cout << n-i+1 << endl;
}
#include<bits/stdc++.h>
using namespace std;
char c[105][105];
int y[105];
int x[105];
int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> c[i][j];
    int flag=0;
    int rm=0;
    for(int i=0;i<h;i++){
        flag=0;
        for(int j=0;j<w;j++)if(c[i][j]=='.')flag++;
        if(flag==w)y[i]++;
    }
    for(int i=0;i<w;i++){
        flag=0;
        for(int j=0;j<h;j++)if(c[j][i]=='.')flag++;
        if(flag==h)x[i]++;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)if(y[i]==0 && x[j]==0)cout << c[i][j];
        if(y[i]==0)cout << endl;
    }
}

//0を無視して直に計算すれば早かった、手間取りすぎ…
#include<bits/stdc++.h>
using namespace std;
long long int x[100005];
int lower(int start,int end,long long int X){
    while(end-start>1){
        if(x[(start+end)/2]<X)start=(start+end)/2;
        else end=(start+end)/2;
    }
    return end;
}
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> x[i];

    if(x[0]>=0)cout << x[k-1] << endl;
    else if(x[n-1]<=0)cout << -x[n-k] << endl;
    else{
        int tmp=lower(0,n-1,0LL);
        long long int ans=1e18;
        for(int i=max(0,tmp-k);i<min(tmp+1,n-k+1);i++){
            if(x[i]>0)ans=min(ans,x[i+k-1]);
            else if(x[i+k-1]<0)min(ans,-x[i]);
            else ans=min(ans,x[i+k-1]-x[i]+min(abs(x[i]),abs(x[i+k-1])));
        }
        cout << ans << endl; 
    }
}


#include<bits/stdc++.h>
using namespace std;
//むりげー。