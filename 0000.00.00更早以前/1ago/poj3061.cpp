#include<bits/stdc++.h>
using namespace std;
#define ri register int
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int INF=1e6+1145;
const int MAXN=1e6+1145;
int n,m;
int a[MAXN];
int l=1,r,val;
int s;
int ans=INF;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	read(s);
	for(int i=1;i<=n;i++)
	{
		if(val>=s)
		{
			ans=min(ans,i-l);
			val-=a[l];
			l++;
			i--;
			continue;
		}
		val+=a[i];
	}
	printf("%d",ans==INF?0:ans);
	return 0;
}

