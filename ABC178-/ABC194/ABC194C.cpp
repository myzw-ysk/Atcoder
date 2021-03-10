#include <bits/stdc++.h>
using namespace std;

long long int c[405];

int main(){
    int n;
    cin >> n;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        c[a+200]++;
    }
    long long int ans=0;
    for(long long int i=0;i<400;i++){
        for(long long int j=i+1;j<401;j++){
            ans+=((j-i)*(j-i))*c[i]*c[j];
        }
    }
    cout << ans;
}