#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+1145;
int va[MAXN];
int main(){
	freopen("A10.in","r",stdin);
	freopen("A10.ans","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&va[i]);
	int opt;
	int l,v,r;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&opt,&l,&r,&v);
		if(opt==0)
			for(int i=l;i<=r;i++) va[i]+=v;
		else
		{
			int ans=0;
			for(int i=l;i<=r;i++)
				if(va[i]<v) ans=max(ans,va[i]);
			printf("%d\n",ans?ans:-1);
		}
	}
	return 0;
}
