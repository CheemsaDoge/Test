#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main()
{
	freopen("five.in","r",stdin);
	freopen("five_std.out","w",stdout);
	ll a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int n;
	cin>>n;
	n-=5;
	int q;
	for(int i=1;i<=n;i++)
	{
		q=e;
		e=(a+b+c+d+e)%mod;
		a=b;
		b=c;
		c=d;
		d=q;
	}
		cout<<e%mod;
}
/*
	 	 __
1 1 0 0 0 |
1 1 1 0 0 |
1 0 1 0 0 |* [ai-1 ai-2 ai-3 ai-4 ai-5] 
1 0 0 1 0 |
1 0 0 0 1_|
		 

*/
