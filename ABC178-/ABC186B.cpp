#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int a[h][w];
    int ans=1e9;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        cin >> a[i][j];
        ans = min(ans,a[i][j]);
    }
    int sum = 0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)sum += (a[i][j]-ans);
    cout << sum;
}