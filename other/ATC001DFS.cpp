#include <bits/stdc++.h>
using namespace std;


int H,W;
char c[505][505];
int check[505][505];
void search(int x,int y){
    if(c[x][y]=='#' || x>=H || x<0 || y>=W || y<0)return;
    if(check[x][y]>0)return;
    check[x][y]++;
    search(x+1,y);
    search(x-1,y);
    search(x,y+1);
    search(x,y-1);
}

int main(){
    int i,j;
    int sx,sy;
    int gx,gy;
    cin >> H >> W;
    for(i=0;i<H;i++)for(j=0;j<W;j++){cin >> c[i][j]; check[i][j]=0;}
    for(i=0;i<H;i++)for(j=0;j<W;j++){
        if(c[i][j]=='s'){sx=i;sy=j;}
        if(c[i][j]=='g'){gx=i;gy=j;}
        }
    search(sx,sy);
    if(check[gx][gy]>0)cout << "Yes" <<endl;
    else{cout << "No" <<endl;}
}
