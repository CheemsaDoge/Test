#include<bits/stdc++.h>
using namespace std;
namespace HMFS{
#define int long long
	int a,b,p,x,ans;
	int qpow(int a,int b=p-2){
		int res=1;
		for(;b;b>>=1,a=a*a%p)if(b&1)res=res*a%p;
		return res;
	}
	void work(){
		cin>>a>>b>>p>>x;
		for(int r=0,f,k,now;r<p-1;r++){
			f=b*qpow(qpow(a,r))%p;
			k=(r-f+p)%p;
			if((now=k*(p-1)+r)>x)continue;
			ans+=(x-now)/(p*(p-1))+1;
		}
		cout<<ans;
	}		
#undef int
}
int main(){
	return HMFS::work(),0;
}
