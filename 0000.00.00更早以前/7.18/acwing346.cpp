#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=6000+1145;
struct Edge{
	int u,v,val;
}edge[10000];
int fa[MAXN],s[MAXN];
int find(int x)
{
   return fa[x]==x?x:find(fa[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.val<b.val;
}
long long cnt,ans;
inline void initialize(int n)
{
	cnt=0,ans=0;
    for(int i=1;i<=n;i++) fa[i]=i,s[i]=1;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int t,n;
	read(t);
	while(t--)
	{
	    read(n);
	    initialize(n);
	    for(int i=0;i<n-1;i++)
	    {
	        read(edge[i].u);
	        read(edge[i].v);
	        read(edge[i].val);
	    }
	    sort(edge,edge+n-1,cmp);
	    for(int i=0;i<n-1;i++)
	    {
	        int eu=find(edge[i].u),ev=find(edge[i].v);
	        if(eu!=ev)
	        {
	            ans+=(s[eu]*s[ev]-1)*(edge[i].val+1);
	            s[eu]+=s[ev];
	            fa[ev]=eu;
	        }
	    }
	    printf("%lld\n",ans);
	}
}
