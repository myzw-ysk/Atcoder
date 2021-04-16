#include <bits/stdc++.h>
using namespace std;

int s[300005];
int main(){
    int n,q;
    cin >> n >> q;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1] = s[i] ^ a[i];
        b[i]=a[i];
    }
    int t,x,y;
    set<int> c;
    for(int i=0;i<q;i++){
        cin >> t >> x >> y;
        if(t==1){
            b[x-1] ^= y;
            c.insert(x-1);
        }
        else{
            int ans = s[y]^s[x-1];
            for(auto i=c.lower_bound(x-1),v=c.lower_bound(y);i!=v;++i){
                if(a[*i]!=b[*i])ans = ans^a[*i]^b[*i];
                
            }
            cout << ans << endl;
        }
    }
}