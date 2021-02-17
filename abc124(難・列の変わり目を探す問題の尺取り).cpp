#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B;
    cin >> A >> B;
    int ans=0;
     if(A>B){
        ans+=A;
        A--;
    }
    else{
        ans+=B;
        B--;
    }   
    if(A>B){
        ans+=A;
        A--;
    }
    else{
        ans+=B;
        B--;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans=1;
    int h[N];
    for(int i=0;i<N;i++)cin >> h[i];
    int MAX=h[0];
    for(int i=1;i<N;i++){
        if(h[i]>=MAX){
            ans++;
            MAX=h[i];
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
        int S1=0;
        int S2=0;
        for(int i=0;i<S.length();i++){
            if((S[i]-'0')!=(i%2))S1++;
            else if((S[i]-'0')!=((i+1)%2))S2++;
        }
        cout << min(S1,S2) << endl;
}
//変わり目に着目するところはわるくなかった
//変わり目を全部記録してK回変えたときにどこまでいけるかがそのまま答えになった
//変わり目の方針と長さをつなげるところのために時間を削るにはどうしたらいいかを絡めて
//尺取り法による解法、ふんわりしてる…
#include <iostream>
using namespace std;
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int i,j;
    for(j=0;j<n;++j) {
        if(s[j] == '0' and (j == 0 or s[j-1] == '1')) --k;
        if(k < 0) {
            if(s[i] == '0' and s[i+1] == '1')++k;
            ++i;
        }
    }
    cout << j - i << endl;
}

