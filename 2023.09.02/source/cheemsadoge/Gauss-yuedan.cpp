#include <bits/stdc++.h>
using namespace std;

const int N=110;
const double eps=1e-6;//double����

int n;
double a[N][N];

int gauss()
{
	int c,r;//c��ʾ��ö����һ�У�r��ʾ��ö����һ��
	for(c=0,r=0;c<n;c++)
	{
		int t=r;
		for(int i=r;i<n;i++)
		{
			if(fabs(a[i][c])>fabs(a[t][c]))//��λ����ǰ����Ԫ�����ϵ�������� 
				t=i;
		}
		if(fabs(a[t][c])<eps) continue;
		for(int i=c;i<=n;i++)	swap(a[t][i],a[r][i]);//���������� 
		for(int i=n;i>=c;i--)	a[r][i]/=a[r][c];//ͬ����ϵ����һ 
		for(int i=r+1;i<n;i++)
		{
			if(fabs(a[i][c])>eps)
			{
				for(int j=n;j>=c;j--)
					a[i][j]-=a[r][j]*a[i][c];//��Ӽ�����ȥ�������ϵ�� 
			}
		}
		r++;
	}
	
	for(int i=n-1;i>=0;i--)//���ش����
	{
		for(int j=i+1;j<n;j++)
		{
			a[i][n]-=a[i][j]*a[j][n];
		}
	}
	
	if(r<n)
	{
		for(int i=r;i<n;i++)
		{
			if(fabs(a[i][n])>eps)
				return 2;//�޽�
		}
		return 1;//����������
	}
	
	return 0;//��Ψһ��
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cin>>a[i][j];
		}
	}
	int t=gauss();
	if(t==0)//��Ψһ��
	{
		for(int i=0;i<n;i++) printf("x%d=%.2lf\n",i+1,a[i][n]);
	}
	else if(t==1)puts("0");
	else puts("-1");
	
	return 0; 
}
