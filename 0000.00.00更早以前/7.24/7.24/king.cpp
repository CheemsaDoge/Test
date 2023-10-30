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
#define ll long long
#define ri register int
#define rl register long long
const int MAXN=1e6+1145;
struct hand{
	int left,right;
}h[15];
bool operator<(hand a,hand b)
{
	return a.left>b.left;
}
int sum=999999999;
int main() {
	freopen("king.in","r",stdin);
	int n;
	read(n);
	if(n>12)return 0;
	freopen("king.out","w",stdout);
	for(int i=0;i<=n;i++)
	{
		read(h[i].left);
		read(h[i].right);
	}
	int val=h[0].left;
	int ls=0;
	for(int i=1;i<=n;i++)
	{
		ls=max(ls,val/h[i].right);
		val*=h[i].left;
	}
	sum=ls;
	while(next_permutation(h+1,h+n))
	{
		val=h[0].left;
		ls=0;
		for(int i=1;i<=n;i++)
		{
			ls=max(ls,val/h[i].right);
			if(ls>=sum)	goto nxt;
			val*=h[i].left;
		}
		sum=min(sum,ls);
		nxt:;
	}
	printf("%d",sum);
}
