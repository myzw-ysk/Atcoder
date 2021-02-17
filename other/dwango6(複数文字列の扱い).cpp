#A 
複数文字列むずい

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 cin >> N;
 string X;
 int t[N];
 int i = 0;
 vector<string> a;
 string sss;
 getline(cin, sss);
for (i=0;i<N;i++){
string s;
 stringstream ss;
 getline(cin, s);
 ss << s;
 ss >> sss;
 ss >> t[i];
 a.push_back(sss);
}
cin >> X;
 string array;
 stringstream ss;
 int num;
 for (i=0;i<N;i++){
   if(a[i]==X)num=i;
   }
   int sum=0;
for(int j=num+1;j<N;j++){
    sum += t[j];
}
 cout << sum << endl;
}

きれいな解き方
mapをつかって文字列をキーとしたファイルを作る
累積和をあとはひくだけ。

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,i,x,y,sum=0;
    string s;
    cin>>n;
    map<string,int>mp;
    for (i=0;i<n;i++){
        cin>>s>>x;
        sum+=x;
        mp[s]=sum;
    }
    cin>>s;
    cout<<sum-mp[s];
}


#B
問題文の誤読は致命的…
おちついて考えれば溶けた問題...
つらい

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 cin >> N;
 int x[N];
 int i;
 for(i=0;i<N;++i){
   cin >> x[i];}
long long int count = 0;
int j;

 for(i=N-1;i<N-1;--i){
    
         count += (x[i+1]-x[i]);
         count %= 1000000007;
     }
     cout << count/N << endl;
}
