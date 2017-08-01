#include <bits/stdc++.h>
using namespace std;
#define maxn 10009

int main(){
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  int ans = 0;
  for (int i = 0; i <= a; i++){
    for (int j = 0; j <= b; j++){
      if ((n - i * 5 - j* 8) % 10 == 0 && n - i * 5 - j * 8 <= c * 10){
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
