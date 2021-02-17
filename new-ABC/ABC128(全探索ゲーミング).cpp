//パフォ900出てるけどBCで手間取りすぎ…

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int A;
int P;
 cin >> A >> P;
 cout<< (A*3+P)/2 << endl;
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i,j;
int N;
cin >> N;
vector<string> S;
string SS;
int P[N];
int ans[N];
for(i=0;i<N;i++){
  cin >> SS >> P[i];
  S.push_back(SS);}
int count=1;
for(i=0;i<N;i++){
    count = 1;
for(j=0;j<N;j++){
if(i==j)continue;
else{
  if(S[i]>S[j])count++;
  else if(S[i]==S[j]){
      if(P[i]<P[j])count++;
  }}}
 ans[count-1]=i+1;
}
for(i=0;i<N;i++)cout << ans[i]<<endl;
}

//pairをうまく使いたかったけど断念、正解は二重でpairにする、だったみたい。
//あとは高い順をひきだすためにマイナスをつけるテクニックはすごい、簡潔
char in[120];
pair<pair<string,int>,int> p[110];
int main(){
int a;scanf("%d",&a);
for(int i=0;i<a;i++){
int t;scanf("%s%d",in,&t);
string tmp=in;
p[i]=make_pair(make_pair(in,-t),i);
}
std::sort(p,p+a);
for(int i=0;i<a;i++)printf("%d\n",p[i].second+1);
}


#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i,j,l;
int N,M;
cin >> N >> M;
int count = 1;
for(i=0;i<N;i++)count*=2;
vector<int> S[M];
int s;
int p[M];
int k[M];
int ans=0;
for(i=0;i<M;i++){
  cin >> k[i];
  for(j=0;j<k[i];j++){cin >> s;
  S[i].push_back(s);}}
for(i=0;i<M;i++)cin >> p[i];
int sw[N];
for(i=0;i<N;i++)sw[i]=0;
int tmp;
int anco;
for(i=0;i<count;i++){
    tmp=i;
    j=0;
    while(tmp!=0){
        sw[j]=tmp%2;
        tmp/=2;
        j++;
    }
    for(j=0;j<M;j++){
        anco=0;
        for(l=0;l<k[j];l++)if(sw[S[j].at(l)-1]==1)anco++;
        if((anco%2)!=p[j])break;
        else if(j==M-1)ans++;
    }
}
cout << ans << endl;
}


//K回行わなきゃダメというわけではなく、までってこと
//あとはCとDは順番よらないマイナスを捨てる動作だと考えると
//NかK以下の全パターンの取り出し方を調べればよい
//結局Dも全探索…

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i,j,k;
int N,K;
cin >> N >> K;
int M = min(N,K);
int V[N+2];
vector<int> H;
vector<int> H2;
int count = 0;
int count2;
int ans = 0;
int tmp;
V[0]=0;
V[N+1]=0;
for(i=1;i<N+1;i++)cin >> V[i];
for(i=0;i<M+1;i++){
    count += V[i];
    if(V[i]<0)H.push_back(V[i]);
    count2=count;
    for(k=0;k<(int)H.size();k++)H2.push_back(H.at(k));
    for(j=0;j<M-i+1;j++){
        count2+=V[N+1-j];
        if(V[N+1-j]<0)H2.push_back(V[N+1-j]);
        sort(H2.begin(),H2.end());
        tmp = count2;
        for(k=0;k<min(K-i-j,(int)H2.size());k++)tmp -= H2.at(k);
        if(tmp>ans)ans=tmp;
    }
    H2.clear();
}
cout << ans << endl;
}

