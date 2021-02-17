#include <bits/stdc++.h>
using namespace std;
int main(){
    char b;
    cin >> b;
    if(b=='A')cout << 'T' << endl;
    else if(b=='T')cout << 'A' << endl;
    else if(b=='C')cout << 'G' << endl;
    else if(b=='G')cout << 'C' << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans=0;
    int tmp=0;
    for(int i=0;i<S.length();i++){
        if(S[i]=='A' || S[i]=='T' || S[i]=='G' || S[i]=='C'){
            tmp++;
            ans=max(tmp,ans);
        }
        else tmp=0;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,q;
    cin >> n >> q;
    string S;
    cin >> S;
    for(int i=1;i<n;i++){
        a[i+1]+=a[i];
        if(S[i-1]=='A' && S[i]=='C')a[i+1]++;
    }
    int l,r;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        cout << a[r]-a[l] << endl;
    }   
}
//4文字の場合もちゃんと考えましたか？本当に先入観なくやりましたか？
#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
long long int dp[105][5][5][5];
int main(){
      int n;
      cin >> n;
      long long int ans=0;
      int nnn=0;
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
              for(int k=0;k<4;k++){
                if(i==0 && j==2 && k==1)nnn++;
                else if(i==0 && j==1 && k==2)nnn++;
                else if(i==2 && j==0 && k==1)nnn++;
                else dp[3][i][j][k]++;
          }
        }
      }
    for(int m=3;m<n;m++){
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    if(j==0 && k==2 && l==1)nnn++;
                    else if(j==0 && k==1 && l==2)nnn++;
                    else if(j==2 && k==0 && l==1)nnn++;
                    else if(i==0 && k==2 && l==1)nnn++;
                    else if(i==0 && j==2 && l==1)nnn++;                    
                    else dp[m+1][j][k][l]+=dp[m][i][j][k];
                    dp[m+1][j][k][l]%=mod;
                }
            }
        }
        }
    }
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
              for(int k=0;k<4;k++){
              ans+=dp[n][i][j][k];
              ans%=mod;
          }
        }
      }
      cout << ans << endl;
}
