#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n=200000;
int a[200010]; 
const LL MAXN=1000000001;
LL Rd()
{
	return LL(rand()*rand()*rand()%MAXN+MAXN+rand())%MAXN;
}
int main()
{
  freopen("xor1.in","w",stdout);
  srand(time(NULL));
  for(int i=1;i<=n;i++)
	a[i]=Rd();
  int x=789789;
  sort(a+1,a+1+n);
  
  printf("%d\n",n);
  for(int i=1;i<=n;i++)
  	printf("%d ",a[i]^x);
  return 0;
}
