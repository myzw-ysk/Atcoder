#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a<=b)cout << a << endl;
    else cout << a-1 << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int bin = (1<<k)-1;
    cout << a + b + c + max(a,max(b,c))*bin << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    char s[h+5][w+5];
    for(int i=1;i<=h;i++){
        s[i][0]='.';
        s[i][w+1]='.';
    }   
    for(int j=1;j<=w;j++){
        s[0][j]='.';
        s[h+1][j]='.';
    }
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)cin >> s[i][j];
    int flag=0;
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        if(s[i][j]=='#'){
            if(s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j-1]=='.' && s[i][j+1]=='.')flag++;
        }
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}

//素数テーブル
#include<bits/stdc++.h>
using namespace std;

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
int main(){
    int n;
    cin >> n;
    auto t=prime_table(55555);
    int i=0;
    int iter=2;
    while(i<n){
        if(t[iter]==true && iter%5==1){
            cout << iter << " ";
            i++;
        }
        iter++;
    }
    cout << endl;
}