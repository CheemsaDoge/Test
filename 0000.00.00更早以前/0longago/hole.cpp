//trie std
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
int trie[N][26];
int tot=1;
int end[N];
char a[1145];
inline int insert(string c)
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
	end[p]=1;
}
inline int search(string c)
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
	int y;
	freopen("hole.in","r",stdin);
	freopen("hole.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	char a[1145];
	for(int i=0;i<n;i++)
	{
		scanf("%s",&a);
		insert(a);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",&a);
		y=search(a);
		if(y)	puts("Yes");
		else puts("No");
	}
}
