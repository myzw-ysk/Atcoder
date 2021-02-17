#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long modpow(long long a,long long b){
    long long res = 1;
    while (b > 0){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}


int main(){
    long long int n;
    cin >> n;
    if(n<2){
        cout << 0;
        return 0;
    }
    long long int ans = (modpow(9,n)*2)%mod;
    ans = (ans + mod - modpow(8,n)) %mod;
    cout << (modpow(10,n)-ans+mod)%mod;
}