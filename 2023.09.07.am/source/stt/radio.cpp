#include<bits/stdc++.h>
using namespace std;
int n;
char a[1000005];
int fail[1000005];
int ans;
int main()
{
	freopen("radio.in","r",stdin);
	freopen("radio.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)
	{
		int p=fail[i-1];
		while(a[p+1]!=a[i]&&p)p=fail[p];
		if(a[p+1]==a[i]&&p+1!=i)fail[i]=p+1;
		ans=max(ans,i-fail[i]);
	}
	printf("%d",ans);
	return 0;
}
