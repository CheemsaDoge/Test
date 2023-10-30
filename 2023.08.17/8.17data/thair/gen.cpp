#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n=30000;
int a[200010]; 
const LL MAXN=100000;
LL Rd()
{
	return rand()*rand()%MAXN+1;
}
int main()
{
  freopen("thair10.in","w",stdout);
  srand(time(NULL));
  printf("%d\n",n);
  for(int i=1;i<=n;i++)
  	printf("%d ",Rd());
  return 0;
}
