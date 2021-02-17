#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin >> n >> a;
    if(n%500<=a)cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int A=0;
    int B=0;
    for(int i=0;i<n;i++){
        if(i%2==0)A+=a[n-1-i];
        else B+=a[n-1-i];
    }
    cout << A-B << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int c[3][3];
    int sum=0;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        cin >> c[i][j];
        sum += c[i][j];
    }
    if(sum==3*(c[0][0]+c[1][1]+c[2][2]))cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int h,w;
    cin >> h >> w;
	char c[51][51];
	int check[51][51];
	queue<pair<int,int>> que;
    int i,j;
    int ans=0;
    for(i=1;i<h+1;i++)for(j=1;j<w+1;j++){cin >> c[i][j]; check[i][j]=1e9; if(c[i][j]=='#')ans++;}
    for(i=1;i<h+1;i++)c[i][0]='#';
    for(j=1;j<w+1;j++)c[0][j]='#';
	check[1][1]=1;
    que.push(pair<int,int> (1,1));
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		int dx[4] = {1,-1,0,0};
		int dy[4] = {0,0,1,-1};
		que.pop();
		for(i=0;i<4;i++){
			if(c[x+dx[i]][y+dy[i]]=='.' && check[x+dx[i]][y+dy[i]]>check[x][y]+1){
				check[x+dx[i]][y+dy[i]]=check[x][y]+1;
				que.push(pair<int,int> (x+dx[i],y+dy[i]));
			}
		}
	}
    if(check[h][w]==1e9)cout << -1 << endl;
    else cout << h*w-check[h][w]-ans << endl;
}