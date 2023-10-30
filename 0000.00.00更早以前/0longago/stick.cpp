#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
bool cmp(int x,int y)
{
	return x>y;
}
int num;
int stick[102];
int n;
int a[100],maxn,tot,minn;
bool dfs(int m,int x)
{
	if(m>n)
	{
		for(int i=1;i<=num;i++)
			if(stick[i]!=x)
//				cout<<"q"<<i<<" "<<stick[i]<<endl;
				return 0;
		return 1;
	}
	for(int i=1;i<=num;i++)
	{
		if(a[m]<=x-stick[i])
		{
			stick[i]+=a[m];
			return dfs(m+1,x);
		}
	}
//	cout<<"p"<<m<<" "<<x<<" "<<endl;
//	for(int i=1;i<=num;i++)
//		cout<<stick[i]<<" ";
//	cout<<endl;
	return 0;
}
int main()
{
//	freopen("stick.in","r",stdin);
//	freopen("stick.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>50)
		{
			i--;
			n--;
			continue;
		}
		tot+=a[i];
		maxn=max(maxn,a[i]);
	}
	minn=tot;
	sort(a+1,a+n+1,cmp);
	for(int i=tot;i>=maxn;i--)
	{
		if(tot%i!=0)
			continue;
//			cout<<i<<" ";
		num=tot/i;
		memset(stick,0,100);
		if(dfs(1,i))
			minn=i;
	}
	memset(stick,0,num+2);
	printf("%d\n",minn);
}
