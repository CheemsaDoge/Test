#include<bits/stdc++.h>
using namespace std;

int n,m,t[4001],a[4001];
bool bj;

bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(t[i]>=2)
		{
			bool ok=1;
			t[i]-=2;
			for(int j=1;j<=n+2;j++)a[j]=t[j];
			for(int j=1;j<=n+2;j++)
			{
				if(a[j]<0)
				{
					ok=0;
					break;
				}
				a[j]%=3;
				a[j+1]-=a[j];
				a[j+2]-=a[j];
			}
			t[i]+=2;
			if(ok)return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("ma.in","r",stdin);
	freopen("ma.ans","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=m*3+1;i++)cin>>x,t[x]++;
	for(int i=1;i<=n;i++)
	{
		t[i]++;
		if(check())bj=1,cout<<i<<" ";
		t[i]--;
	}
	if(!bj)cout<<"NO";
	return 0;
}
