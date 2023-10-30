#include<bits/stdc++.h>
using namespace std;
#define ri register int

inline long long ra(int x)
{
	return (rand()%x)+1;
}

int main()
{
	srand(time(0));
	freopen("0.in","w",stdout);
	int T=30;
	printf("%d\n",T);
	while(T--)
	{
//		long long n=10,k=ra(10);
		long long n=100000,k=ra(n)*ra(n);
		if(T==1)
		{
			printf("1 %lld\n",k);
			putchar('1');
			continue;
		}
		if(T==2)
		{
			printf("1 %lld\n",k);
			putchar('0');
			continue;
		}
		printf("%lld %lld\n1",n,k);
		for(ri i=2;i<=n;i++) printf("%d",ra(2)-1);
		putchar('\n');
	}
	return 0;
}


