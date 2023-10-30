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
#define rl register long long int
#define ri register int
int main()
{
	rl n,k,ans=0;
//	freopen("2.4.in","r",stdin);
//	freopen("2.4.out","w",stdout);
	read(n);
	read(k);
	ans=n*k;
	for(ri x=1,gx;x<=n;x=gx+1)
	{
		gx=k/x?min(k/(k/x),n):n;
		ans-=(k/x)*(x+gx)/2*(gx-x+1);
	}
	printf("%lld",ans);
}
