#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1145;
#define ll long long 
#define rl register long long 
#define ri register int

int exgcd(int a,int b,int& x,int& y)
{
	if(b==0){x=1;y=0;return a;}
	exgcd(a,b,x,y);
	int z = x;x=y;y=z-y*(a/b);
}

int main()
{
	int n;
    scanf("%d",&n);
    for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) { 
        cout << n/i;
        break;
    }
}
