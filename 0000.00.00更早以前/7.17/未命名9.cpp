#include<cstdio>
#define LL long long
LL x,y,m,n,l,a,b,c,x0,y0,g,tmp;
void exgcd(LL a,LL b){
	if(!b){x0=1;g=a;return;}//˳����gcd
	exgcd(b,a%b);
	tmp=x0;x0=y0;y0=tmp-a/b*y0;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	a=n-m;b=l;c=x-y;
	if(a<0)a=-a,c=-c;//����aΪ�������
	exgcd(a,b);
	if(c%g)puts("Impossible");
	else printf("%lld\n",(c/g*x0%(b/g)+b/g)%(b/g));//����С�Ǹ�������
	return 0;
}
