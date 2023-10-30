#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
const int N=20;
const int MAXN=3e4+1145;
struct Edge{
	int u,to,val,nxt;
}edge[N*4];
int totr=0;
int head[N];
void add_edge(int u,int v,double val)
{
	edge[++totr].to=v;
	edge[totr].nxt=head[u];
	head[u]=edge[totr].nxt;
	edge[totr].u=u;
	edge[totr].val=val;
}
int main()
{
//	freopen("sidewalk.in","r",stdin);
//	freopen("sidewalk.out","w",stdout);
	
}
