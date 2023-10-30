#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rl register long long
#define ri register int
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const ll N = 100;
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ex_gcd(b, a % b, x, y);
  ll temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
ll dd;
bool liEu(ll a, ll b, ll c, ll& x, ll& y) {
  dd = ex_gcd(a, b, x, y);
  if (c % dd != 0) return 0;
  ll k = c / dd;
  x *= k;
  y *= k;
  return 1;
}
int main() {
	printf("%d %d %d",1%-2,-1%1,2%-2);
}
