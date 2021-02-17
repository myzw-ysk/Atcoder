//https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_d
//わかるきがしねぇ、あとまわし。

#include <bits/stdc++.h>
using namespace std;

int L;
cin >> L;
int i;
long long int A[L];
for(i=0;i<L;i++)cin >>A[i];
long long int dp[L];

//https://atcoder.jp/contests/atc002/tasks/abc007_3
//DFSみたいな再帰的な書き方をしたらTLEになったでござる
//queueをつかうのがBFSの真髄
#include <bits/stdc++.h>
using namespace std;

int main(){
	int R,C;
	char c[51][51];
	int check[51][51];
	queue<pair<int,int>> que;
    int i,j;
    int sy,sx;
    int gy,gx;
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    for(j=0;j<R;j++)for(i=0;i<C;i++){cin >> c[i][j]; check[i][j]=1e9;}
	check[sx-1][sy-1]=0;
    que.push(pair<int,int> (sx-1,sy-1));
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		int dx[4] = {1,-1,0,0}; //進み方を配列で管理
		int dy[4] = {0,0,1,-1};
		que.pop();
		for(i=0;i<4;i++){
			if(c[x+dx[i]][y+dy[i]]=='.' && check[x+dx[i]][y+dy[i]]>check[x][y]+1){
				check[x+dx[i]][y+dy[i]]=check[x][y]+1;
				que.push(pair<int,int> (x+dx[i],y+dy[i]));//最短が決まったやつをpushしていく
			}
		}
	}
    cout << check[gx-1][gy-1] << endl;
}


