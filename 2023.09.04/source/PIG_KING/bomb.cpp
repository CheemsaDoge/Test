#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

inline int read(){
	int x=0,w=1;
	char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*w;
}

double a[20][20],b[20],c[20][20];//c:矩阵系数  b:常数  两者构成增广矩阵  
int n;

int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout); 
	n=read();
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			c[i][j]=2*(a[i][j]-a[i+1][j]);
			b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
		}
	//高斯消元（数据保证有唯一解）
	for(int i=1;i<=n;i++){//找到x[i]系数不为0的一个方程
		for(int j=i;j<=n;j++){
			if(fabs(c[j][i]>1e-8)){
				for(int k=1;k<=n;k++)
					swap(c[i][k],c[j][k]);
				swap(b[i],b[j]);
			}
		}
	//消去其他方程x[i]的系数
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			double rate=c[j][i]/c[i][i];
			for(int k=i;k<=n;k++) c[j][k]-=c[i][k]*rate;
			b[j]-=b[i]*rate;
		}
	}
	for(int i=1;i<n;i++)
		printf("%0.3lf ",b[i]/c[i][i]);
	printf("%.3lf\n",b[n]/c[n][n]);
	return 0;
}
