#include<bits/stdc++.h>
using namespace std;
#define pc putchar
#define R read()
#define fo(i,a,b) for(register int i=a;i<=b;i++)
#define rep(i,a,b) for(register int i=a;i>=b;i--)
#define m1(a,b) memset(a,b,sizeof a)
int read()
{
    int x=0;
    char ch=getchar();
    bool f=0;
    while(!isdigit(ch)){if(ch=='-') f=1;ch=getchar();}
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(f) x=-x;
    return x;                                       
}
template<typename T> inline void write(T x)
{
    if(x<0)
    {
        pc('-');
        x=-x;
    }
    if(x>9) write(x/10);
    pc(x%10+'0');
}
const int N=5e5+10,M=4e6+10;
int n,m;
int u[M],v[M];
int dfn[N],low[N],cnt;
int h[N],e[M],ne[M],idx;
int stk[N],top;
vector<vector<int> > ans;
void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void tarjan(int u,int last)
{
	dfn[u]=++cnt,low[u]=dfn[u];
	stk[++top]=u;
	for(int i=h[u];~i;i=ne[i])
	{
		if(i==(last^1)) continue;
		int j=e[i];
		if(!dfn[j])
		{
			tarjan(j,i);
				low[u]=min(low[u],low[j]);	
		}
		else low[u]=min(low[u],dfn[j]);
	}
	if(dfn[u]==low[u])
	{
		vector<int> v;
		v.push_back(u);
		while(stk[top]!=u) v.push_back(stk[top--]);
		top--;
		ans.push_back(v);
	}
}
signed main(){
	memset(h,-1,sizeof h);
	n=R,m=R;
	fo(i,1,m) 
	{
		int x=R,y=R;
		add(x,y),add(y,x);
	}
	fo(i,1,n) if(!dfn[i]) tarjan(i,-1);
	write(ans.size()),puts("");
	for(auto i:ans)
	{
		write(i.size()),pc(' ');
		for(auto j:i) write(j),pc(' ');
		puts("");
	}
}
