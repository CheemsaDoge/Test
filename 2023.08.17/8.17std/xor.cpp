#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int a[200010]; 
int ans[50],u;//-1:unknown 0/1:ans 
int num(int x,int y)
{
	return (x>>y)&1;
}
void End()
{
	printf("-1");
	exit(0);
}
void Work(int l,int r,int pos)
{
	if(l==r)
		return;
	if(pos==-1)
		return;
		
	bool xy=true,dy=true;
	int pp;
	for(int i=l;i<r;i++)
	{
		if(num(a[i],pos)>num(a[i+1],pos))
			xy=false,pp=i;
		if(num(a[i],pos)<num(a[i+1],pos))
			dy=false,pp=i;
	}
	
	if(!xy&&!dy)
		End();
		
	if(xy&&dy)
	{
		Work(l,r,pos-1);
		return;
	}
	
	if(xy)
	{
		if(ans[pos]==1)
			End();
		ans[pos]=0;
	}
	if(dy)
	{
		if(ans[pos]==0)
			End();
		ans[pos]=1;
	}
	Work(l,pp,pos-1);
	Work(pp+1,r,pos-1);
}
int main()
{
	freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  	scanf("%d",&a[i]);
  for(int i=0;i<=30;i++)
  	ans[i]=-1;
  Work(1,n,30);
  for(int i=0;i<=30;i++)
  	u|=(1<<i)*(ans[i]==1);
  cout<<u;
  return 0;
}
