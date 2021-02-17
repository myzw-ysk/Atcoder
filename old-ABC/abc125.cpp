#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,t;
    cin >> a >> b >>t;
    cout << b*(t/a) << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int c[n];
    int v[n];
    int ans=0;
    for(int i=0;i<n;i++)cin >> v[i];
    for(int i=0;i<n;i++)cin >> c[i];
    for(int i=0;i<n;i++)if(v[i]-c[i]>0)ans+=(v[i]-c[i]);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
 int tmp;
 int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int MIN=a[1];
    int GCD=gcd(a[0],a[1]);
    for(int i=2;i<n;i++)GCD=gcd(GCD,a[i]);
    int flag=0;
    int ans;
    for(int i=MIN/GCD;i>0;i--){
        flag=0;
        for(int j=0;j<n;j++){
            if(a[j]%(i*GCD)!=0)flag++;
            if(flag>1)break;
        }
        if(flag<2){
            ans=GCD*i;
            break;
        }
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int flag=0;
    long long int MIN=1e9;
    long long int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            a[i]*=-1;
            flag++;
        }
        MIN=min(MIN,a[i]);
        ans+=a[i];
    }
    if(flag%2==1)ans-=(MIN*2);
    cout << ans << endl;
}