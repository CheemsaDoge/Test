#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
int totr=1;
struct point
{
	char c;
	int num;
	int nxt[26];
}rt[N];
void insert(string c)
{
	int p=1;
	int n=c.length();
	for(int i=0;i<n;i++)
	{
		if(!rt[p].nxt[c[i]-'a'])
		{
			totr++;
			rt[totr].c=c[i];
			rt[p].nxt[c[i]-'a']=totr;
		}
		p=rt[p].nxt[c[i]-'a'];
	}
	rt[p].num++;
}
int search(string c)
{
	int p=1;
	int n=c.length();
	for(int i=0;i<n;i++)
	{
		if(!rt[p].nxt[c[i]-'a'])
			return 0;
		p=rt[p].nxt[c[i]-'a'];
	}
	return rt[p].num;
}
int main()
{
	freopen("date.in","r",stdin);
	freopen("answer.out","w",stdout);
	int n;
	cin>>n;
	string a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		insert(a);
	}
	cin>>a;
	cout<<search(a);
}
