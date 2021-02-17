#include <bits/stdc++.h>
using namespace std;
int main(){
    int d;
    cin >> d;
    cout << "Christmas";
    while(d<25){
        cout << " Eve";
        d++;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    sort(p,p+n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=p[i];
        if(i==n-1)sum-=p[i]/2;
    }
    cout << sum << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n>>k;
    int p[n];
    for(int i=0;i<n;i++)cin >> p[i];
    sort(p,p+n);
    int ans=1e9;
    for(int i=0;i<n-k+1;i++){
        ans=min(ans,p[i+k-1]-p[i]);
    }
    cout << ans << endl;
}

//コーディング試験の元ネタ
#include <bits/stdc++.h>
using namespace std;

long long int w[51];
long long int b[51];
long long int p[51];

void burg(int n){
    w[0]=1; b[0]=0; p[0]=1;
    for(int i=0;i<n;i++){
        b[i+1]=2+2*b[i];
        p[i+1]=1+2*p[i];
        w[i+1]=b[i+1]+p[i+1];
    }
}
long long int answer(long long int y,int level){
    if(y==0)return 0;
    else if(y==w[level] || y==w[level]-1)return p[level];
    else if(y==1)return 0;
    else if(y>=2+w[level-1])return 1+p[level-1]+answer(y-2-w[level-1],level-1);
    else return answer(y-1,level-1);
}
int main(){
    int n;
    long long int x;
    cin >> n >> x;
    burg(n);
    cout << answer(x,n) << endl;
}