#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    if(x==3 || x==5 || x==7)cout << "YES" << endl;
    else cout << "NO" << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    int ans=1e9;
    int tmp;
    for(int i=0;i<S.length()-2;i++){
        tmp=(S[i]-'0')*100+(S[i+1]-'0')*10+(S[i+2]-'0');
        ans=min(ans,abs(tmp-753));
    }
    cout << ans << endl;
}
//桁数のたかが知れているから3,5,7がついているやつを全部調べていく
//一応dfsでもできる
//せいぜい3^8*8なので余裕
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    int ans=0;
    q.push(3);
    q.push(5);
    q.push(7);
    int tmp;
    int i,j,k;
    while(q.front()<=n){
            tmp=q.front();
            q.push(tmp*10+3);
            q.push(tmp*10+5);
            q.push(tmp*10+7);
            q.pop();
            i=0; j=0; k=0;
            while(tmp>0){
                if(tmp%10==3)i++;
                else if(tmp%10==5)j++;
                else if(tmp%10==7)k++;
                tmp/=10;
            }
            if(i>0&&j>0&&k>0)ans++;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int64_t ret[101];
void prime_factor(int64_t N) {
  for(int64_t i = 2; i * i <= N; i++) {
    while(N % i == 0) {
      ret[i]++;
      N /= i;
    }
  }
  if(N != 1) ret[N]++;//デフォの1だと今回みたいな繰り返すタイプで不利、もとも書き換え得
}

int main(){
    int64_t n;
    cin >> n;
    int two=0;
    int four=0;
    int twofour=0;
    int onefour=0;
    int sevenfour=0;
    for(int64_t i=2;i<n+1;i++)prime_factor(i);
    for(int64_t i=2;i<=n;i++){
        if(ret[i]>=74)sevenfour++;
        if(ret[i]>=24)twofour++;
        if(ret[i]>=14)onefour++;
        if(ret[i]>=4)four++;
        if(ret[i]>=2)two++;
    }
    cout << sevenfour+twofour*(two-1)+onefour*(four-1)+four*(four-1)/2*(two-2) << endl;
}
