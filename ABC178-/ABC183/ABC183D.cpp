#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,w;
    cin >> n >> w;
    long long int p[n];
    pair<pair<long long int,long long int>, long long int> stp[n];
    for(int i=0;i<n;i++)cin >> stp[i].first.first >> stp[i].first.second >> stp[i].second;
    sort(stp,stp+n);
    long long int tmp_w = 0;
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int> >,greater<pair<long long int,long long int> > > que;
    for(int i=0;i<n;i++){
        while(!que.empty() && que.top().first <= stp[i].first.first){
            tmp_w -= que.top().second;
            que.pop();
        }
        tmp_w += stp[i].second;
        if(tmp_w>w){
            cout << "No";
            return 0;
        }
        que.push(make_pair(stp[i].first.second,stp[i].second));
    }
    cout << "Yes";
}