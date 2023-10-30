/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=200000+1145;const int MAXN=2000;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
inline void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m,T;
inline void Data_in()
{
	int u,v,w;
	read(n);read(m);read(T);
	for(int i=1;i<=m;i++)
	{
		read(u),read(v),read(w);
		add_edge(u,v,w);
	}
}
struct QQ{
	int u,dis1;
};
bool operator<(QQ a,QQ b)
{
	return a.dis1>b.dis1;
}
priority_queue<QQ>q;
inline void SpfawasdeadSoIuseDj_QWQ(int u,int *dis1)
{
	fill(dis1+1,dis1+n+2,INF);
	dis1[u]=0;
	q.push((QQ){u,0});
	while(!q.empty())
	{
		QQ now=q.top();
		q.pop();
		if(now.dis1>dis1[now.u]) continue;
		u=now.u;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(dis1[v]>dis1[u]+edge[i].val)
			{
				dis1[v]=dis1[u]+edge[i].val;
				q.push((QQ){v,dis1[v]});
			}
		}
	}
}
inline int max(const int a,const int b)
{
	return a>b?a:b;
}
int dis1[MAXN];
int dis2[MAXN];
inline void Data_in2()
{
	int t=totr;
	totr=0;
	memset(head,0,10+m);
	for(int i=1;i<=t;i++) add_edge(edge[i].v,edge[i].u,edge[i].val);
}
int main(){
	Data_in();
	SpfawasdeadSoIuseDj_QWQ(T,dis1);
	Data_in2();
	SpfawasdeadSoIuseDj_QWQ(T,dis2);
	int maxn=0;
	for(int i=1;i<=n;i++) maxn=max(maxn,dis1[i]+dis2[i]);
	write(maxn);
	return 0;
}

