#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int flag=0;
    for(int i=0;i<3;i++){
        if(s[i]==s[i+1])flag++;
    }
    if(flag>0)cout << "Bad" << endl;
    else cout << "Good" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,L;
    cin >> N >> L;
    if(L>=1)cout << (L-1)*(N-1)+N*(N+1)/2-1 << endl;
    else{
        int ans=L;
        int sum=(L-1)*N+N*(N+1)/2;
        for(int i=2;i<N+1;i++){
            if(abs(ans)>abs(L-1+i))ans=L-1+i;
        }
        cout << sum-ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int x, long long int y){
 long long int tmp;
 long long int r;
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
    long long int a,b,c,d,i;
    cin >> a >> b >> c >> d;
    long long int ans=(b-a+1)-(b/c-(a-1)/c)-(b/d-(a-1)/d);
    long long int g=c*d/gcd(c,d);
    ans += (b/g-(a-1)/g);
    cout << ans << endl;
}

//惨敗…
//はじめるまでのはやさではなく純粋な締め切りまでのはやさで
//今回は十分
//Aは考慮してもどうしようもない、締め切りに内包されてる
//馬鹿正直に何パターンか試すしかない気がする
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int N;
    cin >> N;
    long long int a[N];
    long long int b[N];
    priority_queue<pair<long long int ,long long int>> q;
    for(long long int i=0;i<N;i++){
        cin >> a[i] >> b[i];
        q.push(make_pair(-b[i],a[i]));
    }
    long long int t=0;
    int flag=0;
    while(!q.empty()){
        t+=q.top().second;
        if(t>-q.top().first){
                flag++;
                break;
        }
        q.pop();
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}
#include<bits/stdc++.h>
using namespace std;