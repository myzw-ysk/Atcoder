#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    if(A<10 && B<10)cout << A*B << endl;
    else{cout << -1 << endl;}
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int i;
    int flag=0;
    if(N>81)cout << "No" << endl;
    else{
        for(i=1;i<10;i++)if(N%i==0 && N/i<10)flag++;
        if(flag>0)cout << "Yes" << endl;
        else{cout << "No" << endl;}
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N;
    cin >> N;
    long long int i,j;
    long long int ans = 1e12+10;
    for(i=1;i*i<=N;i++){
        if(N%i==0){
            j=N/i;
            ans = min(ans,i+j-2);
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,x;
    cin >> a >> b >> x;
    double ans;
    if(a*a*b>2*x)ans = 180*atan((double)(a*b*b)/(2.0*x))/M_PI;
    else{ans = 180*atan((2.0*(a*a*b-x))/(double)(a*a*a))/M_PI;}
    cout << fixed << setprecision(16);
    cout << ans << endl;
}

//食べさせる順番決めるの忘れてた
//読み落としはもったいないからやめような…
//Kが18オーダーの時点で見込み薄、こういうときはやはりにぶたんだよな
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N,K;
    long long int i;
    cin >> N >> K;
    long long int A[N],F[N];
    long long int MAX=1e12+10;
    long long int MIN=0;
    long long int MID;
    long long int k;
    long long int sum=0;
    int flag;
    for(i=0;i<N;i++){
        cin >> A[i];
        sum+=A[i];
    }
    if(sum<=K)cout << 0 << endl;
    else{
    for(i=0;i<N;i++)cin >> F[i];
    sort(A,A+N);
    sort(F,F+N);
    long long int B[N];
    for(i=0;i<N;i++)B[i]=A[i]*F[N-i-1];    
    while(MAX-MIN>1){//2で割る以上、絶対0になるとはかぎらない、1にせよ
        k=0;
        flag=0;
        MID=(MAX+MIN)/2;
        for(i=0;i<N;i++){
            if(B[i]>MID)k+=(A[i]-(MID/F[N-i-1]));
            if(k>K){
                flag++;
                break;
            }
        }
        if(flag>0)MIN=MID;
        else{MAX=MID;}
    }
    cout << MAX << endl;
}}