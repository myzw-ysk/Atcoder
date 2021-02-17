#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B;
    cout << max(max(A+B,A-B),A*B);
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int K,X,i;
    cin >> K >> X;
    for(i=max(-1000000,X-K+1);i<min(1000001,X+K);i++)cout << i << " ";
}


//stringにもソートは使えます！
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s,tmp;
    vector<string> S;
    int i;
    long long int count=0;
    long long int tmp_count=1;
    for(i=0;i<N;i++){
        cin >> s;
        sort(s.begin(),s.end());
        S.push_back(s);
    }
    sort(S.begin(),S.end());
    tmp="0000000000";
    for(string t : S){
        if(tmp!=t){
            tmp=t;
            count += (tmp_count)*(tmp_count-1)/2;
            tmp_count=1;
        }
        else tmp_count++;
    }
    count += (tmp_count)*(tmp_count-1)/2;
    cout << count << endl;
}

//後でコスパのいい奴が残ってしまうのが問題だった
//だったら後ろから決めていけばよい
//結局ソートの順だだと例外がでるような計算には優先度付きqでやるしかない

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int i,j,k;
    int a,b;
    int ans=0;
    pair<int,int> p[N];
    priority_queue<int> q;
    for(i=0;i<N;i++){
        cin >> a >> b;
        p[i]=make_pair(a,b);
    }
    sort(p,p+N);
    j=0;
    for(i=1;i<=M;i++){
        if(j<N){
            while(i>=p[j].first){
                q.push(p[j].second);
                j++;
                if(j>=N)break;
                }
            }
        if(!q.empty()){
        ans+=q.top();
        q.pop();
        }
    }
    cout << ans << endl;
}

