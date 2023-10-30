#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e5+1145;
const int INF=2147483647ll;
#define db double
#define ll long long int 
#define ri register int
int a,b,p,n;ll ans;
int main()
{
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	read(a),read(b),read(p),read(n);
	b%=p;
	register ll jc=a;
	for(int i=1;i<=n;i++)
	{
		if((i%p)*(jc%p)%p==b) ans++;
		jc*=a;
	}
	printf("%lld",ans);
}
