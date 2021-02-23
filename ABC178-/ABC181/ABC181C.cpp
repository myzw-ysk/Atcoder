//sqrtがリスクファクターであることは自明、極力回避する解法とは
//小数を極力避けるのは基本！！！！

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double x[n],y[n];
    double a,b,c;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                a=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                b=sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]));
                c=sqrt((x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]));
                if(a+b==c || b+c==a || c+a==b){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}

//sqrtを使わないためにはこうなるよね

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double x[n],y[n];
    double x1,x2,y1,y2;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                x1 = x[j] - x[i]; x2 = x[k] - x[i];
                y1 = y[j] - y[i]; y2 = y[k] - y[i];
                if(x1 == x2 && x1 == 0){
                    cout << "Yes";
                    return 0;                    
                }
                else if(x1*x2 != 0 && y1/x1 == y2/x2){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}