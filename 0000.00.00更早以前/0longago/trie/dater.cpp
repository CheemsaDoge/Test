#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int main()
{
	int a;
	srand(time(0));
	freopen("date.in","w",stdout);
	int n=rand()%N;
	printf("%d",n);
	for(int i=0;i<=n;i++)
	{
		cout<<endl;
		int p=rand()%3+1;
		for(int j=0;j<p;j++)
		{
			a=rand()%26+'a';
			cout<<char(a);
		}
	}
}
