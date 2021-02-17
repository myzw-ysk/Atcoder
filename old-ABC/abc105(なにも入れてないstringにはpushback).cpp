#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    cout << (n+k-1)/k - n/k << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<=n;i+=4){
        if((n-i)%7==0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout <<"No" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    cin >> n;
    if(n==0)cout << "0" << endl;
    else{
    string S;
    long int i=0;
    long int tmp=2;
    long int hugo = 1;
    while(n!=0L){
        if(n%tmp!=0){
            S.push_back('1');
            n-=((tmp/2)*hugo);
        }
        else S.push_back('0');
        i++;
        hugo*=-1;
        tmp*=2;
    }
    for(int j=S.length()-1;j>=0;j--)cout << S[j];
    cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
map<long long int,long long int> mp;
int main(){
    int n;
    long long int m;
    cin >> n >> m;
    long long int a[n];
    long long int sum =0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        sum %= m;
        mp[sum]++;
    }
    long long int ans=0;
    for(auto u:mp){
        if(u.first==0LL)ans += u.second;
        ans += u.second*(u.second-1)/2;
    }
    cout << ans << endl;
}