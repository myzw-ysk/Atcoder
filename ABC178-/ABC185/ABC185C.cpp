#include <bits/stdc++.h>
using namespace std;

int64_t binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  int64_t ret = 1;
  for(int64_t i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}

int main(){
    long long int l;
    cin >> l;
    cout << binomial(l-1,11);
}