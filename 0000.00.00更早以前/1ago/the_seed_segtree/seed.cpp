#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	int c=time(0);
	int d,sum;
	int i=1;
	int ac=0,wa=0;
	int t=0;
	while(1)
	{
		t++;
		if(t>=1000000)
			if(getchar()-'0')	t=0;
			else	return 0;
		a=time(0)-c;
		if(a!=d)
		{
			d=a;
			sum=0;
		}
		sum++;
		printf("%d¥Œ≤‚ ‘£®AC:%d WA:%d)[time:%d][average:%d]\n",i,ac,wa,time(0)-c,sum);
		system("data.exe");//
		system("treestd.exe");//
		system("std.exe");//
		if(system("fc segtree.out std.out"))//
		{
			wa++;
			system("pause");
		}
		else
			ac++;
		i++;
	}
}
