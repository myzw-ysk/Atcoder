#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];
    
}

//この手の問題のキーポイントとして単調増加するものに着目する
//というのがあった。（最近やってなくて忘れてたけど）

//ポイント1: 鳩ノ巣原理からある数字がn+1個以上あれば自動的にAUTO（どっか被る）
//ポイント2: 逆にそれ以外であれば可能で、