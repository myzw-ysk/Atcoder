#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a+b>c+d)cout << "Left";
    else if(a+b==c+d)cout << "Balanced";
    else cout << "Right";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int ans=0;
    for(int i=1;i<=n;i++){
        int tmp=i;
        int sum=0;
        while(tmp>0){
            sum += tmp%10;
            tmp/=10;
        }
        if(sum>=a && sum<=b)ans+=i;
    }
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x,y;
    cin >> x >> y;
    int ans=0;
    while(x<=y){
        x*=2;
        ans++;
    }
    cout << ans;
}

//実装自体は超簡単、考察力勝負。
//01の変わり目にフォーカスして、変えるときにどういうことがおこるのか…とちまちま考察を進める必要がある
//この手の初見手の付けようがない問題はこわい。
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans=s.length();
    for(int i=1;i<s.length();i++)

}