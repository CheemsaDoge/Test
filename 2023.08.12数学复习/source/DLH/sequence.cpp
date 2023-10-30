/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=1e5+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int n,maxn,zan,a[MAXN],sum;
ll ans;
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);	
	read(n);
	for (int i=1; i<=n; i++) read(a[i]),sum+=a[i];
	for (int i=1; i<=n; i++)
		if (zan+a[i]<0) zan=0;
		else {zan+=a[i];maxn=max(maxn,zan);}
	maxn=max(maxn,zan);
	ans=maxn*2-sum;
	printf("%lld\n",ans);
	return 0;
}
