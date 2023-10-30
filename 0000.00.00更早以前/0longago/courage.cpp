//O((2)nlogn) 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1145;	//!1145141919810!
int maxn=-1145,n;
priority_queue<int>a;
int b;
int main()
{
	freopen("courage.in","r",stdin);
	freopen("courage.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		a.push(b);
	}
	for(int i=1;i<=n;i++)
	{
		b=a.top();
		a.pop();
		maxn=max(maxn,b*i);
	}
	printf("%d",maxn);
}
