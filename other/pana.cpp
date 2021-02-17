#include <bits/stdc++.h>
using namespace std;
 
int main(){
vector<int> v={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
 int i;
 cin >> i;
 cout << v.at(i-1) << endl;
}


#include <bits/stdc++.h>
using namespace std;
 
int main(){
long long int H;
long long int W;
 cin >> H >> W;
 if(H==1 || W==1)cout << 1 <<endl;
 else if((H*W)%2==0)cout << H*W/2 << endl;
 else{cout << (H*W/2)+1 << endl;}
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
long long int a;
long long int b;
long long int c;
 cin >> a >> b >> c;
 if(a+b>=c)cout << "No" <<endl;
 else{
long long int d= (c-a-b)*(c-a-b);
if(d > 4*a*b)cout << "Yes" <<endl;
 else{cout << "No" << endl;}
}}

//文字のDFS
//sk ≤ max{s1, . . . , sk−1} + 1(∀2 ≤ k ≤ N)
//同型のキモはココだった、それまでの最大値を超えることはないっていうのをうまく実装しなきゃいけなかった
#include<bits/stdc++.h>
using namespace std;

int n;
void solve(string now, char mx){
    if(now.length()==n)cout << now << endl;
    else{
        for(char c='a';c<=mx;c++){
            if(c<mx) solve(now+c,mx);
            else solve(now+c,mx+1);
        }
    }
}
int main(){
    cin >> n;
    solve("",'a');
}