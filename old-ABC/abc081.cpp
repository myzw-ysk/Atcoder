#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int ans=0;
    cin >> s;
    for(int i=0;i<3;i++)if(s[i]=='1')ans++;
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int ans=1e9;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        tmp=0;
        while(a[i]%2==0){
            a[i]/=2;
            tmp++;
        }
        ans=min(ans,tmp);
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int s[200005];
int main(){
    int n,k;
    cin >> n >> k;
    int a;
    int ans=0;
    int tmp=0;
    for(int i=0;i<n;i++){
        cin >> a;
        if(s[a]==0)tmp++;
        s[a]++;
    }
    if(tmp<=k){
        cout << 0 << endl;
        return 0;
    }
    sort(s,s+n+1);
    int count=0;
    int i=0;
    while(count<tmp-k){
        if(s[i]>0){
            ans+=s[i];
            count++;
        }
        i++;
    }
    cout << ans;
}
//累積和が非負で単調増加を作れることを利用する
//最短指定はないから確実に作れるのを考えるパターン問題
//まぜこぜのやつはどうやったら非負にできるかっていうと最大のやつをりようしてやればよい
//単純なケース(非負)なら簡単ってことに気付くのが重要
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    int MIN=a[0];
    int MAX=a[0];
    int max_p=0;
    int min_p=0;
    for(int i=1;i<n;i++){
        cin >> a[i];
        if(a[i]<MIN){
            min_p=i;
            MIN=a[i];
        }
        if(MAX<a[i]){
            max_p=i;
            MAX=a[i];
        }
    }
    if(MIN>=0){
        cout << n-1 << endl;
        for(int i=1;i<n;i++)cout << i << " " << i+1 << endl;
        return 0;
    }
    else if(MAX<=0){
        cout << n-1 << endl;
        for(int i=n;i>1;i--)cout << i << " " << i-1 << endl;
        return 0;
    }
    else if(abs(MAX)>=abs(MIN)){
        cout << 2*n-2 << endl;
        for(int i=0;i<n;i++)if(i!=max_p)cout << max_p+1 << " " << i+1 << endl;
        for(int i=1;i<n;i++)cout << i << " " << i+1 << endl;
        return 0;
    }
    else{
        cout << 2*n-2 << endl;
        for(int i=0;i<n;i++)if(i!=min_p)cout << min_p+1 << " " << i+1 << endl;
        for(int i=n;i>1;i--)cout << i << " " << i-1 << endl;
    }
}