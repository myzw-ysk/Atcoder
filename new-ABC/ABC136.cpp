#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(B+C<=A)cout << 0 << endl;
    else cout << B+C-A << endl;
}

//数的に最速は全探索
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    if(N<10)cout << N << endl;
    else if(N<100) cout << 9 << endl;
    else if(N<1000) cout << N-90 << endl;
    else if(N<10000) cout << 909 << endl;
    else if(N<100000) cout << N-9090 << endl;
    else cout << 90909 << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int h[N];
    int i;
    for(i=0;i<N;i++)cin >> h[i];
    int tmp=h[0];
    int flag=0;
    for(i=0;i<N;i++){
        tmp=max(tmp,h[i]);
        if(tmp>h[i]+1)flag++;
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}
#include<bits/stdc++.h>
using namespace std;

int c[100005];
int ans[100005];
int main(){
    string S;
    cin >> S;
    int N=S.length();
    int i,j;
    int r=0;
    int l=0;
    for(i=1;i<N;i++){
        if(S[i-1]=='R' && S[i]=='R')r++;
        else if(S[i-1]=='L' && S[i]=='L')l++;
        else if(S[i-1]='R' && S[i]=='L'){
            for(j=i-1;j>i-r-2;j--)c[j]=i-1-j;
            r=0;
            }
        else{
            for(j=i-l-1;j<i;j++)c[j]=j-(i-l-1);
            l=0;
        }
    }
    if(S[N-2]='L' && S[N-1]=='L')for(j=N-l-1;j<N;j++)c[j]=j-(N-l-1);
    for(i=0;i<N;i++){
        if(S[i]=='R'){
            if(c[i]%2==0)ans[i+c[i]]++;
            else ans[i+c[i]+1]++;
        }
        else{
            if(c[i]%2==0)ans[i-c[i]]++;
            else ans[i-c[i]-1]++;            
        }
    }
    for(i=0;i<N-1;i++)cout << ans[i] << " ";
    cout << ans[N-1] << endl;
}

//E
//逆に攻め得
//整数問題でアルゴリズム知識はあまり求められないから
//時間があるなら整数問題が一番
//今回は和が一定なことに着目
//妙な設定であればそのことで発生する性質をとらえる(今回ならば和一定)
//それさえつかめれば和の約数について調べていけばよい
//整数問題では問題文をよく読み、その条件で発生する性質を元に攻める
#include<bits/stdc++.h>
using namespace std;

//F
//実は無理ゲーだった、こういうのにはまらないように
//コンビネーションでもDPでもいけない時点で引くべきだった
//mod問題でこの2つでいけない場合は引くべき
#include<bits/stdc++.h>
using namespace std;