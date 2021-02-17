#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << min(a,b)+min(c,d) << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,x;
    cin >> n >> d >> x;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=1;i<d+1;i++){
        for(int j=0;j<n;j++){
            if(a[j]==1)x++;
            else if(i%a[j]==1)x++;
        }
    }
    cout << x << endl;
}
#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
    int n;
    cin >> n;
    int a[n+2];
    a[0]=0;
    for(int i=1;i<n+1;i++){
        cin >> a[i];
        b[i] = b[i-1] + abs(a[i]-a[i-1]);
    }
    b[n+1] = b[n] + abs(a[0]-a[n]);
    a[n+1]=0;
    for(int i=1;i<n+1;i++)cout << b[n+1] - abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]) << endl;
}

//なんか一般化してやれる方法があるのだろうという見通し
//100*100にまず決め打ちしようという発想は良かった
//1以上、に着目して上下を一色に染めて差分をうまく染めていく戦略
//いかに狭い問題に設定しなおしていくかがキモ
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << 100 << " " << 100 << endl;
    char c[101][101];
    for(int i=0;i<50;i++)for(int j=0;j<100;j++)c[i][j]='.';
    for(int i=50;i<100;i++)for(int j=0;j<100;j++)c[i][j]='#';
    int i=0; int j=0;
    int k=0; int l=0;
    while(i<b-1){
        c[k][l]='#';
        i++;
        l+=2;
        if(l>=100){
            l=0;
            k+=2;
        }
    }
    k=51; l=0;
    while(j<a-1){
        c[k][l]='.';
        j++;
        l+=2;
        if(l>=100){
            l=0;
            k+=2;
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<100;j++)cout << c[i][j];
        cout << endl;
    }
}