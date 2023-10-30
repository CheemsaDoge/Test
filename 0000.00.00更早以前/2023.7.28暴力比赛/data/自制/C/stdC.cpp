#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+1145;
int va[MAXN];
int main(){
	freopen("C1.in","r",stdin);
	freopen("C1.ans","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&va[i]);
	int opt;
	int l,v,r;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&opt,&l,&r,&v);
		if(opt==0)
			for(int i=l;i<=r;i++) va[i]=sqrt(va[i]);
		else
		{
			long long ans=0;
			for(int i=l;i<=r;i++)
				ans+=va[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
