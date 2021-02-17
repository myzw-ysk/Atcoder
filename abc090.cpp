#include<bits/stdc++.h>
using namespace std;
int main(){
    char c[3][3];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin >> c[i][j];
    for(int i=0;i<3;i++)cout << c[i][i];
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int ans=0;
    for(int i=a;i<=b;i++){
        string s = to_string(i);
        reverse(s.begin(),s.end());
        if(to_string(i)==s)ans++;
    }
    cout <<ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m;
    cin >> n >> m;
    if(n>2 && m>2)cout << (n-2)*(m-2) << endl;
    else if(n==1 && m==1)cout << 1 << endl;
    else if(min(n,m)==1 && max(n,m)>1)cout << max(n,m)-2 << endl;
    else cout << 0 << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;
    cin >> n >> k;
    long long int ans=0;
    for(long long int i=k+1;i<=n;i++){
        if(k==0){
            ans += n/i;
            long long int mod = min((n+i-1)%i+1,i-1);
            if(i>1)ans += (((n+i-1)/i)*mod+(((n+i-1)/i-1)*(i-mod-1)));
        }
        else{
            int mod = min((n+i-k)%i+1,i-k);
            ans += ((n+i-k)/i)*(mod)+(((n+i-k)/i-1)*(i-k-mod));            
        }
    }
    cout << ans << endl;
}

