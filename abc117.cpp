#include <bits/stdc++.h>
using namespace std;
int main(){
    double x,t;
    cin >> t >> x;
    cout << fixed << setprecision(16);
    cout << t*1.0/x << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int l[n];
    for(int i=0;i<n;i++)cin >> l[i];
    sort(l,l+n);
    int sum=0;
    for(int i=0;i<n-1;i++)sum+=l[i];
    if(l[n-1]>=sum)cout << "No" << endl;
    else cout << "Yes" << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int x[m];
    for(int i=0;i<m;i++)cin >> x[i];
    sort(x,x+m);
    if(n>=m)cout << 0 << endl;
    else{
        int y[m-1];
        for(int i=0;i<m-1;i++)y[i]=x[i+1]-x[i];
        sort(y,y+m-1);
        int ans=0;
        for(int i=0;i<m-n;i++)ans+=y[i];
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    long long int a[n];
    long long int ans=0;
    long long int count;
    for(int i=0;i<n;i++)cin >> a[i];
    for(long long int i=40;i>=0;i--){
            count=0;
            for(int j=0;j<n;j++)if(a[j] & (1LL<<i))count++;
            if(count>=n-count || (1LL<<i)>k)ans+=(1LL<<i)*count;
            else{
                ans+=(1LL<<i)*(n-count);
                k-=(1LL<<i);
            }
    }
    cout << ans << endl;
}