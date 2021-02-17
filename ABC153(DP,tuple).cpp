#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int H;
 long long int A;
 cin >> H >> A;
 if(H%A==0)cout << H/A << endl;
 else{cout << (H/A)+1 << endl;}
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int H;
 cin >> H >> N;
 int a[N];
 int i;
 long long int sum =0;
 for(i=0;i<N;++i){
   cin >> a[i];
   sum += a[i];
   if(sum>=H){
       cout << "Yes" << endl;
       break;
   }
   }
if(sum<H)cout << "No" << endl;
 }


#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int K;
 cin >> N >> K;
 if(K>=N)cout << 0 << endl;
 else{
 int a[N];
 int i;
 long long int sum =0;
 for(i=0;i<N;++i){
   cin >> a[i];
   sum += a[i];
   }
 sort(a,a+N);
 for(i=0;i<K;i++)sum -= a[N-1-i];
 cout << sum << endl;
 }
 }

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 long long int N;
 cin >> N;
 if(N==1)cout << 1 << endl;
 else{
 long long int count = 1;
 long long int countsum = 0;
 long long int downsum = 0;
 while(N!=1){
     N/=2;
     countsum += count;
     count *= 2;
 }
 cout << countsum+count << endl;
 }
 }


#ナップザックにはDPを！
#tupleの使い方としてはこれはいいかんじ

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int H;
 int N;
 cin >> H >> N;
 vector<tuple<double, int, int>> a;
 int x;
 int y;
 double z;
 int i;
 long long int sum = 0;
 for(i=0;i<N;++i){
   cin >> x >> y;
   z = (double)x/y;
   a.push_back(make_tuple(z, y, x));
   }
   sort(a.begin(),a.end());   
    tie(z,y,x)=a[N-1];
 while(H>0){
     if(H>=x){
         H -= x;
         sum += y;
     }
     else{
         int tmp = 0;
         int new_x,new_y,new_z;
         for(i=1;i<N;i++){
             tie(new_z,new_y,new_x)=a[N-1-i];
             if(H>=new_x){
                 H -= x;
                 sum += y;
                 break;
             }
         }
     }
     }
 cout << sum << endl;
 }

#DP基本フォーマット
#今回は計算量てきにもDPでいけるラインだったのでHPごとのテーブルで攻めることを思いつかなきゃいかんかった

#include <bits/stdc++.h>
using namespace std;
int main(){
 int H;
 int N;
 long long int dp[20000];
 dp[0]=0;
 cin >> H >> N;
 int D[N];
 int M[N];
 for(int i=0;i<N;i++)cin >> D[i] >> M[i];
 for(int i=1;i<H+1;i++){    
     dp[i]=1e10;//モンスターのHPでのDP
     for(int j=0;j<N;j++){  //HPごとに技ごとで最小のMPをチェック
         dp[i]=min(dp[i],dp[max(0,i-D[j])]+M[j]);
     }}
     cout << dp[H] << endl;
 }



//累積和を取る範囲を事前に尺取っておくことがこの問題のキモだった
//ダメージ量は単調増加→累積か！？って発想と範囲は尺取りで決められるって2つだからまあまあむずい問題
#include <bits/stdc++.h>
using namespace std;
long long int sum[200005];
int main(){
    long long int n,d,a;
    cin >> n >> d >> a;
    pair<int,long long int> p[n];
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
        p[i].second = (p[i].second+a-1)/a;
    }
    sort(p,p+n);
    int r[n];
    int tmp=n-1;
    for(int i=n-1;i>=0;i--){
        while(p[tmp].first+2*d>=p[i].first && tmp>=0)tmp--;
        r[i]=tmp+1;
    }
    long long int ans=0;
    for(int i=0;i<n;i++){
        p[i].second-=(sum[i]-sum[r[i]]);
        sum[i+1]=sum[i]+max(0LL,p[i].second);
        ans+=max(0LL,p[i].second);
    }
    cout << ans << endl;
}