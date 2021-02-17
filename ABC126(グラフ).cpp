//大文字→小文字は+32

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int N;
int K;
string S;
char t;
 cin >> N >> K;
 cin >> S;
 t = S[K-1] + 32;
 S[K-1] = t;
  cout << S << endl;
}

#include <bits/stdc++.h>
using namespace std;
 
int main(){
int i;
string S;
int A;
int B;
 cin >> S;
 A = (S[0]-'0')*10 + (S[1]-'0');
 B = (S[2]-'0')*10 + (S[3]-'0');
 if((A>12||A<1) && (B>=1 && B<=12))cout << "YYMM" << endl;
 else if((B>12||B<1) && (A>=1 && A<=12))cout << "MMYY" << endl;
 else if((B>=1 && B<=12) && (A>=1 && A<=12))cout << "AMBIGUOUS" << endl;
 else{cout << "NA" << endl;}
}

//小数の桁変更はsetprecision(11)

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int N;
 int K;
 int tmp;
 int val;
 double tmpval;
 cin >> N >> K;
 double pro = 0;
 int i;
 for(i=1;i<N+1;++i){
   if(i>=K)pro+=1.0;
   else{
    val=1;
   while(val*i<K){
       val*=2;
   }
   tmpval = 1.0/val;
   pro += tmpval;
   }}
 cout << setprecision(11) << pro*((double)(1.0/N)) << endl;
 }
 

//木構造にたいしてDFSをサクッと実装しよう。

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a[100005];
int ans[100005];
void dfs(int no,int father){ //fatherは祖先の頂点
	for (int i=0;i<a[no].size();i++){
		int u=a[no][i].first;
		int w=a[no][i].second%2; //距離が偶数かどうか
		if (u!=father){
			ans[u]=ans[no]^w;　//wの偶奇を利用してズレさせる
			dfs(u,no);　//noが今度は親になり、uが子になる
		}
	}
}
int main(){
    int n;
	cin>>n;
	for (int i=1;i<n;i++){
		int u,v,c;
		cin>>u>>v>>c;
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> a[100005];
int ans[100005];
void dfs(int no,int father){ 
	for (int i=0;i<a[no].size();i++){
		int u=a[no][i].first;
		int w=a[no][i].second%2; 
		if(u!=father){
         ans[u]=ans[no]^w;
         dfs(u,no);
       }
  }
}
int main(){
    int n;
	cin>>n;
	for (int i=1;i<n;i++){
		int u,v,c;
		cin>>u>>v>>c;
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}


//E
//どこに所属しているかでつけられるからUnionfindかなぁ
//同じ木構造の中にあれば1つ調べれば連鎖的にわかるよね
//どっちをどっちにあわせるのかにも注意、今回は常に左が小さいからそれ
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return;
        par[ry] = rx; 
    }

    int solve(int N) { 
        int ans = 0;
		map<int,int> c;
		for(int i=0;i<N;i++)int a=root(i);//一周しただけだと更新されていない部分があるから更新する
        for(int u:par){
			if(c[u]==0){
				c[u]++;
				ans++;
			}
		}
        return ans;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    UnionFind tree(n);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree.unite(x-1, y-1);
    }
    cout << tree.solve(n);
    return 0;
}

//大きい場合と0の場合は自明だけど、真ん中の時にできるのか？
//M=2の場合に1ができることを全パターンやってだせるかが勝負の分かれ目になりそう
//小さい値で手を動かす重要性
//結論としては、bKcKで、bが昇順、cが降順
//はさみこむ形を作ると同じものの和は0になるからっていうところ
//0から2^Mの和は0になるのも大事な性質だね

