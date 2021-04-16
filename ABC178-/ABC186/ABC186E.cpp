//https://qiita.com/drken/items/b97ff231e43bce50199a
//拡張ユークリッドの互除法を加工の回

#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long extGCD(long long a, long long b, long long &x, long long &y,long long g) {
    if (b == 0) {
        x = g;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x, g);
    y -= a/b * x;
    return d;
}

int main(){
    int t;
    cin >> t;
    long long int n,s,k;
    for(int i=0;i<t;i++){
        cin >> n >> s >> k;
        long long int gcd = GCD(n,k);
        if((n-s)%gcd != 0){
            cout << -1 << "\n";
        }
        else{
            long long int x,y;
            //すべての項を最大公約数で割る必要があった。
            //中にいれるやつだけGCD考慮してもダメ、結局幅が出る
            extGCD(k/gcd,n/gcd,x,y,(n-s)/gcd);
            while(x<0)x+=(n/gcd);
            x %= (n/gcd);
            cout << x << "\n";
        }
    }
}