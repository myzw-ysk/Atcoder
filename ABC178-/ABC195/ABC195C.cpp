#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int ans=0;
    long long int tmp = 1000;
    for(int i=0;i<6;i++){
        ans += max(n-tmp+1,0LL);
        tmp *= 1000;
    }
    cout << ans;
}