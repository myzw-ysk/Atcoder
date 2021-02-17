#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,k;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> k;
    if(e-a>k)cout << ":(" << endl;
    else cout << "Yay!" << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[5];
    int ans=0;
    int MIN=10;
    for(int i=0;i<5;i++){
        cin >> a[i];
        ans+=(((a[i]+9)/10)*10);
        if(a[i]%10!=0)MIN=min(a[i]%10,MIN);
    }
    cout << ans-(10-MIN) << endl;
}
//狭いところ次第に結局なる
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    long long int a[5];
    for(int i=0;i<5;i++)cin >> a[i];
    long long int ans=0;
    long long int MIN=1e15+1;    
    ans+=(n+a[0]-1)/a[0];
    MIN=min(MIN,a[0]);
    for(int i=1;i<5;i++){
        if(a[i]<MIN){
            MIN=a[i];
            ans += (n-(ans-i)*MIN+MIN-1)/MIN;
        }
        else ans++;
    }
    cout << ans << endl;
}
//いずれの解法についても鍵はa番目とb番目とc番目の和は
//a*b*c>kのときk番目以内にはない
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    long long int a[x],b[y],c[z],d[3000002];
    for(int i=0;i<x;i++)cin >> a[i];
    for(int i=0;i<y;i++)cin >> b[i];
    for(int i=0;i<z;i++)cin >> c[i];
    int count=0;
        long long int e[x*y];
        for(int i=0;i<x;i++)for(int j=0;j<y;j++){
            e[count]=-a[i]-b[j];
            count++;
        }
        sort(e,e+count);
        int count2=0;
        for(int i=0;i<k;i++)for(int l=0;l<z;l++){
            d[count2]=e[i]-c[l];
            count2++;
        }
        sort(d,d+count2);
    for(int i=0;i<k;i++)cout << -d[i] << endl;
}

//優先度付きキューでも解ける！
//二分探索でも解ける！
//https://img.atcoder.jp/abc123/editorial.pdf