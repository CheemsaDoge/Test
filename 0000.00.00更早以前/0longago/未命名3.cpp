#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int v[N],prime[N];
int main()
{
		freopen("shai.in","r",stdin);
	freopen("x.out","w",stdout);
	int n;
	cin>>n;
	int m=0;
	for(int i=2;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=i;
			prime[++m]=i;
		}
		for(int j=1;j<=m;j++)
		{
			if(prime[j]>v[i]||prime[j]>n/i)	break;
			v[i*prime[j]]=prime[j];
		}
	}
	cout<<m;
	for(int i=1;i<=m;i++)
		cout<<prime[i]<<endl;
}
