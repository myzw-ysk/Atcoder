#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin >> n >> a;
    cout << n*n-a;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int x;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> x;
        ans +=2*min(abs(x-k),abs(x));
    }
    cout << ans;
}
//実装重いゲー。
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;

int main(){
    cin >> a >> b >> c >> d >> e >> f;
    int a_wat=0; int b_wat=0;
    int c_sug=0; int d_sug=0;
    int ans_w=100; int ans_s=0;
    while(a_wat<f){
        b_wat=0;
        while(a_wat+b_wat<f){
            c_sug=0;
            if(a_wat==0)b_wat+=b*100;
            while(a_wat+b_wat+c_sug<=f){
                d_sug=0;
                while(a_wat+b_wat+c_sug+d_sug<=f && (c_sug+d_sug)*100<=(a_wat+b_wat)*e){
                    if((c_sug+d_sug)*100==(a_wat+b_wat)*e){
                        cout << a_wat+b_wat+c_sug+d_sug << " " << c_sug+d_sug;
                        return 0;
                    }
                    else if((c_sug+d_sug)*ans_w>=(a_wat+b_wat)*ans_s){
                        ans_w=a_wat+b_wat;
                        ans_s=c_sug+d_sug;
                    }
                    d_sug+=d;
                }
                c_sug+=c;
            }
            b_wat+=b*100;
        }
        a_wat+=a*100;
    }
    cout << ans_w+ans_s << " " << ans_s;
}

//わーシャルを理解しているかがわかるいい問題
//結局イコールになるやつかつ経由が端点と一致してないやつの和を取ればよかった
#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[305][305];
int c[305][305];
int main(){
    cin >> n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> a[i][j];
    for (int k = 0; k < n; k++){       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                if(a[i][j]>a[i][k] + a[k][j]){
                    cout << -1;
                    return 0;
                }
                else if(a[i][j] < a[i][k] + a[k][j])c[i][j]++;
            }
        }
    }
    long long int ans=0;
    for (int i = 0; i < n; i++) {    // 始点
        for (int j = 0; j < n; j++) {  // 終点
            if(c[i][j]==n-2)ans+=a[i][j];
        }
    }
    cout << ans/2;
}
