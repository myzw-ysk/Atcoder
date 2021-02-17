#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    cout << "ABC"+s;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==1)cout << 1;
    else if(n<4)cout << 2;
    else if(n<8)cout << 4;
    else if(n<16)cout << 8;
    else if(n<32)cout << 16;
    else if(n<64)cout << 32;
    else cout << 64;
}
#include <bits/stdc++.h>
using namespace std;
int ca[200005];
int cb[200005];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a==1)ca[b]++;
        else if(b==n)cb[a]++;
    }
    for(int i=1;i<=n;i++){
        if(ca[i]>0 && cb[i]>0){
            cout << "POSSIBLE";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}

//このての鉄板の考え方:最終状態から逆算する
//逆合成せよ
//そして今回の場合はまず順番をこちらから操作できる:つまり上下が明確
//かつ最小限の大きさである順列からスタートさせてやればよい
//これなら50で割り切れないやつがkにきても扱いやすい
//おんなじ数だけとかだと割り切れないときが厄介

//キーとなる要素は数を固定・逆操作を考える・そのとき都合がいい初期値はなにか？

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int k;
    cin >> k;
    cout << 50 << endl;//この手の鉄板:数字を固定してしまう

}