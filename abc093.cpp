#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<3;i++){
        if(s[i]=='a')a++;
        else if(s[i]=='b')b++;
        else c++;
    }
    if(a==0 || b==0 || c==0)cout << "No" << endl;
    else cout << "Yes" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    for(int i=a;i<b+1;i++)if(i<a+k || i>=b-k+1)cout << i << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    if((2*a[2]-a[0]-a[1])%2==0)cout << (2*a[2]-a[0]-a[1])/2 << endl;
    else cout << 2+(2*a[2]-a[0]-a[1])/2 << endl;
}
//a*b<=kなものにフォーカスって路線自体は悪くないけど
//場合分けによってこれをなんとかする場合もあるとしろう
//今回は積の平方根を使ってみてやるのがよかった
//積にフォーカスしたときにどうとるのが最大になるのかをもっと具体的に詰める努力をする
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    long long int a,b;
    long long int ans;
    for(int i=0;i<q;i++){
        cin >> a >> b;

    }
}