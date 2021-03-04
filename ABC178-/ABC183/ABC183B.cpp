#include <bits/stdc++.h>
using namespace std;

int main(){
    long double s[2],g[2];
    cin >> s[0] >> s[1] >> g[0] >> g[1];
    cout << fixed << setprecision(16);
    cout << s[0]+s[1]*(g[0]-s[0])/(g[1]+s[1]);
}