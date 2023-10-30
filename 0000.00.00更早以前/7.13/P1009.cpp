#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
char a[500];
char b[500];
char c[500];
int add()
{
	int la,lb;
	la=strlen(a);
	lb=strlen(b);
	for(int i=0;i<=max(la+10,lb+11);i++)
	{
		b[i]+=a[i];
		if(b[i]>=10)
		{
			b[i+1]+=b[i]/10;
			b[i]%=10;
		}
	}
}
int mul(int n)
{
	int la,lb;
	la=strlen(a);
	lb=strlen(b);
	for(int i=0;i<=la+10;i++)
		a[i]*=n;
	for(int i=0;i<=la+10;i++)
		if(a[i]>=10)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	add();
}
int puts()
{
	int lb=strlen(b);
	for(int i=lb-1;i>=0;i--)
		cout<<int(b[i]);
}
int main()
{
	int n;
	read(n);
	a[0]=1;
	for(int i=1;i<=n;i++)
		mul(i);
	puts();
}

#include<stdio.h>
int main()
{
    int n;
}
