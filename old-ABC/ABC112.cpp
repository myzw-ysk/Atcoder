#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    if(N==1)cout <<"Hello World" << endl;
    else cout << A+B << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    int c,a;
    int ans=1e9;
    for(int i=0;i<n;i++){
        cin >> c >> a;
        if(a<=t && ans>c)ans=c;
    }
    if(ans<1e9)cout << ans << endl;
    else cout << "TLE" << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n],y[n],h[n];
    int a_h;
    int flag;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i] >> h[i];
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            flag=0;
            a_h=0;
            for(int k=0;k<n;k++){
                if(a_h==0 && h[k]>0)a_h=h[k]+abs(i-x[k])+abs(j-y[k]);
                else if(a_h>0 && h[k]>0){
                    if(a_h!=h[k]+abs(i-x[k])+abs(j-y[k])){
                        flag++;
                        break;
                    }}
                else if(a_h>0){
                    if(a_h-abs(i-x[k])-abs(j-y[k])>0){
                        flag++;
                        break;
                    }
                }
            }
            if(flag==0){
            for(int k=0;k<n;k++){
                if(h[k]>0){
                    if(a_h!=h[k]+abs(i-x[k])+abs(j-y[k])){
                        flag++;
                        break;
                    }}
                else{
                    if(a_h-abs(i-x[k])-abs(j-y[k])>0){
                        flag++;
                        break;
                    }
                }
            }}
            if(flag==0){
                cout << i << " " << j << " " << a_h << endl;
                break;
            }
        }
        if(flag==0)break;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int ans=1;
    int j;
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            j=m/i;
            if(m/i>=n)ans=max(ans,i);
            if(m/j>=n)ans=max(ans,j);
        }
    }
    cout << ans << endl;
}