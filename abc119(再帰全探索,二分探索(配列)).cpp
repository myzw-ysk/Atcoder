#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    if((S[0]-'0')*1000+(S[1]-'0')*100+(S[2]-'0')*10+(S[3]-'0')<2019)cout << "Heisei" << endl;
    else if((S[0]-'0')*1000+(S[1]-'0')*100+(S[2]-'0')*10+(S[3]-'0')==2019 && (S[5]-'0')*10+(S[6]-'0')<5)cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long double ans=0;
    long double x;
    string S;
    for(int i=0;i<n;i++){
        cin >> x >> S;
        if(S=="JPY")ans+=x;
        else ans += 380000.0*x;
    }
    cout << fixed << setprecision(16);
    cout << ans << endl;
}

//究極的にはすべての竹をどの竹に使うのかの4通りしかない。
//竹が少ないことに着目して全探索する
#include <bits/stdc++.h>
using namespace std;
int l[9];
int n,a,b,c;
int ans;
int dfs(int number,int A,int B,int C){
    if(number==n){
        if(A>0 && B>0 && C>0)ans=abs(A-a)+abs(B-b)+abs(C-c)-30;
        else ans=1e9;
        return ans;
    }
    else{
        if(number==0)ans=1e9;
        int ans1=dfs(number+1,A+l[number],B,C)+10;
        int ans2=dfs(number+1,A,B+l[number],C)+10;
        int ans3=dfs(number+1,A,B,C+l[number])+10;
        int ans4=dfs(number+1,A,B,C);
        return min(min(min(ans1,ans2),ans3),ans4);
    }
}

int main(){
    cin >> n >> a >> b >> c;
    for(int i=0;i<n;i++)cin >> l[i];
    cout << dfs(0,0,0,0) << endl;
}

#include <bits/stdc++.h>
using namespace std;

long long int s[100005],t[100005];
int lower_s(int start,int end,long long int x){
    while(end-start>1){
        if(s[(start+end)/2]<x)start=(start+end)/2;
        else end=(start+end)/2;
    }
    return end;
}
int lower_t(int start,int end,long long int x){
    while(end-start>1){
        if(t[(start+end)/2]<x)start=(start+end)/2;
        else end=(start+end)/2;
    }
    return end;
}

int main(){
    int a,b,q;
    cin >> a >> b >> q;
    long long int x;
    long long int ans=1e15;
    int tmp1,tmp2;
    for(int i=0;i<a;i++)cin >> s[i];
    for(int j=0;j<b;j++)cin >> t[j];
    for(int i=0;i<q;i++){
        ans=1e15;
        cin >> x;
        tmp1=lower_s(0,a-1,x);
        tmp2=lower_t(0,b-1,x);
        for(int i=max(tmp1-1,0);i<=tmp1;i++){
            for(int j=max(tmp2-1,0);j<=tmp2;j++){
                ans=min(ans,abs(s[i]-x)+abs(s[i]-t[j]));
                ans=min(ans,abs(t[j]-x)+abs(s[i]-t[j]));
            }
        }
        cout << ans << endl;
    }
}