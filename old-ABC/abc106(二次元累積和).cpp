#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n<105)cout << 0 << endl;
    else if(n<135)cout <<1 << endl;
    else if(n<165)cout<< 2 << endl;
    else if(n<189)cout << 3 << endl;
    else if(n<195)cout << 4 << endl;
    else cout <<5 << endl;

}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << a*b-a-b+1 << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    long long int k;
    cin >> S >> k;
    for(long long int i=0;i<S.length();i++){
        if(S[i]!='1'){
            cout << S[i] << endl;
            return 0;
        }
        else if(S[i]=='1' && i==k-1){
            cout << '1' << endl;
            return 0;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int c[505][505];
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    int L,R;
    for(int i=0;i<m;i++){
        cin >> L >> R;
        c[L][R]++;
    }
    for(int j=1;j<n+1;j++){
        for(int i=j;i>1;i--){
            c[i-1][j]+=c[i][j];
        }
    }
    for(int j=n;j>=1;j--){
        for(int i=j;i<n+1;i++){
            c[j][i+1]+=c[j][i];
        }
    }
    for(int i=0;i<q;i++){
        cin >> L >> R;
        cout << c[L][R] << endl;
    }
}