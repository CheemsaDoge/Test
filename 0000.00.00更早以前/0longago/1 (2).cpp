#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
using namespace std;
typedef long long ll;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int INF=2E9+233;
const int MAXN=1e5+1145;
int n,m,wc[MAXN],c[MAXN]; 
int e,beg[MAXN],nex[MAXN],to[MAXN],w[MAXN],wt[MAXN];
int a[MAXN<<2],laz[MAXN<<2];
int son[MAXN],id[MAXN],fa[MAXN],cnt,dep[MAXN],siz[MAXN],top[MAXN],num[MAXN]; 
short res=0;
int maxn;
//map
inline void add(int x,int y){
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
//map
//tree¡ý¡ý
struct SGtree{
	struct Node{
		int l,r;
		int lch,rch;
		int val,tag;
		int c;
	}rt[MAXN*2+1];
	int totr;
	int build(int l,int r,int *a,int *c)
	{
		totr++;
		int x=totr;
		rt[x].l=l;
		rt[x].r=r;
		if(l==r){
			rt[x].val=a[l];
			rt[x].c=c[l];
			return x;
		}
		int mid=((l+r)>>1);
		rt[x].lch=build(l,mid,a,c);
		rt[x].rch=build(mid+1,r,a,c);
		return x;
	}
	int calc(int x)
	{
		return rt[x].val+(rt[x].r-rt[x].l+1)*rt[x].tag;
	}
	void push_up(int x)
	{
		rt[x].val=
			calc(rt[x].lch)+
			calc(rt[x].rch);
	}
	void push_down(int x)
	{
		rt[rt[x].lch].tag+=rt[x].tag;
		rt[rt[x].rch].tag+=rt[x].tag;
		rt[x].tag=0;
	}
	void change(int x,int l,int r,int v)
	{
		if(rt[x].r<l||rt[x].l>r)
			return ;
		if(l<=rt[x].l&&rt[x].r<=r)
		{
			rt[x].tag+=v;
			rt[x].val=calc(x);
			return ;
		}
		push_down(x);
		modify(rt[x].lch,l,r,v);
		modify(rt[x].rch,l,r,v);
		push_up(x);
	}
	int query(int x,int l,int r)
	{
		if(rt[x].r<l||rt[x].l>r)
			return 0;
		if(l<=rt[x].l&&rt[x].r<=r)
			return calc(x);
		push_down(x);
		push_up(x);
		return query(rt[x].lch,l,r)+query(rt[x].rch,l,r);
	}
	SGtree(){
		totr=0;
	}
}sgt;
inline void dfs1(int x,int f,int deep){ 
    dep[x]=deep; 
    fa[x]=f; 
    siz[x]=1; 
    int maxson=-1; 
    for(Rint i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==f)continue; 
        dfs1(y,x,deep+1);
        siz[x]+=siz[y]; 
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];
    }
}

inline void dfs2(int x,int topf){
    id[x]=++cnt;
    wt[cnt]=w[x];
    wc[cnt]=c[x];
    num[x]=cnt;
    top[x]=topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(Rint i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}
//algo¡ü¡ü
int main(){
	freopen("sea.in","r",stdin);
//	freopen("sea.out","w",stdout);
	char op[3];
    read(n);read(m);
	for (Rint i=1; i<=n; i++) 
	{
		read(c[i]);read(w[i]);
	}
    for(Rint i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
	sgt.build(1,n,wt,wc);
    while(m--){
        int k,x,y,z;
        for(int i=1;i<=2;i++)
        	op[i]=getchar();
        if(op[1]=='C'&&op[2]=='C'){
            read(x);read(y);
            c[num[x]]=y;
        }
        else if(op[1]=='C'&&op[2]=='W'){
            read(x);read(y);
            sgt.change(1,num[x],num[x],y-wt[x]);
        }
        else if(op[1]=='Q'&&op[2]=='S'){
            read(x);read(y);
			printf("%lld\n", sgt.sum(1, num[x], num[y],c[num[x]],c));
        }
        else{
            read(x);read(y);
			printf("%d\n", sgt.max_(1, num[x], num[y],c[num[x]],c));
        }
    }
}
