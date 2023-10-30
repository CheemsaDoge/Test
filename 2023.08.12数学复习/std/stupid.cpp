#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
int C(int x,int y)
{
    if(y==x || !y) return 1;
    if(!x) return 0;
    return (C(x/2,y/2) % 2)*(C(x%2,y%2) % 2);
}
int main()
{
	freopen("stupid.in","r",stdin);
	freopen("stupid.out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &a, &b);
		printf("%d\n", C(a,b) % 2);
	}
	    
    return 0;
}
