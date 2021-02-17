#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin >> m;
    cout << 24+(24-m);
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    string s;
    cin >> a >> b >> s;
    for(int i=0;i<a;i++){
        if(s[i]=='-'){
            cout << "No";
            return 0;
        }
    }
    if(s[a]!='-'){
        cout << "No";
        return 0;
    }
    for(int i=0;i<b;i++){
        if(s[a+1+i]=='-'){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";        
}
#include<bits/stdc++.h>
using namespace std;
long long int ans[505];
int main(){
    int n;
    cin >> n;
    long long int c[n],s[n],f[n];
    for(int i=0;i<n-1;i++){
        cin >> c[i] >> s[i] >> f[i];
        for(int j=0;j<=i;j++)ans[j] = max(((ans[j]+f[i]-1)/f[i])*f[i],s[i])+c[i];
    }
    for(int i=0;i<n;i++)cout << ans[i] << endl;
}
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
int ans[100005];
int main(){
    auto t = prime_table(100000);
    for(int i=1;i<=100000;i++)ans[i]=ans[i-1]+(t[i]&t[(i+1)/2]);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << endl;
    }
}