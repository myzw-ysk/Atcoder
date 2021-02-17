#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S[2]==S[3] && S[4]==S[5])cout << "Yes" << endl;
    else{cout << "No" << endl;}
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int ans= 1000*(x/500) + 5*((x-(500*(x/500)))/5);
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int i;
    int K,N;
    cin >> K >> N;
    int A[N];
    int tmp = 0;
    for(i=0;i<N;i++)cin >> A[i];
    for(i=1;i<N;i++)if(tmp<A[i]-A[i-1])tmp=(A[i]-A[i-1]);
    if(tmp<K-A[N-1]+A[0])tmp=K-A[N-1]+A[0];
    cout << K-tmp << endl;
    }


//条件が嵩んだら全探索せよ。
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N,X,Y;
    cin >> N >> X >> Y;
    int i,j;
    int ans[N];
    for(j=1;j<N;j++)ans[j]=0;
    for(i=1;i<N;i++){
        for(j=i+1;j<N+1;j++){
            if(max(i-X,X-i)+1+max(j-Y,Y-j)<j-i)ans[max(i-X,X-i)+1+max(j-Y,Y-j)]++;
            else{ans[j-i]++;}
        }
    }
    for(j=1;j<N;j++)cout << ans[j] << endl;
    }


//いつだかのABCの類題、使う最大分だけ持ってきてまとめてソート
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    int i,j;
    long long int p;
    long long int q;
    long long int r;
    long long int sum = 0;
    vector<long long int> aka;
    vector<long long int> mido;
    vector<int> mus;
    for(i=0;i<A;i++){
        cin >> p;
        aka.push_back(p);}
    for(i=0;i<B;i++){
        cin >> q;
        mido.push_back(q);}
    for(i=0;i<C;i++){
        cin >> r;
        mus.push_back(r);}
    sort(aka.begin(),aka.end(),greater<int>());
    sort(mido.begin(),mido.end(),greater<int>());
    for(i=0;i<X;i++)mus.push_back(aka.at(i));
    for(i=0;i<Y;i++)mus.push_back(mido.at(i));  
    sort(mus.begin(),mus.end(),greater<int>());
    for(i=0;i<X+Y;i++)sum += mus.at(i);
    cout << sum << endl;
}

//問題分の意図はつかめてたけど実装方針がどれもよくなくてロスタイムが大きい
//やっぱり数こなして力をつけるしかないのか…？