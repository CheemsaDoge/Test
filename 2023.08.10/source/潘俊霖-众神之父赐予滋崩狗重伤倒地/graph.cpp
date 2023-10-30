/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MOD=998244353ll;const int INF=2147483647ll;//2^31-1
const int MAXM=3e5+1145;const int MAXN=3e5+1145;
#define db double
#define ll long long
struct EDGE{
	int u,v,nxt;
}edge[MAXM*4];
int totr,head[MAXN];
void add_edge(int u,int v)
{
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
long long fast_pow(int a,int x,int p) //fast_pow
{
	if(a%p==0) return 0;
	long long no=a,ans=1;
	while(x){
		if(x&1) ans=1ll*ans*no%p;
		x>>=1;no=1ll*no*no%p;
	}
	return ans;
}
int n,m;
int rs[MAXN];
int sum;
int ans;
int gulang;
void RS(int u)
{
	if(head[u]==0) {
		gulang++;
		return ;
	}
	if(rs[u]==0) rs[u]=1;
	if(rs[u]==1) sum++;
	int se=rs[u]==1?-1:1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(rs[edge[i].v]==0) rs[edge[i].v]=se,RS(edge[i].v);
		else if(rs[edge[i].v]==rs[u]) {ans=-1;return ;}
	}
	return ;
}
int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int T;
	read(T);
	int a,b;
	while(T--)
	{
		memset(rs,0,sizeof(rs));
		memset(head,0,sizeof(head));
		totr=0;ans=0;gulang=0;
		read(n);read(m);
		for(int i=1;i<=m;i++)
		{
			read(a);read(b);
			add_edge(a,b);
			add_edge(b,a);
		}
		for(int i=1;i<=n;i++)
		{
			if(!rs[i]) RS(i);
			if(ans==-1) 
			{
				printf("%d\n",0);
				break;
			}
		}
		if(ans!=-1)
		{
			ans=0;
			ans+=1ll*fast_pow(2,sum,MOD);
			ans=(1ll*ans+1ll*fast_pow(2,n-gulang-sum,MOD))%MOD;
			printf("%d\n",1ll*ans*fast_pow(3,gulang,MOD)%MOD);
		}
		for(int i=1;i<=totr;i++) edge[i].nxt=0,edge[i].u=0,edge[i].v=0;
	}
}
