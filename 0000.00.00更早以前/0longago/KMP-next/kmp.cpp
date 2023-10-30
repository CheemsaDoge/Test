#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
int next[N];
string a;
string b;
int lena,lenb,n;
int f[N];
void kmp_next()
{
	int p;
	next[0]=0;
	for(int i=1;i<lena;i++)
	{
		p=next[i-1];
		while(p!=0)	if(a[i]=a[next[p]-1])	next[i]=next[p]+1;
		else p=next[p];
	}

} 
int main()
{
//	freopen("x.in","r",stdin);
//	freopen("x.out","w",stdout);
	cin>>a>>b;
	lena=a.length();
	lenb=b.length();
	kmp_next();
	for(int i=1;i<=lena;i++)
		cout<<next[i]<<" ";
}
