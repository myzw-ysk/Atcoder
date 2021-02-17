#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    cout << (n-1)*(m-1);
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    cout << s[0] << s.length()-2 << s[s.length()-1];
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> four;
    queue<int> two;
    queue<int> one;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a%4==0)four.push(a);
        else if(a%2==0)two.push(a);
        else one.push(a);
    }
    long long int x[n];
    for(int i=0;i<n;i++){
        if(i%2==0 && !one.empty()){
            x[i]=one.front();
            one.pop();
        }
        else if(i%2==0 && !two.empty()){
            x[i]=two.front();
            two.pop();
        }
        else if(i%2==0 && !four.empty()){
            x[i]=four.front();
            four.pop();
        }
        else if(i%2==1 && !four.empty()){
            x[i]=four.front();
            four.pop();
        }
        else if(i%2==1 && !two.empty()){
            x[i]=two.front();
            two.pop();
        }
        else if(i%2==1 && !two.empty()){
            x[i]=one.front();
            one.pop();
        }
    }
    for(int i=0;i<n-1;i++){
        if((x[i]*x[i+1])%4!=0){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int c[h][w];
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int i; int j;
    int tmp=0; int color=1;
    for(i=0;i<h;i++){
        if(i%2==0){
            for(j=0;j<w;j++){
                c[i][j]=color;
                tmp++;
                if(tmp==a[color-1]){
                    color++;
                    tmp=0;
                }
            }
        }
        else{
            for(j=w-1;j>=0;j--){
                c[i][j]=color;
                tmp++;
                if(tmp==a[color-1]){
                    color++;
                    tmp=0;
                }
            }
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w-1;j++)cout << c[i][j] << " ";
        cout << c[i][w-1] << endl;
    }
}

