/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]
inline void _File()
{
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
}
inline int max(const int a,const int b)
{
	return a>b?a:b;
}
int n,l,r,ans;
bool vis[MAXN];
int a[MAXN];
int b[MAXN];
bool cmp1(int i,int j)
{
	return a[i]<a[j];
}
int main(){
//	_File();
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]),b[i]=i;
	std::sort(b+1,b+1+n,cmp1);
	int now=0;
	a[b[1]]=0;
	int last=a[b[1]];
	for(int i=2;i<=n;i++)
	{
		if(a[b[i]]!=last) last=a[b[i]],now++;
		a[b[i]]=now;
	}
	if(now==0) 
	{
		write(1);
		return 0;
	}
	vis[a[1]]=true;
	r=1;l=1;
	while(r<n)
	{
		while(!vis[a[r+1]]&&r+1<=n) vis[a[++r]]=true;
//		if(r-l+1==2) cout<<"ss"<<r<<l<<a[r]<<a[l];
		ans=max(ans,r-l+1);
		while(l<=r&&vis[a[r+1]]) vis[a[l]]=false,l++;
	}
	write(ans);
	return 0;
}

