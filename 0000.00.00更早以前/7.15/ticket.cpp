#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define lowbit(x) x&(-x)
#define ri register int
#define mid ((l+r)>>1)
const int N=1e5+1145;
int a[N],c[N],n,m,i,j,k,ans[N],p[N],v[N];
inline int ask(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x))
        ans+=c[x];
    return ans;
}
inline int add(int x,int y)
{
    for(;x<=n;x+=lowbit(x))
        c[x]+=y;
}
int res[N];
int main()
{
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	while(~scanf("%d",&n))
	{
	    memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            read(p[i]);
            read(v[i]);
            p[i]++;
            add(i,1);
        }
		for(int i=n;i>=1;i--)
		{
			ri l=1,r=n;
            while(l<r)
                if (ask(mid)<p[i])	l=mid+1;
                else r=mid;
            ans[r]=v[i];
            add(r,-1);
		}
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
	}
}

