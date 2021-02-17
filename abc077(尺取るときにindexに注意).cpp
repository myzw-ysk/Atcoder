#include<bits/stdc++.h>
using namespace std;
int main(){
    char c[2][3];
    for(int i=0;i<2;i++)for(int j=0;j<3;j++)cin >> c[i][j];
    if(c[0][2]==c[1][0] && c[1][2]==c[0][0] && c[1][1]==c[0][1])cout << "YES";
    else cout << "NO";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i=1;
    while(i*i<=n)i++;
    cout << (i-1)*(i-1);
}
#include<bits/stdc++.h>
using namespace std;
long long int q[100005];
long long int p[100005];
int main(){
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++)cin >> c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int i=0,j=0;
    long long int ans=0;
    for(int k=0;k<n;k++){
        while(i<n && b[k]>=c[i])i++;
        q[k]=n-i;
    }
    for(int k=n-1;k>=0;k--)p[k]=p[k+1]+q[k];
    for(int k=0;k<n;k++){
        while(j<n && a[k]>=b[j])j++;
        ans += p[j];
    }
    cout << ans;
}