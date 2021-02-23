#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int x;
    long long int man=0;
    long double euc=0;
    long long int che=0;
    for(int i=0;i<n;i++){
        cin >> x;
        man += abs(x);
        euc += (long double)x*(long double)x;
        che = max(che,abs(x));
    }
    cout << man << endl;
    cout << fixed << setprecision(16);
    cout << sqrt(euc) << endl;
    cout << (long long int)che << endl;
}