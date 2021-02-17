#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a*b%2==0)cout << "Even" << endl;
    else cout << "Odd" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(b<10){
        for(int i=2;i*i<=a*10+b;i++){
            if(i*i==a*10+b){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    else if(b<100){
        for(int i=2;i*i<=a*100+b;i++){
            if(i*i==a*100+b){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    else{
        for(int i=2;i*i<=a*1000+b;i++){
            if(i*i==a*1000+b){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }        
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int t[n+1],x[n+1],y[n+1];
    t[0]=0; x[0]=0; y[0]=0;
    for(int i=1;i<n+1;i++){
        cin >> t[i] >> x[i] >> y[i];
        if(t[i]-t[i-1] < abs(x[i]-x[i-1])+abs(y[i]-y[i-1])
          || ( (t[i]-t[i-1] > abs(x[i]-x[i-1])+abs(y[i]-y[i-1])) 
          && ( ( (t[i]-t[i-1])%2 != abs(x[i]-x[i-1])%2 + abs(y[i]-y[i-1])%2 ) )) ){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << endl;
}

//累積和で計算削減をするというオチがついているが…
//まったく方針に検討がつかなかったのが問題。
//方針としては取りうる正方形の大きさをきめうちして、最大で何個とれるかに絞り込む
#include<bits/stdc++.h>
using namespace std;
int main(){

}