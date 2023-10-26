#include<cstdio>
#include<algorithm>
namespace Acc{
	const int N = 3e5+10;
	const int M = 1.5e7+10;
	int a[N],d,p[M],np[M],n,cnt,buc[M],mx,ans;
	void sieve(int q){
		np[0]=np[1]=1;
		for(int i=2;i<=q;i++){
			if(!np[i])p[++cnt]=i;
			for(int j=1;j<=cnt && p[j]*i<=q;j++){
				np[i*p[j]]=1;
				if(i%p[j]==0)break;
			}
		}
	}
	void work(){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),d=std::__gcd(a[i],d);
		for(int i=1;i<=n;i++)a[i]/=d,mx=std::max(mx,a[i]),buc[a[i]]++;
		sieve(mx);ans=n;
		for(int i=1;i<=cnt;i++){
			int res=0;
			for(int j=1;p[i]*j<=mx;j++) res+=buc[p[i]*j];
			if(res) ans=std::max(ans,res);
		}
		printf("%d\n",ans==0?-1:n-ans);
	}
}
int main(){
	return Acc::work(),0;
}
