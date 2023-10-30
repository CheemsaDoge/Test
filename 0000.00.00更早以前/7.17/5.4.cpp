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
int main() {
	ri T;
	rl n,x,y,d;
	freopen("5.4.in","r",stdin);
	freopen("5.4.out","w",stdout);
    read(T);
    while(T--)
    {
    	rl u=0,v=0;
    	read(n);
    	read(d);
    	read(x);
    	read(y);
    	rl uu=0;
    	v=0;
    	ll c=(y-x+n)%n;
    	ll cc=ex_gcd(d,n,u,v);
    	if(c%cc!=0)
    		printf("Impossible\n");
    	else
    		printf("%lld\n",((u * (c / cc)) % (n / cc) + (n / cc)) % (n / cc));    		
	}
}
