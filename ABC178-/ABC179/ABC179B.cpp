#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int d[n][2];
    int flag=0;
    for(int i=0;i<n;i++){
        cin >> d[i][0] >> d[i][1];
        if(d[i][0]==d[i][1])flag++;
        else flag=0;
        if(flag==3){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}