#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int j = i;
        int flag = 0;
        while(j>0){
            if(j%10==7){
                ans++;
                flag++;
                break;
            }
            j /= 10;
        }
        j = i;
        while(j>0 && flag==0){
            if(j%8==7){
                ans++;
                flag++;
                break;
            }
            j /= 8;            
        }
    }
    cout << n-ans;
}