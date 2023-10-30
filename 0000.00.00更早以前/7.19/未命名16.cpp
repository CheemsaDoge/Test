#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int N=1e6+1145;
const int MAXN=3e4+1145;
struct Edge{
	int u,to;
	double val;
}edge[N];
int totr=0;
int n,k;
struct Point{
	int x,y;
}point[5000];
double get_Dis(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline void add_edge(int u,int v,double val)
{
	edge[++totr].to=v;
	edge[totr].u=u;
	edge[totr].val=val;
}
int fa[MAXN];
inline void initialize(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x)
{
   return fa[x]==x?x:find(fa[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.val<b.val;
}
priority_queue<double>a;
int cnt,ans;
int main()
{
	int k,n,x,y,c;
    read(n);
	read(k);
    initialize(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        	add_edge(i,j,get_Dis(point[i],point[j]));
	ans=0;
	int ev,eu;
	sort(edge+1,edge+1+totr,cmp);
	for(int i=1;i<=totr;i++)			//O(m)
	{
			eu=find(edge[i].u), ev=find(edge[i].to);
			if(eu==ev)
				continue;
			a.push(-edge[i].val);
			ans+=edge[i].val;
			fa[ev]=eu;
			if(++cnt==n-1)
				break;
	}
	k-=1;
	while(k--)
		a.pop();
	printf("%.4lf\n",a.top());
}
