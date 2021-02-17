#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    if(A<=B*2)cout << 0 << endl;
    else cout << A - B*2 << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long int d[N];
    int i,j;
    long long int sum =0;
    for(i=0;i<N;i++)cin >> d[i];
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            sum += d[i]*d[j];
        }
    }
    cout << sum << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    int i;
    int count=0;
    char tmp = 'X';
    for(i=0;i<N;i++){
        if(S[i]!=tmp){
            count++;
            tmp=S[i];
        }
    }
    cout << count << endl;
}

//imosライクな方法でやったけど
//二分探索でやればふつーにlogで行けたという話
//単調増加にはにぶたんを！
#include <bits/stdc++.h>
using namespace std;

int main(){
    long int N;
    cin >> N;
    long int i,j,k;
    long int tmp;
    long int l[N];
    long int ans = 0;
    for(i=0;i<N;i++)cin >> l[i];
    sort(l,l+N);
    for(i=0;i<N-2;i++){
        tmp=0;
        for(j=i+1;j<N-1;j++){
            k=j+1+tmp;
            while(l[i]+l[j]>l[k]){
                tmp++;
                k++;
                if(k>N-1)break;
            }
            ans += tmp;
            if(tmp>0)tmp--;
            }
        }
        cout << ans << endl;
    }

#E 
//わーシャルフロイド法
//基本的な気持ちとしてはスタートとゴールと経由地点を決めて
//直接いくのと経由していくのでどっちがはやいか比較してはやければ入れていく
//今回は重さがつけられているからなお更これ
//https://qiita.com/okaryo/items/8e6cd73f8a676b7a5d75

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e17;
ll N, M, L, Q;
ll fuel[305][305];
ll dist[305][305];
ll s[105000], t[105000];
ll A[100000], B[100000], C[100000];

void input() {
    cin >> N >> M >> L;
    for(int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
    cin >> Q;
    for(int i = 1; i <= Q; i++) cin >> s[i] >> t[i];
}

void solve() {
    input();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            fuel[i][j] = INF;
            dist[i][j] = INF;
        }
        fuel[i][i] = 0;
        dist[i][i] = 0;
    }
    for(int i = 1; i <= M; i++) {
        chmin(fuel[A[i]][B[i]], C[i]);
        chmin(fuel[B[i]][A[i]], C[i]);
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                chmin(fuel[j][k], fuel[j][i] + fuel[i][k]);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            if(fuel[i][j] <= L) chmin(dist[i][j], 1LL);
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                chmin(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for(int i = 1; i <= Q; i++) {
        if(dist[t[i]][s[i]] < INF) cout << dist[t[i]][s[i]] - 1 << "\n";
        else cout << -1 << "\n";
    }
    return;
}

int main() {
    solve();
    return 0;
}


#F
//個数に着目して式変形をしていく方針自体は悪くなかった
//考察がしんどいけどさらにこの個数になるやつは何個かを調べて、
//累積和にもちこめば定数時間で計算可能だった
//腕力も時間があれば勝負していくべき
//下のは途中でちからつきた
#include <bits/stdc++.h>
using namespace std;

int c[300005];
int main(){
    int N;
    cin >> N;
    int a[N];
    int i;
    int tmp=0;
    int count=0;
    int MAX=1;
    int vr=0;
    for(i=0;i<N;i++)cin >> a[i];
    sort(a,a+N);
    for(i=0;i<N;i++){
        if(tmp!=a[i]){
            tmp=a[i];
            c[count]++;
            count=1;}
            else{
                count++;
                MAX=max(MAX,count);
            }
    }
    for(i=1;i<MAX+1;i++)var+=c[i];
    for(i=1;i<N+1;i++){

        if(i>MAX)cout <<  << endl;            
    }
}