#include <bits/stdc++.h>
using namespace std;

const long long int mod = 1e9+7;
long long int a[2005];

int main(){
    int s;
    cin >> s;
    a[s]=1;
    for(int i=s;i>2;i--){
        for(int j=3;j<=i;j++){
            a[i-j] += a[i];
            a[i-j] %= mod;
        }
    }
    cout << a[0];
}