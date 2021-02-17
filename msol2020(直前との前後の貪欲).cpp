#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    cout << 8-(x-400)/200;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    if(c>b && b>a){
        cout << "Yes";
        return 0;
    }
    for(int i=0;i<k;i++){
        if(a>=b)b*=2;
        else if(b>=c)c*=2;
        if(c>b && b>a){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=k;i<n;i++){
        if(a[i]>a[i-k])cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
//上がるところだけ着目していればよいってタイプの問題(その発想自体は途中はあったのに…)
//さがる場所があったってことはそのあと上がったら結果は同じでどのみち直接上がるポイントだけつけていけばよい
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int a[n];
    long long int mon=1000;//long にしないとだめなほどもうかるらしい
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1])mon+=(mon/a[i-1])*(a[i]-a[i-1]);
    }
    cout << mon;
}