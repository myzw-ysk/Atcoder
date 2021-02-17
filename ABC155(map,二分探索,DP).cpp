#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(A==B && B!=C)cout << "Yes" << endl;
    else if(A==C && B!=C)cout << "Yes" << endl;
    else if(B==C && A!=C)cout << "Yes" << endl;  
    else{cout << "No" << endl;}
}



#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int i;
    cin >> N;
    int A[N];
    for(i=0;i<N;i++)cin >> A[i];
    int flag = 0;
    for(i=0;i<N;i++){
        if(A[i]%2==0){
            if(A[i] % 3 != 0 && A[i] % 5 != 0)flag++;
        }
    }
    if(flag>0)cout << "DENIED" << endl;
    else{cout << "APPROVED" << endl;}
}

//secondでmapの中身にアクセスできる
//mapの中身はもともと昇順
//吐くのは一番数が多いもpのだけだから
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    int i;
    string S;
    cin>>N;
    map<string,int>mp;
    for(i=0;i<N;i++){
        cin>>S;
        mp[S]+=1;
    }
    int max;
    for(const auto& e : mp){
        int x = e.second;
        if(x>max)max=x;
    }
    for(auto it = mp.begin();it != mp.end();it++){
        if(it->second == max)cout << it->first <<endl;
    }
}


//積についての二分探索
#include <bits/stdc++.h>
using namespace std;

long long int n,k;
long long int a[200005];

int main(){
    cin >> n >> k;
    for(long long int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    long long int x=1e9;
    long long int minus=-x*x;
    long long int plus=x*x;
    while(plus - minus>1){
        int mid = (lb+ub)/2,cnt=0;
        for(int i=0;i<n;i++){//二分探索はしょせんlogNなんだからloopすればいいじゃない
            if(a[i] < 0){
                cnt +=n- (lower_bound(a,a+n,(long double )mid/a[i])-a);
                //lbがイテレータでかえされるのがうざいならaで引いてやる
            }
            else if( a[i] >0){
                cnt += upper_bound(a,a+n,(long double)mid/a[i])-a;
            }
            else if( mid >= 0){//つまり0の場合だからがばっとたせる
                cnt+=n;
            }
            if( a[i] * a[i] <= mid) cnt--;//自分自身を引く
        }
        (cnt>=2*k?ub:lb) = mid;//更新する
    }
    cout<<ub<<endl;
}





#include<bits/stdc++.h>
using namespace std;
int main(){
    string N;
    cin >> N;
    int n = N.length();
    long long int S[n+1];
    int i;
    for(i=0;i<n;i++)S[i+1]=N[i]-'0';
    S[0]=0;
    long long int dp[n+1][2];
    dp[0][0]=0;dp[0][1]=1;
    for(i=1;i<n+1;i++){
        dp[i][0]=min(dp[i-1][0]+S[i],dp[i-1][1]+10-S[i]);
        dp[i][1]=min(dp[i-1][0]+1+S[i],dp[i-1][1]+10-S[i]-1);
    }
    cout << dp[n][0] << endl;
}

