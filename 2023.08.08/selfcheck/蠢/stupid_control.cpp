#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
int main()
{
	int a;
	int c=time(0);
	int d,sum;
	int i=1;
	int ac=0,wa=0;
	int maxn=0;
	while(1)
	{
		system("CLS");
		a=time(0)-c;
		if(a!=d)
		{
			d=a;
			sum=0;
		}
		sum++;
		int timer=time(0)-c;
		maxn=max(maxn,sum);
		printf("%d¥Œ≤‚ ‘£®AC:%d WA:%d)[time:%d][average:%d][maxn=%d]\n",i,ac,wa,timer,int(i/(timer+1)),maxn);
		system("datamaker.exe");
		system("stupid_std.exe");
		system("stupid.exe");
		if(system("fc stupid.out stupid.ans"))
		{
			wa++;
			system("pause");
		}
		else
			ac++;
		i++;
	}
}
