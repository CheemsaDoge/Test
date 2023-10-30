#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define rl register long long 
#define ll long long
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
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
ll gcd(ll a,ll b)
{
	if(b==0)	return a;
	if(a<b)	return gcd(b,a);
	return gcd(b,a%b);
}
ll d;
bool liEu(ll a, ll b, ll c, ll& x, ll& y) {
  d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  ll k = c / d;
  x *= k;
  y *= k;
  return 1;
}
int main()
{
	freopen("5.1.in","r",stdin);
	freopen("5.1.out","w",stdout);
	rl x,y,m,n,l;
	rl u,v;
	read(x);
	read(y);
	read(m);
	read(n);
	read(l);
	rl a=m-n,b=l,c=y-x;
	if(a<0)a=-a,c=-c;
	if(!liEu(a,b,c,u,v))
	{
		printf("Impossible");
		return 0;
	}
	printf("%d",(u%(b/d)+b/d)%(b/d));
}
