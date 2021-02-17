#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,t;
    cin >> x >> t;
    cout << max(x-t,0) << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.length();i+=2)cout << s[i];
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
        mp[a[i]-1]++;
        mp[a[i]+1]++;
        ans=max(ans,max(mp[a[i]],max(mp[a[i]-1],mp[a[i]+1])));
    }
    cout << ans;
}

//数値の入れ替えはswap(x,y)でもできるよ…
//みんな解けている貪欲問題でのコツは小細工を削ること
#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main(){
    int n;
    cin >> n;
    int p[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> p[i];
        if(p[i]==(i+1))c[i]++;
    }
    for(int i=0;i<n;i++){
        if(c[i]==1){
            c[i]=0;
            if(i<n-1)c[i+1]=0;
            ans++;
        }
    }
    cout << ans;
}


