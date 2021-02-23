#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x,y,a,b;
    cin >> x >> y >> a >> b;
    long long int ans=0;
    while(a*x<y && a*x<=x+b && a*x>0){
        x *= a;
        ans++; 
    }
    ans += (y-1-x)/b;
    cout << ans;
}

//数式で書いたときにうまく計算できなくても重要な性質が見つかることもある
//今回の場合は先にAをやることと、その回数はせいぜい対数回しかないことに着目