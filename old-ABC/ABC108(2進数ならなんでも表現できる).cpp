#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    if(k%2==1)cout << (k/2)*(k/2+1) << endl;
    else cout << k*k/4 << endl;
}
//ベクトルじゃ！
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << c-(d-b) << " " << d+(c-a) << " "   << a-(d-b) << " " << b+(c-a) << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;
    cin >> n >> k;
    long long int a,b;
    long long int ans=0;
    for(int i=0;i<k;i++){
        if(i==0)ans+=(n/k)*(n/k)*(n/k);
        else{
            if(n%k>=i)a=n/k+1;
            else a=n/k;
            if(n%k>=k-i)b=n/k+1;
            else b=n/k;
            if((2*k-2*i)%k==0)ans+=a*b*b;
    }
    }
    cout << ans << endl;
}
//天才かよ、さすが700点問題…
//結局枝の長さを全部2の累乗にして2進数の再現をしてやればよい
//足りない部分はうまく差分のノードをいれてやればよい
//なんかうまくいかない
//ビットライクな表記も、log2なんて便利なツールもある
#include<bits/stdc++.h>
using namespace std;
int main(){
    int l;
    cin >> l;
    int n=log2(l);
    vector<pair<pair<int,int>,int>> ans;
    for(int i=0;i<n;i++){
        ans.push_back(make_pair(make_pair(i+1,i+2),0));
        ans.push_back(make_pair(make_pair(i+1,i+2),(1 << i)));
    }
    for(int i=n;i>=0;i--){
        if(l-(1 << i)>=(1 << n)){
            ans.push_back(make_pair(make_pair(i,n),l-(1 << i)));
            break;
        }
    }
    cout << n+1 << " " << ans.size() << endl;
    for(auto u:ans)cout << u.first.first << " " << u.first.second << " " << u.second << endl;
}