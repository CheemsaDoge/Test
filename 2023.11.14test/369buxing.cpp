/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-10-26 07:57:50
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-14 21:44:30
 * @FilePath: \TEST\2023.11.14test\369buxing.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
namespace CheemsaDoge {
	typedef long long LL;
	template <typename type1,typename type2> inline type1 min(const type1 _a,const type2 _b) {return _a>_b?_b:_a;}
	template <typename type1,typename type2> inline type1 max(const type1 _a,const type2 _b) {return _a>_b?_a:_b;}
	template <typename types,typename ... args> inline types min(const types _a,const args ... more) {return min(_a,more...);}
	template <typename types,typename ... args> inline types max(const types _a,const args ... more) {return max(_a,more...);}
	template <typename type1,typename type2> inline void __getmin(type1 &_a,const type2 _b) {_a=min(_a,_b);}
	template <typename type1,typename type2> inline void __getmax(type1 &_a,const type2 _b) {_a=max(_a,_b);}
	template <typename types,typename ... args> inline void __getmin(types &_a,const args ... _b) {_a=getmin(_a,_b...);}
	template <typename types,typename ... args> inline void __getmax(types &_a,const args ... _b) {_a=getmax(_a,_b...);}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	inline int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}return x*f;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
/** @brief 计算某数的多次方对mod取模后的答案 
  * @description: 计算某数的多次方对mod取模后的答案
  * @param {type1} _a 底数(返回值类型以此为主)
  * @param {type2} _n 次数
  * @param {type3} __mod 模数(不填则默认为2,305,843,009,213,693,952(2^61))
  * @return {*} _a的_n次方对__mod取模(类型以底数类型为准)
  */
 	template <typename type1,typename type2> type1 pow(type1 _a,type2 _n,LL __mod=2305843009213693952ll) {type1 _ans=1;_a%=__mod;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;using std::make_pair;
	#define sqrt __builtin_sqrt
}
namespace OI_File{
	inline void _File() {
		freopen("369buxing.in","r",stdin);
		freopen("369buxing.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
// typedef __int128_t int128;
const int INF=0x41414141;const int MAXN=6e5;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
int fa[MAXN],siz[MAXN],top[MAXN],dfn[MAXN],idx[MAXN],son[MAXN],End[MAXN],dfs_num;
int f[MAXN][3],a[MAXN],n;
struct Matrix {
    int g[3][3];
    Matrix() {memset(g,0,sizeof(g));}
    Matrix operator *(Matrix a) const {
        Matrix c;
        for(int i=0;i<=1;i++) 
            for(int j=0;j<=1;j++) 
                for(int b=0;b<=1;b++) 
                    c.g[i][j]=max(c.g[i][j],g[i][b]+a.g[b][j]);
        return c;
    }
}g[MAXN],val[MAXN];
vector<int>edge[MAXN];
inline void add_edge(int u,int v) {
    return edge[u].emplace_back(v),void();
}
void dfs1(int u,int fath=0) {
    siz[u]=1;fa[u]=fath;
    int Max=0;
    f[u][1]=a[u];
    for(int v:edge[u]) {
        if(v==fath) continue;
        dfs1(v,u);
        f[u][1]+=f[v][0];
        f[u][0]+=max(f[v][1],f[v][0]);
        siz[u]+=siz[v];
        if(siz[v]>Max) {
            Max=siz[v];
            son[u]=v;
        }
    } return void();
}
void dfs2(int u,int topp) {
    dfn[u]=++dfs_num;
    idx[dfs_num]=u;
    top[u]=topp;
    End[topp]=dfs_num;
    g[u].g[1][0]=a[u];
    g[u].g[1][1]=-INF;
    if(!son[u]) return;
    dfs2(son[u],topp);
    for(int v:edge[u]) {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
        g[u].g[0][0]+=max(f[v][1],f[v][0]);
        g[u].g[1][0]+=f[v][0];
    }
    g[u].g[0][1]=g[u].g[0][0];
}
inline void push_up(int root) {
    val[root]=val[root<<1]*val[root<<1|1];
}
void build(int root,int l,int r) {
    if(l==r) return val[root]=g[idx[l]],void();
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    push_up(root);
}
void modify(int root,int l,int r,int pos) {
    if(l==r) return val[root]=g[idx[l]],void();
    int mid=(l+r)>>1;
    if(mid<pos) modify(root<<1|1,mid+1,r,pos);
    else modify(root<<1,l,mid,pos);
    push_up(root);
}
Matrix query(int root,int l,int r,int ql,int qr) {
    if(l>=ql&&r<=qr) return val[root];
    // write(root,l,r,ql,qr,'\n');
    int mid=(l+r)>>1;
    if(qr<=mid) return query(root<<1,l,mid,ql,qr);
    if(mid<ql) return query(root<<1|1,mid+1,r,ql,qr);
    return query(root<<1,l,mid,ql,qr)*query(root<<1|1,mid+1,r,ql,qr);
}
inline void update(int x,int w) {
    g[x].g[1][0]+=w-a[x];
    a[x]=w;
    while(x) {
        Matrix last=query(1,1,n,dfn[top[x]],End[top[x]]);
        modify(1,1,n,dfn[x]);
        Matrix now=query(1,1,n,dfn[top[x]],End[top[x]]);
        x=fa[top[x]];
        g[x].g[0][0]+=max(now.g[0][0],now.g[1][0])-max(last.g[0][0],last.g[1][0]);
        g[x].g[0][1]=g[x].g[0][0];
        g[x].g[1][0]+=now.g[0][0]-last.g[0][0];
    }
}
signed main() {
	// _File();
    int m;
    read(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n-1;i++) {
        int u,v;read(u,v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    for (int i=1;i<=m;i++) {
        int x,w;
        read(x,w);
        update(x,w);
        Matrix ans=query(1,1,n,1,End[1]);
        write(max(ans.g[0][0],ans.g[1][0]),'\n');
    }
	return 0;
}