//結局場合分けしてつぶすしかなかった問題

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(r1==r2 && c1==c2){
        cout << 0;
        return 0;
    }
    if(abs(r1-r2)+abs(c1-c2)<=3){
            r1=r2;
            c1=c2;
            cout << 1;
            return 0;
    }
    else if(r1==r2){
        if((c1-c2)%2==0 || abs(c1-c2)<=6){
            cout << 2;
            return 0;
        }
        else{
            cout << 3;
            return 0;
        }
    }
    else if(c1==c2){
        if((r1-r2)%2==0 || abs(r1-r2)<=6){
            cout << 2;
            return 0;
        }
        else{
            cout << 3;
            return 0;
        }
    }
    else if(abs(c2-(c1+r2-r1))==0 || abs(c2-(c1+r1-r2))==0 ||
        abs(r2-(r1+c2-c1))==0 || abs(r2-(r1+c1-c2))==0 ){
            cout << 1;
            return 0;
        }
    else{
        if(abs(c2-(c1+r2-r1))<=3 || abs(c2-(c1+r1-r2))<=3 ||
        abs(r2-(r1+c2-c1))<=3 || abs(r2-(r1+c1-c2))<=3 ){
            cout << 2;
            return 0;
        }
        else if((c2-(c1+r2-r1))%2==0 || (c2-(c1+r1-r2))%2==0
            || (r2-(r1+c2-c1))%2==0 || (r2-(r1+c1-c2))%2==0){
                cout << 2;
                return 0;
        }
        else{
            cout << 3;
            return 0;
        }
        }        
}
    