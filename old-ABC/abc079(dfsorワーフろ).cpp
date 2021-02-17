#include<bits/stdc++.h>
using namespace std;
 int main(){
     string n;
     cin >> n;
     if(n[1]==n[2] && (n[0]==n[1] || n[2]==n[3]))cout << "Yes";
     else cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int l[n+1];
    l[0]=2;
    l[1]=1;
    for(int i=2;i<=n;i++)l[i]=l[i-1]+l[i-2];
    cout << l[n];
}
#include<bits/stdc++.h>
using namespace std;
char inc(int i){
    if(i==0)return '+';
    else return '-';
}
int main(){
    string s;
    cin >> s;
    int a=s[0]-'0';
    int b=s[1]-'0';
    int c=s[2]-'0';
    int d=s[3]-'0';
    int tmp;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                tmp=a+b+c+d;
                if(i==1)tmp-=2*b;
                if(j==1)tmp-=2*c;
                if(k==1)tmp-=2*d;
                if(tmp==7){
                    cout << a;
                    cout << inc(i);
                    cout << b;
                    cout << inc(j);
                    cout << c;
                    cout << inc(k);
                    cout << d;
                    cout << "=7";
                    return 0;
                }
            }
        }
    }
}
//方針ミスがあったとはいえ時間のかかりすぎ、dfsだとしてももっと早く書けないと…
//dfsのイメージはどういう遷移なのか早くイメージを固めてしまうこと、決めないで書くのは時間の無駄
#include<bits/stdc++.h>
using namespace std;
int c[10][10];
int C[10];
int a[10];
void solve(int n){
    a[0]=1;
    if(n==10){
        int tmp=0;
        for(int i=1;i<10;i++){
            tmp += c[a[i]][a[i-1]];
            C[a[i]]=min(C[a[i]],tmp);
        }
    }
    else{
        int cou[10];
        for(int i=0;i<10;i++)cou[i]=0;
        for(int i=0;i<n;i++)cou[a[i]]=1;
        for(int i=0;i<10;i++){
            if(cou[i]==0){
                a[n]=i;
                solve(n+1);
            }
        }
    }
}
int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)cin >> c[i][j];
        C[i]=c[i][1];
    }
    solve(1);
    int x;
    int ans=0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        cin >> x;
        if(x>1 || x==0)ans+=C[x];
    }
    cout << ans;
}

//じつはわーシャルフロイドで真ん中を決めてそれより小さければ更新でも良かった
//というかこれが最速だった…　んん
# include < cstdio >
# define rep (i , n ) for ( int ( i )=0;( i ) <( n );( i )++)
int c [10][10];
int H ,W ,A , res ;
int main ()
{
scanf ("% d % d " ,&H ,& W );
rep (i ,10) rep (j ,10) scanf ("% d " ,& c [ i ][ j ]);
rep (k ,10) rep (i ,10) rep (j ,10)
if ( c [ i ][ j ] > c [ i ][ k ]+ c [ k ][ j ]) c [ i ][ j ]= c [ i ][ k ]+ c [ k ][ j ];
rep (i , H ) rep (j , W )
{
scanf ("% d " ,& A );
if (A >=0) res += c [ A ][1];
}
printf ("% d \ n " , res );
}