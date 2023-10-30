#include<bits/stdc++.h>
using namespace std;
int n,m,tot=0;
int to[500010],nxt[500010],w[500010],head[200010],dis1[200010],dis2[200010];
bool pd[200010];
inline void createside(int sta,int end,int val)
{
	to[++tot]=end;
	nxt[tot]=head[sta];
	head[sta]=tot;
	w[tot]=val;
}
queue<int>q;
int main()
{
	freopen("second10.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v,c;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&c);
		createside(u,v,c);
		createside(v,u,c);
	}
	for(int i=0;i<=n;++i)dis1[i]=dis2[i]=2000000000;
	q.push(1);
	dis1[1]=0;
	pd[1]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		pd[x]=false;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(dis2[y]<=dis1[x]+w[i])continue;
			if(dis1[x]+w[i]<dis1[y])
			{
				
				dis2[y]=min(dis1[y],dis2[x]+w[i]);
				dis1[y]=dis1[x]+w[i];
				if(!pd[y])
				{
					pd[y]=true;
					q.push(y);
				}
			}
			else if(dis2[y]>dis1[x]+w[i])
			{
				if(dis1[x]+w[i]>dis1[y])
				{
					dis2[y]=dis1[x]+w[i];
					if(!pd[y])
					{
						pd[y]=true;
						q.push(y);
					}
				}
				else if(dis2[x]+w[i]<dis2[y])
				{
					dis2[y]=dis2[x]+w[i];
					if(!pd[y])
					{
						pd[y]=true;
						q.push(y);
					}
				}
			}
		}
	}
	printf("%d\n",dis2[n]);
	return 0;
}
