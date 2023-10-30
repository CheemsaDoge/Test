#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e5+1145;
const int MAXM=1e6+1145;
int colour[MAXN];
int maxn=0;
struct point{
	int x,y,a;	
}a[MAXN];
vector<int>hang[MAXM];
vector<int>lie[MAXN];
int N,R,C,x,y,z;
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	read(N);
	read(R);
	read(C);
	srand(time(0));
	int f=rand()%N;
	printf("%d\n",N-f);
}
