#include <bits/stdc++.h>
using namespace std;
const int MAXN =1e6+1145;
#define ri register int
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int tr[MAXN][27];
int totr,fail[MAXN];
int tot,mapy[200];
int sum[200];
char s[MAXN];
struct STRING{
	int q;
	int vis;
	char a[80];
}st[200];
int maxn=-1;
void Initialize(int n)
{
	memset(tr,0,n*2000);
	memset(fail,0,n*2000);
	memset(mapy,0,200);
	memset(sum,0,200);
	memset(st,0,200*82);
	maxn=0;
	tot=0;
	totr=0;
}
void add(char *a)
{
	int u=0;
	for(int i=0;i<strlen(a);i++)
		if(tr[u][a[i]])	u=tr[u][a[i]-'a'];
		else u=tr[u][a[i]-'a']=++totr;
	st[++tot].vis++;
	strcpy(st[tot].a,a);
	mapy[u]=tot;
}
void build()
{
	int u=0;queue<int>a;
	for(int i=0;i<=25;i++)
		if(tr[u][i])	a.push(tr[u][i]);
	while(!a.empty())
	{
		u=a.front();a.pop();
		for(int i=0;i<=25;i++)
			if(tr[u][i])	fail[tr[u][i]]=tr[fail[u]][i],a.push(tr[u][i]);
			else	tr[u][i]=tr[fail[u]][i];
	}
}
void query(char*a)
{
	int u=0;
	for(int i=0;i<strlen(a);i++)
	{
		u=tr[u][a[i]-'a'];
		for(int j=u;j&&st[mapy[j]].vis!=-1;j=fail[j])
			if(st[mapy[j]].vis)
			{
				st[mapy[j]].q+=st[mapy[j]].vis;
				maxn=max(maxn,st[mapy[j]].q);
			}
	}
}

int main()
{
	ri N;
//	freopen("x.out","w",stdout);
	while(1)
	{
		read(N);if(!N)	return 0;
		for(int i=0;i<N;i++)
		{
			scanf("%s",&s);
			add(s);
		}
		scanf("%s",&s);
		build();
		query(s);
		printf("%d\n",maxn);
		for(int i=1;i<=N;i++)
			if(maxn==st[i].q)
				printf("%s\n",st[i].a);
		cout<<st[5].q;
		Initialize(N);
	}
	
}
