#include<bits/stdc++.h>
using namespace std;
int main(){
    char x,y;
    cin >> x >> y;
    if((int)(x-y)>0)cout << ">";
    else if((int)(x-y)<0)cout << "<";
    else cout << "=";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    x-=z;
    cout << x/(y+z);
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int time=100*(n-m)+1900*m;
    int two=1;
    for(int i=0;i<m;i++)two*=2;
    cout << time*two;
}
//Xに先手番があって主導権がル時点でその二択以外相手にとらせたくない
//くそO(1)数学だった。最後をどちらがとるかに着目したのは良かった
//Yの最小化を妨げるだけでもかちかくとなる
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,z,w;
    cin >> n >> z >> w;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    if(n==1)cout << abs(a[0]-w);
    else{
        cout << max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]));
    }
}