#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e8+9999999;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long int
#define rl register long long int
#define ri register int
void exgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int main()
{
//	freopen("2.2.in","r",stdin);
//	freopen("2.2.out","w",stdout);
	rl x=0,y=0,a,b;
	read(a);
	read(b);
	exgcd(a,b,x,y);
	while(x<=0)
		x+=b;
	printf("%lld",x);	
}
