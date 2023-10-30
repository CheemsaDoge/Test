#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a[100];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=m;i++) cout<<a[i]<<" ";
	cout<<endl;
	while(next_permutation(a+1,a+1+n))
	{
		for(int i=1;i<=m;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}
