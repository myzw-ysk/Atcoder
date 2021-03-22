#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int A = (a[0]-'0') + (a[1]-'0') + (a[2]-'0');
    int B = (b[0]-'0') + (b[1]-'0') + (b[2]-'0');
    if(A>=B)cout << A;
    else cout << B;
}