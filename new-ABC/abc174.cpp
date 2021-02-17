#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    if(x>=30)cout << "Yes";
    else cout << "No";
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int d;
    cin>> n >> d;
    int ans=0;
    long long int x,y;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        if(x*x+y*y<=d*d)ans++;
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int k;
    cin >> k;
    map<long long int,int> mp;
    long long int tmp=7;
    int now=1; 
    while(1){
        if(tmp%k==0){
            cout << now;
            return 0;
        }
        else if(mp[tmp%k]>0){
            cout << -1;
            return 0;
        }
        else{
            mp[tmp%k]++;
            tmp = (tmp*10 +7)%k; 
        }
        now++;
    }
}

//隣り合ってなくてもよいを読み落とした時点でダイヤラかし
//そして実装方針でミスってる
//左右から入れ替える方針だと余計な入れ替えをする可能性など諸々リスクがある
//だからRを全部左に寄せる前提で何個移す必要があるのかを数える
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    char c[n];
    int r=0;
    for(int i=0;i<n;i++){
        cin >> c[i];
        if(c[i]=='R')r++;
    }
    int ans=0;
    for(int i=0;i<r;i++)if(c[i]=='W')ans++;
    cout << ans;
}

//てんぱってprirityとか考えたけど、冷静になると
//ある長さにするには何回必要ですか？の二ブタンになる
//N～NlogNでできる解法であれくらいのACでいけるのはこの解法くらいって詰め方でも行けた…
//割り算部分は結局下みたいな感じになる、1回引かなきゃいけなかった
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int MIN=0;
    int MAX=a[n-1];
    int MID=(MAX+MIN)/2;
    int tmp=0;
    while(MAX-MIN>1){
        MID=(MAX+MIN)/2;
        tmp=0;
        for(int i=0;i<n;i++)tmp+=((a[i]+MID-1)/MID-1);//ここで自己っても冷静に検討すること
        if(tmp>k)MIN=MID;
        else MAX=MID;
    }
    cout << MAX;//上のif分を信じること、その通りに動くから違ったらそれ以前に間違いはある
}

//5*10^5って時点でこのまえのsetのやり方では無理とわかる
//ではどうするのかというと…
//解説放送をみること。→BITを使った平面走査をする.後日調べること
//Moだと時間外では？
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    int c[n];
    for(int i=0;i<n;i++)cin >> c[i];
    int l,r;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        cout <<  << endl;
    }
}