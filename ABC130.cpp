#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,a;
    cin >> x >> a;
    if(x<a)cout << 0 << endl;
    else cout << 10 << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,X;
    cin >> N >> X;
    int L[N];
    for(int i=0;i<N;i++)cin >> L[i];
    int ans=1;
    int d=0;
    for(int i=0;i<N;i++){
        d+=L[i];
        if(d>X)break;
        else ans++;
    }
    cout << ans << endl;
}
//long double は結構な桁でも行ける
#include<bits/stdc++.h>
using namespace std;
int main(){
    long double w,h,x,y;
    cin >> w >> h >> x >> y;
    if(x==w/2.0 && y==h/2.0){
        long double ans = w*h/2.0;
        cout << fixed << setprecision(16);
        cout << ans << " " << 1 << endl;
    }
    else{
        long double ans = w*h/2.0;
        cout << fixed << setprecision(16);
        cout << ans << " " << 0 << endl;        
    }
}
#include<bits/stdc++.h>
using namespace std;
long long int s[100005];
int main(){
    long long int N,K;
    cin >> N >> K;
    long long int a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
        s[i+1] = s[i]+a[i];
    }
    if(s[N]<K)cout << 0 << endl;
    else{
        long long int ans=0;
        for(int i=0;i<N;i++){
            long long int MAX=N;
            long long int MIN=i;
            long long int MID=(MAX+MIN)/2;
            if(s[N]-s[i]>=K){
            while(MAX-MIN>1){
                MID=(MAX+MIN)/2;
                if(s[MID]-s[i]>=K)MAX=MID;
                else MIN=MID;
            }
            ans +=(N-MAX+1);
            }
        }
        cout << ans << endl;
}}

//騙されることなかれ、結局やるべきは累積和のDP
//かならずりべんじすることになる今のレベルでも溶けるDP