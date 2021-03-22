#include <bits/stdc++.h>
using namespace std;

long long int c[200005];

int main(){
    int n;
    cin >> n;
    long long int a[n],b[n];
    long long int tmp = 0;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        tmp -= a[i];
        c[i] = 2 * a[i] + b[i];
    }
    sort(c,c+n);
    for(int i=0;i<n;i++){
        tmp += c[n-1-i];
        if(tmp>0){
            cout << (i+1);
            return 0;
        }
    }
}