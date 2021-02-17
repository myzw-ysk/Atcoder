#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    for(int i=0;i<3;i++){
        if(S[i]=='1')S[i]='9';
        else if(S[i]=='9')S[i]='1';
    }
    cout << S << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=111;i<1000;i+=111){
        if(i>=n){
            cout << i << endl;
            break;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int c_a[100005],c_b[100005];
int main(){
    int n;
    cin >> n;
    int a[n/2],b[n/2];
    for(int i=0;i<n;i++){
        if(i%2==0){
            cin >> a[i/2];
            c_a[a[i/2]]++;
        }
        else{
            cin >> b[(i-1)/2];
            c_b[b[(i-1)/2]]++;
        }
    }
    int max_a=0;
    int sec_a=0;
    int max_b=0;
    int sec_b=0;
    for(int i=0;i<n/2;i++){
        if(c_a[max_a]<=c_a[a[i]] && max_a!=a[i]){
            sec_a=max_a;
            max_a=a[i];
        }
        else if(c_a[sec_a]<=c_a[a[i]] && sec_a!=a[i] && max_a!=a[i]){
            sec_a=a[i];
        }
        if(c_b[max_b]<=c_b[b[i]] && max_b!=b[i]){
            sec_b=max_b;
            max_b=b[i];
        }
        else if(c_b[sec_b]<=c_b[b[i]] && sec_b!=b[i] && max_b!=b[i]){
            sec_b=b[i];
        }      
    }
    if(max_a!=max_b)cout << n-c_a[max_a]-c_b[max_b] << endl;
    else if(c_a[sec_a]>c_b[sec_b])cout << n-c_a[sec_a]-c_b[max_b] << endl;
    else cout << n-c_a[max_a]-c_b[sec_b] << endl;
}