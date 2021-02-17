#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int M;
 cin >> N >> M;
 cout << (N*(N-1))/2+(M*(M-1))/2 << endl;
 return 0;
}




#include <bits/stdc++.h>
using namespace std;

int main(){
string txt;
 cin >> txt;
 int N = txt.length();
  int n = (N-1)/2;
  int m = (N+3)/2-1;
  int i;
  char c;
  char d;
  int t=0;
  for(i=0;i<n;i++){
   c = txt[i];
   d = txt[n-i-1];
   if(c!=d)t++;}
  for(i=m;i<N;i++){
   c = txt[i];
   d = txt[N-1-i+m];
   if(c!=d)t++;}
  for(i=0;i<N;i++){
   c = txt[i];
   d = txt[N-i-1];
   if(c!=d)t++;}
  if(t>0)cout << "No" << endl; 
  else{cout << "Yes" << endl;} 
  return 0;
}

///小数表示はfixedにお任せ
#include <bits/stdc++.h>
using namespace std;
 
int main(){
 double L;
 double tmpval;
 cin >> L;
 tmpval = (double)(L*L*L)/27.0;
 cout << fixed << setprecision(16);
 cout  << 1.0*tmpval << endl;
 }


///全部longlongに統一すること！！！！
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long int A[N];
    long long int C[N];
    long long int box[N]; 
    int i;
    long long int ans=0;
    long long int sa;
    for(i=0;i<N;i++){
        cin >> A[i];
        C[i]=0;
    }
    for(i=0;i<N;i++)C[A[i]-1]++;
    for(i=0;i<N;i++){
        box[i]=C[i]*(C[i]-1)/2;
        ans += box[i];
    }
    for(i=0;i<N;i++){
        sa = C[A[i]-1]-1;
        cout << ans - sa << endl;
    }
}


#include <bits/stdc++.h>
using namespace std;

int s[3000][3000]; 
char c[3000][3000];
int main(){
    int h,w,k;
    cin >> h >> w >> k;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        cin >> c[i][j];
        s[i][j] =c[i][j] - '0';
    }
    int flag=0;
    int solv=1e9;
    int tmp;
    for(int i=0;i<(1<<h);i++){
        vector<int> ans;
        flag=0;
        tmp=__builtin_popcount(i);
        ans.push_back(s[0][0]);
        for(int j=0;j<h-1;j++){
            if(i&(1<<j))ans.push_back(s[j+1][0]);
            else ans[ans.size()-1]+=s[j+1][0];
            if(ans[ans.size()-1]>k){
                flag++;
                break;
            }
        }
        if(flag==0){
            for(int l=1;l<w;l++){
                flag=0;
                vector<int> num;
                num.push_back(s[0][l]);
                for(int j=0;j<h-1;j++){
                    if(i&(1<<j))num.push_back(s[j+1][l]);
                    else num[num.size()-1]+=s[j+1][l];
                    if(num[num.size()-1]>k){
                        flag++;
                        break;
                    }
                }
                if(flag>0)break;
                else{
                    for(int l=0;l<ans.size();l++){
                        ans[l]+=num[l];
                        if(ans[l]>k){
                            flag++;
                            break;
                        }
                    }
                    if(flag>0){
                        tmp++;
                        for(int l=0;l<ans.size();l++)ans[l]=num[l];
                        flag=0;
                    }
                }
            }
            if(flag==0)solv=min(solv,tmp);
        }
    }
    cout << solv << endl;
}


//きれいな遷移だこと… 和をindexとして持つDPは前にもみたなぁ
//区間が決まっているかどうかだけ見る、具体的な値まで入れるとオーバー
#include <bits/stdc++.h>
using namespace std;

const int MAX = 3005;
const long long int mod = 998244353;
long long int dp[MAX][MAX][3];

int main(){
    int n,s;
    cin >> n >> s;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    dp[0][0][0]=1; dp[0][0][1]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][0] %= mod;
            dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
            dp[i+1][j][1] %= mod;
            dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] +dp[i][j][2];
            dp[i+1][j][2] %= mod;        
            if(j+a[i]<=s){
                dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]; 
                dp[i+1][j+a[i]][1] %= mod;
                dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]; 
                dp[i+1][j+a[i]][2] %= mod;
            }        
        }
    }
    cout << dp[n][s][2] << endl;
}