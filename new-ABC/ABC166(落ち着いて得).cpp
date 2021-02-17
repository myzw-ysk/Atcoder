#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    if(S=="ABC") cout << "ARC" << endl;
    else cout << "ABC" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    int n,k;
    cin >> n >> k;
    int d[k];
    int A;
    for(int i=0;i<k;i++){
        cin >> d[i];
        for(int j=0;j<d[i];j++){
            cin >> A;
            a[A]++;
        } 
    }
    int ans=0;
    for(int i=1;i<n+1;i++)if(a[i]==0)ans++;
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

int ans[100005];
int main(){
    int n,m;
    int a,b;
    cin >> n >> m;
    int h[n];
    for(int i=0;i<n;i++)cin >> h[i];
    for(int i=1;i<m+1;i++){
        cin >> a >> b;
        if(h[a-1]<=h[b-1])ans[a-1]--;
        if(h[b-1]<=h[a-1])ans[b-1]--;
    }
    int answer=0;
    for(int i=0;i<n;i++)if(ans[i]>=0)answer++;
    cout << answer << endl;
}
#include<bits/stdc++.h>
using namespace std;
map<long long int ,long long int> mp;
int main(){
    long long int az;
    long long int x;
    cin >> x;
    for(long long int i=1;i<2005;i++){
        az=i*i*i*i*i;
        mp[az]=i;
        mp[-az]=-i;
    }
    long long int tmp;
    long long int A,B;
    for(long long int i=1;i<2005;i++){
        tmp=i*i*i*i*i;
        if(tmp==x){
            A=i;
            B=0;
            break;
        }
        else if(mp[-tmp-x]!=0){
            A=-i;
            B=mp[-tmp-x];
            break;
        }
        else if(mp[tmp-x]!=0){
            A=i;
            B=mp[tmp-x];
            break;
        }
        else if(mp[x-tmp]!=0){
            A=i;
            B=mp[x-tmp];
            break;
        }
    }
    cout << A << " " << B << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    long int N;
    cin >> N;
    long int a[N];
    map<long int,long int> mp;
    long int ans=0;
    for(long int i=0;i<N;i++){
        cin >> a[i];
        mp[i+1+a[i]]++;
        ans+=mp[i+1-a[i]];
    }
    cout << ans << endl;
}