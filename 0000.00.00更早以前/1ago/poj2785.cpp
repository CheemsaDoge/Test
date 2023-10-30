#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+1145;
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
#define ll long long int 
#define ri register int
ll A[MAXN],B[MAXN],C[MAXN],D[MAXN];
ll SA[MAXN],SC[MAXN];
int n;
int totr=0;
void calc()
{
	totr=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			SA[++totr]=A[i]+B[j];
	sort(SA+1,SA+1+totr);
	totr=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			SC[++totr]=C[i]+D[j];
	sort(SC+1,SC+1+totr,cmp);
}
int main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(A[i]);
	for(int i=1;i<=n;i++)
		read(B[i]);
	for(int i=1;i<=n;i++)
		read(C[i]);
	for(int i=1;i<=n;i++)
		read(D[i]);
	calc();
	
}

