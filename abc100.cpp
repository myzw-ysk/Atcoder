#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a<=8 && b<=8)cout << "Yay!" << endl;
    else cout << ":(" << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,n;
    cin >> d >> n;
    if(d==0 && n<100)cout << n << endl;
    else if(d==0)cout << 101 << endl;
    else if(d==1 && n<100)cout << n*100 << endl;
    else if(d==1)cout << 10100 << endl;
    else if(d==2 && n==100)cout << 1010000 << endl;
    else cout << n*10000 << endl;

}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    int tmp=0;
    int ans=0;
    while(tmp<n){
        if(a[tmp]%2==0){
            a[tmp]/=2;
            ans++;
        }
        else tmp++;
    }
    cout << ans << endl;
}


//方針はあっているはずなのに引っかかってでれない…
//と思ったが、個々のMAXのケースではなくて
//それぞれ正負で取った場合の和を検討してやるのが正解。
//今回は順位が知りたいってわけじゃないからあのルールは不適
//実際にそれぞれのケースを考える。
#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, sum, mx=-9e20, a[1005][3], s[1005];
int main() {
	int i, j, k;
	cin>>n>>m;
	for(i=0; i<n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(k=0; k<8; k++) {
		for(i=0; i<n; i++) {
			s[i] = 0;
			for(j=0; j<3; j++) s[i] += (k>>j&1 ? a[i][j] : -a[i][j]);
		}
		sort(s, s+n);
		sum = 0;
		for(i=n-1; i>=n-m; i--) sum += s[i];
		mx = max(mx, sum);
	}
	cout<<mx;
	return 0;
}
