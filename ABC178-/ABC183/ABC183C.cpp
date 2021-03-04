#include <bits/stdc++.h>
using namespace std;

int n,k;
int t[8][8];
int ans=0;

void dfs(int now,int time,int num){
    if(__builtin_popcount(num)==n-1){
        if(time+t[now][0]==k)ans++;
        return;
    }
    else if(time>=k)return;
    else{
    for(int i=1;i<n;i++){
        if(!(num & (1 << i)))dfs(i,time+t[now][i],num+(1 << i));
    }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> t[i][j];
    dfs(0,0,0);
    cout << ans;
}

//再帰しなくても最初よぎった通りnext_perが使える
//next_perはvectorにwhileで全部試すやり方

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int n,k;
	cin >> n >> k;
	vector<vector<int>>T(n,vector<int>(n));
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		cin >> T[i][j];
	}
	
	vector<int>index;
	for(int i=0;i<n;i++)index.push_back(i);

	int ans=0;
	do{
		int time=0;
		for(int i=0;i<n;i++)time+=T[index[i]][index[(i+1)%n]];
		if(time==k)ans++;
	}while(next_permutation(index.begin()+1, index.end()));
	cout << ans;
}