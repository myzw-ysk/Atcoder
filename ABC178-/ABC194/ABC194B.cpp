#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];
    int a_i,b_i,a_j,b_j;
    int a_ans=1e9; int b_ans=1e9;
    int a_ans2=1e9; int b_ans2=1e9;
    for(int i=0;i<n;i++){
        if(a_ans>=a[i]){
            a_j=a_i; a_ans2=a_ans;
            a_i=i; a_ans=a[i];
        }
        else if(a_ans2>=a[i]){
            a_j=i; a_ans2=a[i];
        }
        if(b_ans>=b[i]){
            b_j=b_i; b_ans2=b_ans;
            b_i=i; b_ans=b[i];
        }
        else if(b_ans2>=b[i]){
            b_j=i; b_ans2=b[i];
        }
    }
    if(a_i!=b_i)cout << max(a_ans,b_ans);
    else{
        cout << min(a_ans+b_ans,min(max(a_ans,b_ans2),max(a_ans2,b_ans)));
    }
}