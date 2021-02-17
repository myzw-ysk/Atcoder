#include<bits/stdc++.h>
using namespace std;
int main(){
    int r;
    cin >> r;
    double a = r*2.0*M_PI;
    cout << fixed << setprecision(16);
    cout << a << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    int i;
    cin >> N >> M;
    long int a;
    long int sum =0;
    for(i=0;i<M;i++){
        cin >> a;
        sum += a;
    }
    if(sum>N)cout << -1 << endl;
    else cout << N-sum << endl;
}
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    int N;
    cin >> N;
    int c;
    int i;
    for(i=2;i<N+1;i++){
        cin >> c;
        a[c]++;
    }
    for(i=1;i<N+1;i++)cout << a[i] << endl;
}
//10^100に騙されすぎ、本質は個数。落ち着いて何を知りたいのか見極める
#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;

int main(){
    int N,K;
    cin >> N >> K;
    int i;
    long long int tmp;
    long long int ans=0;
    long long int MIN=0;
    long long int MAX=N;
    for(i=1;i<=N+1;i++){
        tmp=(MAX-MIN)+1;
        MIN+=i;
        MAX+=(N-i);
        if(i>=K){
            ans+=tmp;
            ans%=mod;
        }
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;