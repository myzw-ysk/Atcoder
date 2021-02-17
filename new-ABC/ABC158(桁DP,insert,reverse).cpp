#include <bits/stdc++.h>
using namespace std;
 
int main(){
string S;
 cin >> S;
 if(S[0]==S[1] && S[1]==S[2])cout << "No" << endl;
 else{cout << "Yes" << endl;}
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
int j;
long long int N;
long long int A;
long long int B;
long long int count;
long long int C;
cin >> N >> A >> B;
count=N/(A+B);
C=N-(A+B)*count;
if(C>A)C=A;
cout << A*count+C << endl;
}

//この手の母数が少ないけど場合わけが多くなる問題は全部について条件に当てはまるか調べるほうが確実

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
int j;
int A;
int B;
int tmp;
int tmp2;
int count = 0;
cin >> A >>B;
tmp=A*25/2;
if((A*25)%2==1)tmp++;
tmp2=(A+1)*25/2;
if(((A+1)*25)%2==1)tmp2++;
for(i=10*B;i<10*(B+1);i++){
    for(j=tmp;j<tmp2;j++){
    if(i==j){
        cout << i << endl;
        count++;
        break;
    }}
    if(count>0)break;
}
if(count==0)cout << "-1" << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    int Q;
    int i;
    int T;
    int F;
    int count = 0;
    char C;
    cin >> S;
    cin >> Q;
    for(int i=0;i<Q;i++){
        cin >> T;
        if(T==1)count++;
        if(T==2){
            cin >> F >> C;
            if((F==1 && count%2==0) || (F==2 && count%2==1))S.insert(S.begin(),C);
            if((F==2 && count%2==0) || (F==1 && count%2==1))S.insert(S.end(),C);
            }
        }
    if(count%2==1)reverse(S.begin(),S.end());
    cout << S << endl;
    }

//ポイントはPが素数で桁を時に10倍したものを扱うって所を利用してガバく管理するところ
//なんか1つとおらないけど大筋としてはこれ、計算量を減らすことうの一つとして累積和の考え方はつかわれがち
//左からやると10の運上倍されたものが出てきてただしく評価できないのでかならず右からやること
#include<bits/stdc++.h>
using namespace std;

long long int c[10005];
int main(){
    string S;
    long long int N,P,i;
    long long int tmp = 0;
    long long int count = 0;
    long long int ten=1;
    cin >> N >> P;
    cin >> S;
    if(P==2 || P==5){
        for(i=0;i<S.length();i++)if((S[i]-'0')%P==0)count+=(i+1);
    }
    else{
        for(i=0;i<S.length();i++){
            tmp=tmp+ten*(S[N-1-i]-'0');
            tmp%=P;
            ten=(ten*10)%P;
            c[tmp]++;
        }
        count=c[0];
        for(i=0;i<P;i++)count+=c[i]*(c[i]-1)/2;
    }
    cout << count << endl;
}

