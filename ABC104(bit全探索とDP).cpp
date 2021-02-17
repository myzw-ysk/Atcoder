#include<bits/stdc++.h>
using namespace std;
int main(){
    int r;
    cin >> r;
    if(r<1200)cout << "ABC" << endl;
    else if(r<2800)cout << "ARC" << endl;
    else cout << "AGC" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    if(S[0]!='A'){
        cout << "WA" << endl;
        return 0;
    }
    else{
        int flag=0;
        int flag2=0;
        for(int i=1;i<S.length();i++){
            if(i>=2 && i<S.length()-1 && S[i]=='C')flag++;
            else if((int)(S[i]-'a')<0 || (int)(S[i]-'a')>26)flag2++;
        }
        if(flag!=1 || flag2>0)cout << "WA" << endl;
        else cout << "AC" << endl;
    }
}


//全完しないで手を付けるのは最も高いやつだけだからそれ以外をbit全探索すればよい
#include<bits/stdc++.h>
using namespace std;

int main(){
    int d,g;
    cin >> d >> g;
    pair<int,int> p[d];
    int sum[d];
    for(int i=0;i<d;i++){
        cin >> p[i].first >> p[i].second;
        sum[i]=(i+1)*100*p[i].first+p[i].second;
    }
    int ans=1e9;
    int tmp;
    int count;
    for(int i=0;i<(1<<d);i++){
        tmp=0;
        count=0;
        for(int j=0;j<d;j++)if(i & (1<<j)){
            tmp+=sum[j];
            count+=p[j].first;
        }
        if(tmp<g){
            for(int j=d-1;j>=0;j--){
                if(!(i & (1<<j))){
                    count+=min((g-tmp+j*100)/((j+1)*100),p[j].first);
                    tmp+=min(g-tmp,p[j].first*(j+1)*100);
                    break;
                }
            }
        }
        if(tmp>=g)ans=min(count,ans);
    }
    cout << ans;
}

#include<bits/stdc++.h>
using namespace std;

long long int dp[100005][4];
const long long int mod=1e9+7;
int main(){
    string S;
    cin >> S;
    long long int ans=0;
    dp[0][0]=1;
    for(int i=0;i<S.length();i++){
        if(S[i]=='A'){
            for(int j=0;j<4;j++)(dp[i+1][j] += dp[i][j])%=mod;
            (dp[i+1][1] += dp[i][0])%=mod;
        }
        else if(S[i]=='B'){
            for(int j=0;j<4;j++)(dp[i+1][j] += dp[i][j])%=mod;
            (dp[i+1][2] += dp[i][1])%=mod;
        }
        else if(S[i]=='C'){
            for(int j=0;j<4;j++)(dp[i+1][j] += dp[i][j])%=mod;
            (dp[i+1][3] += dp[i][2])%=mod;
        }
        else{
            for(int j=0;j<4;j++){
                (dp[i+1][j] += 3 * dp[i][j])%=mod;
                if(j<3)(dp[i+1][j+1] += dp[i][j])%=mod;
            }
        }
    }
    cout << dp[S.length()][3] << endl;
}