#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	int c=time(0);
	int d,sum;
	int i=1;
	int ac=0,wa=0;
	while(1)
	{
		a=time(0)-c;
		if(a!=d)
		{
			d=a;
			sum=0;
		}
		sum++;
		printf("%d¥Œ≤‚ ‘£®AC:%d WA:%d)[time:%d][average:%d]\n",i,ac,wa,time(0)-c,sum);
		system("data.exe");//
		system("x.exe");//
		system("std.exe");//
		if(system("fc x.out std.out"))//
		{
			wa++;
			system("pause");
		}
		else
			ac++;
		i++;
	}
}
