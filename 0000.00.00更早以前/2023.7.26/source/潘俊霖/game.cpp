#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
const int MAXN=500+145;
#define ll long long
#define ri register int
#define rl register long long
int ans=0;
int val[MAXN][MAXN];
int is_head[MAXN];
priority_queue<long long int>m;
int main() {
	int n;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			read(val[i][j]);
			val[j][i]=val[i][j];
		}
	for(int i=1;i<=n;i++)
	{
		priority_queue<long long int>z;
		for(int j=1;j<=n;j++)
			z.push(val[i][j]);
		z.pop();
		m.push(z.top());
	}
	printf("1\n%lld",m.top());
}




/*
喜欢骗分
球球了
让我对几个点 
*/ 
