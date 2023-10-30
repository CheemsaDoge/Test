#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
int trie[N][26];
int tot=1;
int end[N];

int insert(string c)
{
	int len=c.length();
	int p=1;
	for(int k=0;k<len;k++)
	{
		int ch=c[k]-'a';
		if(trie[p][ch]==0)
			trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	end[p]++;
}
int search(string c)
{
	int len=c.length();
	int p=1;
	for(int k=0;k<len;k++)
	{
		p=trie[p][c[k]-'a'];
		if(p==0)	return 0;
	}
	return end[p];
}
int main()
{
	freopen("date.in","r",stdin);
	freopen("stdout.out","w",stdout);
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
