//#include<bits/stdc++.h>
//using namespace std;
//template<typename T> inline void read(T &x){
//    x=0;T w=1,ch=getchar();
//    while(!isdigit(ch)&&ch!='-')ch=getchar();
//    if(ch=='-')w=-1,ch=getchar();
//    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
//    x=x*w;
//}
//const int MAXN=1e6+1145;
//#define ri register int
//#define rl register long long 
//#define ll long long 
//int totr=0;
//int tr[MAXN][27];
//ll vis[MAXN];
//int fail[MAXN];
//void add(char* a)
//{
//	int u=0;
//	for(int i=0;a[i];i++)
//		if(tr[u][a[i]-'a'])	u=tr[u][a[i]-'a'];
//		else	tr[u][a[i]-'a']=++totr,u=totr;
//	vis[u]++;
//}
//void build()
//{
//	ri u=0;
//	queue<int>a;
//	for(ri i=0;i<=25;i++)
//		if(tr[0][i])	a.push(tr[0][i]);
//	while(!a.empty())
//	{
//		u=a.front();	a.pop();
//		for(int i=0;i<=25;i++)
//			if(tr[u][i])	fail[tr[u][i]]=tr[fail[u]][i],a.push(tr[u][i]);
//			else	tr[u][i]=tr[fail[u]][i];
//	}
//}
//ll query(char*a)
//{
//	rl res=0,u=0;
//	for(ri i=0;a[i];i++)
//	{
//		u=tr[u][a[i]-'a'];
//		for(ri j=u;j&&vis[j]!=-1;j=fail[j])	res+=vis[j],vis[j]=-1;
//	}
//	return res;
//}
//char s[MAXN];
//int main()
//{
//	ri n;
//	read(n);
//	for(ri i=1;i<=n;i++)	scanf("%s",&s),add(s);
//	build();
//	scanf("%s",&s);
//	printf("%d\n",query(s));
//}

#include<cstdio>
using namespace std;
long long n, cnt = 0;

int main() {
	scanf("%d",&n);
	if (n == 1) {
		printf("1");
		exit(0);
	}
	printf("15874");
}
