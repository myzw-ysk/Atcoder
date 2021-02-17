#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,W,h,w;
    cin >> H >> W;
    cin >> h >> w;
    cout << H*W-(H*w+h*W-h*w) << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,C;
    cin >> N >> M >> C;
    int B[M];
    for(int i=0;i<M;i++)cin >> B[i];
    int A[N][M];
    int tmp;
    int ans=0;
    for(int i=0;i<N;i++){
        tmp=C;
        for(int j=0;j<M;j++){
            cin >> A[i][j];
            tmp += A[i][j]*B[j];
        }
    if(tmp>0)ans++;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    pair<long long int,int> p[n];
    long long int ans=0;
    long long int a;
    int b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        p[i]=make_pair(a,b);
    }
    sort(p,p+n);
    int tmp=0;
    for(int i=0;i<n;i++){
        tmp+=p[i].second;
        if(tmp>=m){
            ans+=(p[i].second-(tmp-m))*p[i].first;
            break;
        }
        else ans+=p[i].second*p[i].first;
    }
    cout << ans << endl;
}
//複数の排他論理和は偶数個なら0奇数個なら1
//long longにしたい整数の後ろにはLL
#include <bits/stdc++.h>
using namespace std;
long long int a[45];
long long int b[45];
int main(){
    long long int A,B;
    cin >> A >> B;
        A--;
        long long int ans=0;
        for(long long int i=0;i<45;i++){
            if(i==0)a[0]=A%(1LL<<2);
            else a[i]=A%(1LL<<(i+1));
            if((1LL<<(i+1))>A)break;
        }
        for(long long int i=0;i<45;i++){
            if(i==0)b[0]=B%(1<<2);
            else b[i]=B%(1LL<<(i+1));
            if((1LL<<(i+1))>B)break;
        }
        long long int aa,bb;
        for(long long int i=0;i<45;i++){
            if(i==0){
            if(a[0]==1 || a[0]==2)aa=1;
            else aa=0;
            if(b[0]==1 || b[0]==2)bb=1;
            else bb=0;
            ans += (1<<0)*(aa^bb);
            }
            else{
                if(a[i]>=(1LL<<i))aa=(a[i]-(1LL<<i)+1)%2;
                else aa=0;
                if(b[i]>=(1LL<<i))bb=(b[i]-(1LL<<i)+1)%2;
                else bb=0;
                ans += (1LL<<i)*(aa^bb);
            }
        }
        cout << ans << endl;    
}