#include <bits/stdc++.h>
using namespace std;

int main(){
    long int n,m,t;
    cin >> n >> m >> t;
    long int a,b;
    long int tmp=n;
    long int now=0;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        tmp -= (a-now);
        if(tmp<=0){
            cout << "No";
            return 0;
        }
        tmp = min(n,tmp+(b-a));
        now=b;
    }
    tmp -=(t-now);
    if(tmp<=0)cout << "No";
    else cout << "Yes";
}