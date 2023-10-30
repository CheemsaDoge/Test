#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e6+1145;
const int INF=2147483647ll;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
int tr[MAXN][123],tis[MAXN];
int totr;
void insert(char* in)
{
	int u=0;
	for(int i=0;i<int(strlen(in));i++)
	{
		if(!tr[u][int(in[i])]) tr[u][int(in[i])]=++totr;
		u=tr[u][int(in[i])];
		tis[u]++;
	}
}
int search(char* in)
{
	int u=0;
	for(int i=0;i<int(strlen(in));i++)
	{
		if(!tr[u][int(in[i])]) return 0;
		u=tr[u][int(in[i])];
	}
	return tis[u];
}
void ini(int a)
{
	for(int i=1;i<=122;i++)
		if(tr[a][i]) ini(tr[a][i]),tr[a][i]=0;
}
char in[MAXN];
int main()
{
//	freopen("P8306_5.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T,n,q;
	read(T);
	while(T--)
	{
		read(n),read(q);
		for(int i=1;i<=n;i++) scanf("%s",in),insert(in);
		for(int i=1;i<=q;i++) scanf("%s",in),printf("%d\n",search(in));
		for(int i=0;i<=totr;i++) for(int j=0;j<=122;j++) tr[i][j]=0;
		for(int i=0;i<=totr;i++) tis[i]=0;
		totr=0;
	}
}
//z-122
