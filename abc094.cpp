#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,x;
    cin >> a >> b >> x;
    if(x>=a && x<= a+b)cout << "YES" << endl;
    else cout << "NO" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int a[m];
    int r=0;
    int l=0;
    for(int i=0;i<m;i++){
        cin >> a[i];
        if(a[i]<x)l++;
        else r++;
    }
    if(l>r)cout << r << endl;
    else cout << l << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y,y+n);
    for(int i=0;i<n;i++){
        if(x[i]<=y[n/2-1])cout << y[n/2] << endl;
        else cout << y[n/2-1] << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int ans=a[0];
    for(int i=1;i<n-1;i++)if(abs((double)ans-(double)(a[n-1]*1.0/2))>abs((double)a[i]-(double)(a[n-1]*1.0/2)))ans=a[i];
    cout << a[n-1] << " " << ans << endl;
}
