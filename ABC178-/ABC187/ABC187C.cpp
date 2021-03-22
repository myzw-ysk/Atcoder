#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> n_q;
    map<string,int> q;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        decltype(s)::iterator it = s.begin();
        char& c = *it;
        if(c == '!')q[s]++;
        else n_q[s]++;
    }
    for(auto u:n_q){
        if(q["!"+u.first]>0){
            cout << u.first;
            return 0;
        }
    }
    cout << "satisfiable";
}