#include<bits/stdc++.h>
using namespace std;
bool isComp[100000005];
int main ()
{
	int n,ans=0;
	scanf("%d",&n);
	isComp[1]=1;  
	for(int i=2;i*i<=n;i++) 
	    if(isComp[i]==0)  
	        for(int j=i*i;j<=n;j+=i) 
	        	isComp[j]=1;   
	for(int i=1;i<=n;i++)
		ans+=isComp[i]==0?1:0;
	printf("%d",ans);
	return 0;  
}
