#include<bits/stdc++.h>
using namespace std;
#define ri register int

int qq[1001][1001],n,m,a,b,c;
struct node
{
	long long cost;
	int x,y;
	bool operator <( const node &tt )const
	{
		return tt.cost < cost;
	}
} l[3][1001][1001];
int dx[]= {0,1,0,-1,0},dy[]= {0,0,1,0,-1};

template < typename T >inline void read(T &x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=((x<<3)+(x<<1)+(c^48));
	x*=f;
}
inline void Dij1(int x,int y)
{
	l[0][x][y].cost=qq[x][y];
	bool vis[1001][1001];
	memset(vis,0,sizeof(vis));
	priority_queue< node > q;
	q.push((node)
	{
		qq[x][y],x,y
	});
	while(!q.empty())
	{
		node temp1=q.top();
		q.pop();
		int xx=temp1.x,yy=temp1.y;
		if(vis[xx][yy]) continue;
		vis[xx][yy]=1;
		for(ri i=1; i<=4; ++i)
		{
			if(xx+dx[i]>=1 && xx+dx[i]<=n && yy+dy[i]>=1 && yy+dy[i]<=m)
			{
				int tx=xx+dx[i],ty=yy+dy[i];
				if(l[0][tx][ty].cost>l[0][xx][yy].cost+qq[tx][ty])
				{
					l[0][tx][ty].cost=l[0][xx][yy].cost+qq[tx][ty];
					if(!vis[tx][ty])
					{
						temp1.cost=l[0][tx][ty].cost;
						temp1.x=tx;
						temp1.y=ty;
						q.push(temp1);
					}
				}
			}
		}
	}
}
inline void Dij2(int x,int y)
{
	l[1][x][y].cost=qq[x][y];
	bool vis[1001][1001];
	memset(vis,0,sizeof(vis));
	priority_queue< node > q;
	q.push((node)
	{
		qq[x][y],x,y
	});
	while(!q.empty())
	{
		node temp1=q.top();
		q.pop();
		int xx=temp1.x,yy=temp1.y,zz=temp1.cost;
		if(vis[xx][yy]) continue;
		vis[xx][yy]=1;
		for(ri i=1; i<=4; ++i)
		{
			if(xx+dx[i]>=1 && xx+dx[i]<=n && yy+dy[i]>=1 && yy+dy[i]<=m)
			{
				int tx=xx+dx[i],ty=yy+dy[i];
				if(l[1][tx][ty].cost>l[1][xx][yy].cost+qq[tx][ty])
				{
					l[1][tx][ty].cost=l[1][xx][yy].cost+qq[tx][ty];
					if(!vis[tx][ty])
					{
						temp1.cost=l[1][tx][ty].cost;
						temp1.x=tx;
						temp1.y=ty;
						q.push(temp1);
					}
				}
			}
		}
	}
}
inline void Dij3(int x,int y)
{
	l[2][x][y].cost=qq[x][y];
	bool vis[1001][1001];
	memset(vis,0,sizeof(vis));
	priority_queue< node > q;
	q.push((node)
	{
		qq[x][y],x,y
	});
	while(!q.empty())
	{
		node temp1=q.top();
		q.pop();
		int xx=temp1.x,yy=temp1.y,zz=temp1.cost;
		if(vis[xx][yy]) continue;
		vis[xx][yy]=1;
		for(ri i=1; i<=4; ++i)
		{
			if(xx+dx[i]>=1 && xx+dx[i]<=n && yy+dy[i]>=1 && yy+dy[i]<=m)
			{
				int tx=xx+dx[i],ty=yy+dy[i];
				if(l[2][tx][ty].cost>l[2][xx][yy].cost+qq[tx][ty])
				{
					l[2][tx][ty].cost=l[2][xx][yy].cost+qq[tx][ty];
					if(!vis[tx][ty])
					{
						temp1.cost=l[2][tx][ty].cost;
						temp1.x=tx;
						temp1.y=ty;
						q.push(temp1);
					}
				}
			}
		}
	}
}

int main()
{
	
	freopen("impact.in","r",stdin);
	freopen("impact.out","w",stdout);
	read(n);read(m);read(a);read(b);read(c);
	for(ri i=1; i<=n; ++i)
	{
		for(ri j=1; j<=m; ++j)
		{
			read(qq[i][j]);
		}
	}
	for(ri i=0; i<=2; ++i)
	{
		for(ri j=1; j<=n; ++j)
		{
			for(ri k=1; k<=m; ++k)
			{
				l[i][j][k].cost=100000000000000;
			}
		}
	}
	Dij1(1,a);
	Dij2(n,b);
	Dij3(n,c);
	long long minn=100000000000000;
	for(ri i=1; i<=n; ++i)
	{
		for(ri j=1; j<=m; ++j)
		{
			minn=min(l[0][i][j].cost+l[1][i][j].cost+l[2][i][j].cost-(qq[i][j]<<1),minn);
		}
	}
	printf("%lld",minn);
}
/*
2 2 1 1 2
1 1
1 1
*/
/*
5 5 1 5 4
1 100 1 1 1
1 100 1 100 1
1 1 1 100 1
100 1 100 100 1
1 1 1 1 1
*/
