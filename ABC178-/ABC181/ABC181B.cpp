#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int a,b;
    long long int ans = 0;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        ans += (a+b)*(b-a+1)/2;
    }
    cout << ans;
}