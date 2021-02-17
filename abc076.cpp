#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,g;
    cin >> r >> g;
    cout << 2 * g - r;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int x=1;
    for(int i=0;i<n;i++){
        if(x<k)x*=2;
        else x+=k;
    }
    cout << x;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int flag;
    char ans[(int)(s.length())];
    for(int j=0;j<(int)s.length();j++)ans[j]=s[j];
    if((int)s.length()-(int)t.length()>0){
    for(int i=0;i<(int)s.length()-(int)t.length();i++){
        flag=0;
        for(int j=0;j<(int)t.length();j++){
            if(s[(int)s.length()-1-i-j]!=t[(int)t.length()-1-j] && s[(int)s.length()-1-i-j]!='?'){
                flag++;
                break;
            }
        }
        if(flag==0){
            for(int j=0;j<(int)t.length();j++)if(ans[(int)s.length()-1-i-j]=='?')ans[(int)s.length()-1-i-j]=t[(int)t.length()-1-j];
            for(int j=0;j<(int)s.length();j++){
                if(ans[j]!='?')cout << ans[j];
                else cout << 'a';
            }
            return 0;
        }
    }
    }
    else if((int)s.length()-(int)t.length()==0){
        flag=0;
        for(int j=0;j<(int)t.length();j++){
            if(s[j]!=t[j] && s[j]!='?'){
                flag++;
                break;
            }
        }
        if(flag==0){
            for(int j=0;j<(int)t.length();j++)if(ans[j]=='?')ans[j]=t[j];
            for(int j=0;j<(int)s.length();j++)cout << ans[j];
            return 0;
        }
    }
    cout << "UNRESTORABLE";
}

//実は知識ゲーではない
//各区間で出せる速度は定式化できる←この定式化をしたうえで各時間について説くのでここがキモ
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int t[n],v[n];
    for(int i=0;i<n;i++)cin >> t[i];
    for(int i=0;i<n;i++)cin >> v[i];


    cout << fixed << setprecision(16);

}