#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << 1000*((n+999)/1000)-n << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << "AC x " << mp["AC"] << endl;
    cout << "WA x " << mp["WA"] << endl;
    cout << "TLE x " << mp["TLE"] << endl;
    cout << "RE x " << mp["RE"] << endl;    
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,K;
    cin >> h >> w >> K;
    char c[h][w];
    int ans=0;
    int tmp;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> c[i][j];
    for(int i=0;i<(1 << h);i++){
        for(int j=0;j<(1 << w);j++){
            tmp=0;
            for(int k=0;k<h;k++){
                for(int l=0;l<w;l++){
                    if( (i & (1 << k)) && (j & (1 << l)) )if(c[k][l]=='#')tmp++;
                }
            }
            if(tmp==K)ans++;
        }
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    priority_queue<long long int> q;
    q.push(a[n-1]);
    long long int ans=0;
    for(int i=n-2;i>=0;i--){
        ans += q.top();
        q.pop();
        q.push(a[i]);
        q.push(a[i]);
    }
    cout << ans;
}

//別解法は最後に符号合わせをやるもの、今回は非負にできるありきで高いものからとっていく
//そもそも府になる条件の見積もりが甘かった
//最後の条件はもう一方の方法だったら漏らしてないしいっちょういったんだなぁ
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    long long int mod=1e9+7;
    long long int ans=1;
    vector<long long int> plus;
    vector<long long int> minus;
    for(int i=0;i<n;i++){
        if(a[i]<0)minus.push_back(a[i]);
        else plus.push_back(a[i]);
    }
    if(n==k){
        int t=0;
        for(int i=0;i<k;i++){
            ans *= abs(a[i]);
            ans %= mod;
            if(a[i]<0)t++;
        }
        if(t%2==1 && ans!=0)cout << mod - ans;
        else cout << ans;
    }
    else if(a[n-1]<0 && k%2==1){
        for(int i=0;i<k;i++){
            ans *= abs(a[n-1-i]);
            ans %= mod;
        }
        cout << mod - ans;
    }
    else{
        int p;
        long unsigned int m;
        int count=0;
        p=plus.size()-1; m=0;
        while(count<k){
            while((m+1<minus.size() && p-1>=0) && count+2<=k){
                if(minus[m]*minus[m+1]>=plus[p]*plus[p-1]){
                ans *= ((minus[m]*minus[m+1])%mod);
                ans %= mod;
                m+=2;
                count+=2;
                }
                else break;
            }
            while(p<0 && count+1<=k){
                ans *= abs(minus[m]);
                ans %= mod;
                m++;
                count++;     
            }
            if(p==0 && (count<k && (k-count)%2==0)){
                while(count+1<=k){
                    ans *= abs(minus[m]);
                    ans %= mod;
                    m++;
                    count++;     
                }                
            }
            if(count+1<=k && p>=0){
                ans *= plus[p];
                ans %= mod;
                p--;
                count++;                
            }
        }
        cout << ans;
    }
}

//木構造では連結成分の数=頂点の数-辺の数
//これを知っているかどうかだけでとけるかきまってしまう問題…
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int v=0,e=0;
    for(int i=1;i<=n;i++)v+=(long long int)(i)*(n-i+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        if(a>b)swap(a,b);
        e+=(long long int)(a)*(n-b+1);//aを含むようなのは1~aでbを含むのはb~n
    }
    cout << v - e;
}