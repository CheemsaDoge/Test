#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

const int maxn=4e5+3456;
int n,m;
int e,beg[maxn],nex[maxn],to[maxn],w[maxn],wt[maxn];
int a[maxn<<2];
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn]; 
int res=0;

inline void add(int x,int y){
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
/////////////////////////////////////////////////////
inline void build(int rt,int l,int r)
{
    if(l==r)
	{
        a[rt]=wt[l];
        return;
    }
    build(lson);
    build(rson);
    a[rt]=(a[rt<<1]+a[rt<<1|1]);
}

inline void query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R){res+=a[rt];return;}
    else
	{
        if(L<=mid)query(lson,L,R);
        if(R>mid)query(rson,L,R);
    }
}
/////////////////////////////////////////////////////////
inline void dfs1(int x,int f,int deep)
{
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    int maxson=-1;
    for(Rint i=beg[x];i;i=nex[i])
	{
        int y=to[i];
        if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];
    }
}

inline void dfs2(int x,int topf)
{ 
    id[x]=++cnt;
    wt[cnt]=w[x];
    top[x]=topf; 
    if(!son[x])return;
    dfs2(son[x],topf);
    for(Rint i=beg[x];i;i=nex[i])
	{
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}

inline int qRange(int x,int y){
    int ans=0;
    while(top[x]!=top[y])
	{ 
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res=0;
        query(1,1,n,id[top[x]],id[x]);
        ans+=res;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    res=0;
    query(1,1,n,id[x],id[y]);
    ans+=res;
    return ans;
}
int main()
{
	freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
    read(n);read(m);
    int a,b;
    for(Rint i=1;i<=n;i++)read(w[i]);
    for(Rint i=1;i<n;i++)
	{
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    while(m--)
	{
        read(a);
        read(b);
        printf("%d\n",qRange(a,b));
    }
}
