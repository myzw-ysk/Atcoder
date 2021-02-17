#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==min(a,min(b,c)))cout << max(b,c)-a << endl;
    else if(b==min(a,min(b,c)))cout << max(a,c)-b << endl;
    else if(c==min(a,min(b,c)))cout << max(a,b)-c << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string S,T;
    cin >> S >> T;
    int flag=0;
    for(int i=0;i<S.length();i++){
        flag=0;
        for(int j=0;j<S.length();j++){
            if(S[(i+j)%S.length()]!=T[j]){flag++; break;}
        }
        if(flag==0){cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum=0;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        sum += a;
    }
    cout << sum-n << endl;
}

//この手のNM>NlogNorNに落とし込む問題が苦手勝ち
//落とす手はソートかにぶたんしかない(今回ならソートしかない)
//決まったらねばりづよくどうやったら使えるかを考えるしかない
//一番効率がいいのは片端の手前だって目の付け所はよかった
//そうすると条件を満たしていないときだけたしていけばよい

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    pair<int,int> p[m];
    for(int i = 0; i < m; i++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p,p+m);
    int MAX=0;
    int ans=0;
    for(int i=0;i<m;i++){
        if(p[i].second>MAX){
            ans++;
            MAX=p[i].first-1;
        }
    }
    cout << ans << endl;
}
