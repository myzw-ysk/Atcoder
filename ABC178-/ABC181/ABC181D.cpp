#include <bits/stdc++.h>
using namespace std;

int cou[10];
int main(){
    string S;
    cin >> S;
    if(S.length()==1){
        if(S=="8")cout << "Yes";
        else cout << "No";
        return 0;
    }
    else if(S.length()==2){
        if( ((S[0]-'0')*10+(S[1]-'0'))%8==0
        || ((S[1]-'0')*10+(S[0]-'0'))%8==0 )cout << "Yes";
        else cout << "No";
        return 0;
    }    
    else{
      for(int i=0;i<S.length();i++)cou[(S[i]-'0')]++;  
    for(int i=1008;i<2000;i+=8){
        string s = to_string(i);
        map<int,int> mp;
        
        mp[s[1]-'0']++; mp[s[2]-'0']++; mp[s[3]-'0']++;
        if(cou[s[3]-'0']>=mp[s[3]-'0'] 
        && cou[s[1]-'0']>=mp[s[1]-'0']
        && cou[s[2]-'0']>=mp[s[2]-'0']
        && (s[1]-'0')*(s[2]-'0')*(s[3]-'0')>0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    }
}