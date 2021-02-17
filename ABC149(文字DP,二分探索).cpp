
#A 文字入力パターン
#include <bits/stdc++.h>
using namespace std;
 
int main(){
string S;
string T;
 cin >> S >> T;
cout << T << S;
  return 0;
}



 
#B
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int A;
 long long int B;
 long long int K;
 cin >> A >> B >> K;
 if(A>=K)cout << A-K << " " << B << endl;
 else if(A+B-K>=0){
     cout << 0 << " " << A+B-K << endl;
 }
 else{cout << 0 << " " << 0 << endl;}
 return 0;
}

#c
while分の使い方…　イコールは2かいやぞ…

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int N;
 cin >> N;
 int i=0;
 int j;
 if(N==2)cout << N << endl;
 else{
 while(i==0){
     for(j=2;j<N;++j){
      if(N%j==0){
          break;
      }
      if(j==N-1)i++;}
      if(i==0)N++;
     }
    cout << N << endl;}
  return 0;
}

#D
DPのポイント
1.各サイクルで全パターンを書き出す
2.用意する箱は最小限度になるように書く、今回はsumはN/Kあればじゅうぶん。
用意するだけでも時間はかかる。

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int K;
 int R;
 int S;
 int P;
 cin >> N >> K;
 cin >> R >> S >> P;
string T;
 cin >> T;
  int i;
  int j;
  long long int count=0;
  int k;
for(i=0;i<K;i++){
    j=i;
    k=0;
    long long int sum[N/K+10][3]={0};
        if(T[j]=='r')sum[k][2]=P; 
        if(T[j]=='s')sum[k][0]=R;
        if(T[j]=='p')sum[k][1]=S;
        j+=K;
    while(j<N){
        k++;
        if(T[j]=='r'){sum[k][2]=P+max(sum[k-1][0],sum[k-1][1]); 
        sum[k][0]=max(sum[k-1][2],sum[k-1][1]); 
        sum[k][1]=max(sum[k-1][2],sum[k-1][0]);}
        if(T[j]=='s'){sum[k][0]=R+max(sum[k-1][2],sum[k-1][1]);
        sum[k][2]=max(sum[k-1][0],sum[k-1][1]); 
        sum[k][1]=max(sum[k-1][2],sum[k-1][0]);}
        if(T[j]=='p'){sum[k][1]=S+max(sum[k-1][0],sum[k-1][2]);
        sum[k][0]=max(sum[k-1][2],sum[k-1][1]); 
        sum[k][2]=max(sum[k-1][1],sum[k-1][0]);}
        j+=K;}
    count += max(sum[k][0],max(sum[k][1],sum[k][2]));
}
   cout << count << endl;
  return 0;
}

#E
これでは時間切れなので二分探索する
lowerboundである値以上を探す

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
 
int main(){
    ll n,m;
    cin>>n>>m;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll sum[n+1];
    sum[n]=0;
    for(int i=n-1;i>=0;i--){
        sum[i]=sum[i+1]+a[i];
    }
    int ok=1,ng=200001;
    ll hold[200001];
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        ll t=0;
        for(int i=0;i<n;i++){
            t+=n-(lower_bound(a,a+n,mid-a[i])-a);
        }
        hold[mid]=t;
        if(t>=m)ok=mid;
        else ng=mid;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int tmp=lower_bound(a,a+n,ok-a[i])-a;
        ans+=sum[tmp]+a[i]*(n-tmp);
    }
    ans-=(hold[ok]-m)*ok;
    cout<<ans<<endl;
}