#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int y=a;
    int x=c;
    int z=b;
    cout << x << " " << y << " " << z << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int a[N];
    int i;
    int sum=0;
    for(i=0;i<N;i++){
        cin >> a[i];
        sum += a[i];
    }
    double vot = (double)sum/(4.0*M);
    int count=0;
    for(i=0;i<N;i++)if(a[i]>=vot)count++;
    if(count>=M)cout << "Yes" << endl;
    else{cout << "No" << endl;}
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int N,K;
    cin >> N >> K;
        long long int a= N%K;
        long long int b= K-a;
        cout << min(a,b) << endl;
}

//K番目をだせ！っていわれている以上dpは悪手
//末尾の数字で順番に次のけたのものがだせる仕組みを利用するにはqueue!
//そのものを利用して次のものがだせる(けど数は膨大)ってときにqueueは強い

#include<bits/stdc++.h>
using namespace std;

int main(){
    int K;
    long long int i;
    int count;
    long long int mod;
    queue<long long int> q;
    cin >>K;
    for(i=1;i<10;i++)q.push(i);
    for(count=0;count<K-1;count++){
        i=q.front();
        mod=i%10;
        q.pop();
        if(mod!=0)q.push(i*10+mod-1);
        q.push(i*10+mod);
        if(mod!=9)q.push(i*10+mod+1);
    }
    i=q.front();
    cout << i << endl;
}

//F
//約数探しは怖くない！ルートの範囲で調べるだけ！

#include<bits/stdc++.h>
using namespace std;

long long int num_yakusu(long long int N){
    long long int num=0;
    for(long long int i=1;i*i<=N;i++){
        if(i*i==N)num++;
        else if(N%i==0)num+=2;
    }
    return num;
}

long long int num_yakusu_neo(long long int N){
    long long int num=0;
    for(long long int i=2;i*i<=N;i++){
        if(i*i==N)num++;
        else if(N%i==0){
            long long int j = N/i;
            long long int k=N;
            while(k>=i){
                if(k%i==0)k /= i;
                else{k %= i;}
            }
            if(k==1)num++;
            k=N;
            while(k>=j){
                if(k%j==0)k /= j;
                else{k %= j;}
            }
            if(k==1)num++;
    }}
    return num;
}

int main(){
	long long int n;
	cin >> n;
	cout << num_yakusu_neo(n)+num_yakusu(n-1) << endl;
	return 0;
}