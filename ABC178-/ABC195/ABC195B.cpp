#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,w;
    cin >> a >> b >> w;
    w *=1000;
    int tmp_max=w/a+1;
    int tmp_min=w/b;
    vector<int> ans;
    for(int i=tmp_min;i<=tmp_max;i++){
        if(w>=a*i && w<=b*i)ans.push_back(i);
    }
    if(ans.empty())cout << "UNSATISFIABLE";
    else cout << *ans.cbegin() << " " << *ans.rbegin();
}