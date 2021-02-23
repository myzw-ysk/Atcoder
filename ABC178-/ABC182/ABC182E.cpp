#include <bits/stdc++.h>
using namespace std;

int check1[1505][1505];
int check2[1505][1505];
int block[1505][1505];
int light[1505][1505];
int main(){
    int h,w,n,m;
    cin >> h >> w >> n >> m;
    int a,b,c,d;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        light[a][b]++;
    }
    for(int i=0;i<m;i++){
        cin >> c >> d;
        block[c][d]++;
    }
    for(int i=1;i<=h;i++){
        int akari=0; int kabe=0;
        for(int j=1;j<=w;j++){
            if(akari==0 && block[i][j]>0)kabe=j;
            if(akari==0 && light[i][j]>0)akari=j;
            if(akari>0 && block[i][j]>0){
                for(int k=j-1;k>kabe;k--)check1[i][k]++;
                akari=0; kabe=j;
            }
        }
        if(akari>0)for(int k=w;k>kabe;k--)check1[i][k]++;
    }
    for(int i=1;i<=w;i++){
        int akari=0; int kabe=0;
        for(int j=1;j<=h;j++){
            if(akari==0 && block[j][i]>0)kabe=j;
            if(akari==0 && light[j][i]>0)akari=j;
            if(akari>0 && block[j][i]>0){
                for(int k=j-1;k>kabe;k--)check2[k][i]++;
                akari=0; kabe=j;
            }
        }
        if(akari>0)for(int k=h;k>kabe;k--)check2[k][i]++;
    }
    int ans = 0;
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)ans += (check1[i][j]>0 || check2[i][j]>0);
    cout << ans;
}

//方針に迷いがあった。
//BFSではその行の探索×電球の数探索しなきゃいけないので早々に切るべきだった。
//計算量はO(HW)であることは問題文から自明だったため、
//あかりを壁を見つけたらもう一つ前の壁までもどっても最大で計算量2倍なので怖くない。