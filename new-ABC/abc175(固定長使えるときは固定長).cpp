#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s=="RRR")cout << 3 << endl;
    else if(s=="SRR" || s=="RRS")cout << 2 << endl;
    else if(s=="SSS")cout << 0 << endl;
    else cout << 1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int l[n];
    int ans=0;
    for(int i=0;i<n;i++)cin >> l[i];
    sort(l,l+n);
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if((l[i]+l[j]>l[k]) && (l[i]!=l[j]) && (l[j]!=l[k]))ans++;
            }
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int x,k,d;
    cin >> x >> k >> d;
    if((abs(x)/d)>=k){
        cout << abs(x)-k*d;
        return 0;
    }
    long long int tmp=abs(x)/d;
    if((k-tmp)%2==0)cout << abs(x)-tmp*d;
    else cout << abs(abs(x)-(tmp+1)*d);
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int k;
    cin >> n >> k;
    int p[n+5];
    p[0]=0;
    for(int i=1;i<=n;i++)cin >> p[i];
    long long int c[n+5];
    c[0]=0;
    for(int i=1;i<=n;i++)cin >> c[i];
    long long int ans= -1e18-5;
    for(int i=1;i<=n;i++){
        int next=i;
        long long int count=0;
        long long int tmp=0;
        long long int tmp_ans=0;
        long long int nokori;
        while((count==0) || (next!=i)){
            count++;
            tmp+=c[p[next]];
            if(count<=k)ans=max(ans,tmp);
            next=p[next];
        }
        tmp_ans=tmp*(k/count);
        nokori=k-((k/count)*count);
        long long int count2=0;
        if((k/count)>0)ans=max(ans,tmp_ans);
        while(count2<nokori){
            count2++;
            tmp_ans+=c[p[next]];
            next=p[next];
            ans=max(ans,tmp_ans);            
        }
        count2=0;
        if((k/count)>0){
            tmp_ans=tmp*((k/count)-1);
        while(count2<count){
            count2++;
            tmp_ans+=c[p[next]];
            next=p[next];
            ans=max(ans,tmp_ans);            
        }}
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
long long int dp[3001][3001][4];
long long int sc[3001][3001];
int main(){
    int R,C,k;
    cin >> R >> C >> k;
    int r,c;
    long long int v;
    for(int i=0;i<k;i++){
        cin >> r >> c >> v;
        r --; c--;
        sc[r][c]=v;
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            for(int m=0;m<4;m++){
                 if(sc[i][j]>0 && m<3){
                    dp[i][j+1][m+1]=max(dp[i][j][m]+sc[i][j],dp[i][j+1][m+1]);
                    dp[i+1][j][0]=max(dp[i][j][m]+sc[i][j],dp[i+1][j][0]);
                 }
                dp[i][j+1][m]=max(dp[i][j][m],dp[i][j+1][m]);
                dp[i+1][j][0]=max(dp[i][j][m],dp[i+1][j][0]);            
            }
        }
    }
    cout << dp[R][C-1][0];
}
#include <bits/stdc++.h>
using namespace std;
int main(){

}