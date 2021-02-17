#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,t;
    cin >> n >> x >> t;
    cout << ((n+x-1)/x)*t;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.length();i++)ans += (s[i]-'0');
    if((ans%9)==0)cout << "Yes";
    else cout << "No";
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long long int ans=0;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            ans+=(a[i-1]-a[i]);
            a[i]=a[i-1];
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int check[1005][1005];
int main(){
    int h,w;
    cin >> h >> w;
    int ch,cw;
    cin >> ch >> cw;
    ch--; cw--;
    int dh,dw;
    cin >> dh >> dw;
    dh--; dw--;
    char c[h][w];
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        cin >> c[i][j];
        check[i][j]=-1;
    }
    queue< pair<int,int> > que;
    que.push(make_pair(ch,cw));
    check[ch][cw]=0;
    int x,y;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int count=0;
    while(!que.empty()){
        x=que.front().first;
        y=que.front().second;
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0 && x+dx[i]<h){
                if(y+dy[i]>=0 && y+dy[i]<w){
                    if(c[x+dx[i]][y+dy[i]]=='.' && (check[x+dx[i]][y+dy[i]]== -1 || check[x+dx[i]][y+dy[i]]>check[x][y])){
                        que.push(make_pair(x+dx[i],y+dy[i]));
                        check[x+dx[i]][y+dy[i]]=check[x][y];
                    }
                    else if(c[x+dx[i]][y+dy[i]]=='#'){
                        for(int j=-2;j<3;j++){
                            if(x+j>=0 && x+j<h){
                            for(int k=-2;k<3;k++){
                                if(y+k>=0 && y+k<w){
                                if(c[x+j][y+k]=='.' && (check[x+j][y+k]==-1 || check[x+j][y+k]>(check[x][y]+1))){
                                if((dx[i]>=0 && j>=0) || (dy[i]>=0 && k>=0) || (dx[i]<0 && j<0) || (dy[i]<0 && k<0))que.push(make_pair(x+j,y+k));
                                check[x+j][y+k]=check[x][y]+1;                                   
                                }}
                            }
                            }
                        }
                    }                    
                }
            }
        }
        que.pop();
    }
    cout << check[dh][dw];
}

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;