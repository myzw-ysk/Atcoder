#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    s[3]='8';
    cout << s;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int d[n];
    for(int i=0;i<n;i++)cin >> d[i];
    sort(d,d+n);
    int ans=1;
    for(int i=1;i<n;i++){
        if(d[i-1]<d[i]) ans++;
    }
    cout << ans;
}
//ちまちま場合分けしなくても実は枚数の最大値的に全探索で行けた…
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int y;
    cin >> y;
    int a,b,c;
    c=y/1000;
    if(c<n){
        cout << -1 << " " << -1 << " " << -1;
        return 0;
    }
    if(c==n){
        cout << 0 << " " << 0 << " " << c;
        return 0;
    }
    b=min((c-n)/4,c/5);
    c-=5*b;
    a=b+c-n;
    b-=2*a;
    if(b<0){
        cout << -1 << " " << -1 << " " << -1;
        return 0;
    }
    cout << a << " " << b << " " << c;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h;
    cin >> n >> h;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=n-1;i>=0;i--){
        h -= b[i];
        ans++;
        if(h<=0)break;
        if(a[n-1]>b[i-1])break;
    }
    if(h<=0){
        cout << ans;
        return 0;
    }
    cout << ans + (h+a[n-1]-1)/a[n-1];
}