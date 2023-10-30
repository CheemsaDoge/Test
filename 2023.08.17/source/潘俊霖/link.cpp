/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define MOD 10007
/*---------------------------------pre------------------------------------*/
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM*4];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int n,s;
int W[MAXN];
int sum,maxn;
int sum2;
int big1,big2;
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	int m,u,v;
	read(n);
	for(int i=1;i<n;i++)
	{
		read(u);read(v);
		add_edge(u,v),add_edge(v,u);
	}
	for(int i=1;i<=n;i++) read(W[i]);
	for(int i=1;i<=n;i++)
	{
		sum2=0;big1=0;big2=0;
		for(int j=head[i];j;j=edge[j].nxt)
		{
			#define v edge[j].v
			#define u i
			if(W[v]>=big1){
				big2=big1;
				big1=W[v];
				maxn=max(maxn,big1*big2);
			}
			else if(W[v]>big2)
			{
				big2=W[v];
				maxn=max(maxn,big2*big1);
			}
			sum+=sum2*W[v];
			sum%=MOD;
			sum2+=W[v];sum2%=MOD;
			#undef u
			#undef v
		}
	}
	write(maxn);pk;write(sum*2%MOD);
	
}

//1 /lt n /le 2 /times 10^5
