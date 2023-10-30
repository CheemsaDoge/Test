#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 10000
#define MAXlen 20
#define MAXC MAXN*MAXlen
using namespace std;
struct Node{
	char c;
	int num;
	int ch[26];
}rt[MAXC];
int totr=1;
int new_node(char c)
{
	totr++;
	rt[totr].c=c;
	return totr;
}
void Insert(char s[])
{
	int p=1;
	for(int i=0;i<strlen(s);i++)
	{
		if(rt[p].ch[s[i]-'a']==0)
			rt[p].ch[s[i]-'a']=new_node(s[i]);
		p=rt[p].ch[s[i]-'a'];
	}
	rt[p].num++;
}
char ans[MAXlen];
int cnt;
void dfs(int x)
{
	ans[cnt]=rt[x].c;
	cnt++;
	if(rt[x].num!=0)
	{
		ans[cnt]='\0';
		for(int i=1;i<=rt[x].num;i++)
			printf("%s\n",ans+1);
	}
			
	for(int i=0;i<26;i++)
	{
		int v=rt[x].ch[i];
		if(v)
			dfs(v);
	}
	cnt--;
}
int main(){
	char s[MAXlen];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&s);
		Insert(s);
	}
	dfs(1);
	return 0;
}
