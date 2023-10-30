#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
bool cmp(int x,int y)
{
	return x>y;
}
bool ac;
int n,a[100],tot,maxn,minn;
int used[100],sum;
void dfs(int num,int len,int last)
{
	if(last==0)
	{
		cout<<num;
		
		if(num==sum)
		{
			printf("%d",len);
			exit(0);
		}
		dfs(num+1,len,len);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i]&&a[i]<=last)
		{
			used[i]=1;
			dfs(num,len,last-a[i]);
			used[i]=0;
			if(a[i]==last||last==sum)
				break;
		}
	}
	return;
}
/*
24
26 43 23 20 19 6 34 25 21 22 48 47 38 28 27 3 25 13 36 27 15 32 26 26
*/
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>50)
		{
			a[i]=0;
			i--;
			n--;
			continue;
		}
		tot+=a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<endl;
	for(int i=maxn;i<=tot/2;i++)
	{
		if(tot%i!=0)
			continue;
		sum=tot/i;
		dfs(1,i,i);
	}
	printf("%d",tot);
}
