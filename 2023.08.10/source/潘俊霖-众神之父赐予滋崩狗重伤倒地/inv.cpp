/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=3e6+1145;const int INF=2147483647ll;//2^31-1
#define db double
int n,p;
int inv[MAXN];
int main() {
	freopen("inv.in","r",stdin);
	freopen("inv.out","w",stdout);	
	read(n);read(p);
	inv[1]=1;
	printf("%d\n",1);
	for(int i=2;i<=n;i++)
	{
		inv[i]=1ll*(p-(p/i))*inv[p%i]%p;
		printf("%d\n",inv[i]);
	}
	return 0;
}
