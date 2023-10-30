
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ri register int
#define ll long long int
bool cmp1(int x,int y)
{
	return x<y;
}
bool cmp2(int x,int y)
{
	return x>y;
}
inline long long mi(int x,int n)
{
	register long long int sum=1;
	ri p=x;
	while(n)
	{
		if(n&1)
			sum*=p;
		n>>=1;
		p*=p;
	}
	return sum;
}
ll cifang[155][40];
int n,m;
ll k[8];
ll p[8];
vector<int>A;
vector<int>B;
inline void dfs1(int dep,ll val)
{
	if(dep>n/2)
	{
		A.push_back(val);
		return ;
	}
	for(ri i=1;i<=m;i++)
		dfs1(dep+1,val+k[dep]*cifang[i][p[dep]]);
	
}
inline void dfs2(int dep,ll val)
{
	if(dep>n)
	{
		B.push_back(val);
		return ;
	}
	for(ri i=1;i<=m;i++)
		dfs2(dep+1,val+k[dep]*cifang[i][p[dep]]);
}
long long int sum=0;
int main()
{
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	read(n);
	read(m);
	for(ri i=1;i<=n;i++)
	{
		read(k[i]);
		read(p[i]);
		for(ri j=1;j<=m;j++)
		{
			cifang[j][p[i]]=mi(j,p[i]);
			if(cifang[j][p[i]]>2147483647ll)
				break;
		}
	}
	dfs1(1,0);
	dfs2(n/2+1,0);
	sort(A.begin(),A.end(),cmp1);
	sort(B.begin(),B.end(),cmp2);
	for(ri i=0;i<B.size();i++)
	{
		if(B[lower_bound(B.begin(),B.end(),-A[i])]==-A[i])
			sum++;
	}
	printf("%lld",sum);
}
