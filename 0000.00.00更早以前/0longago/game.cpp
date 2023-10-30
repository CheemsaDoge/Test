#include<iostream>
#include<fstream>
using namespace std;
int a[100001],b[100001];
int x1=-0x7fffffff;
int y1=0x7ffffff;
int x2=-0x7fffffff;
int y2=0x7ffffff;
bool flag1=0,flag2=0;
int z=0;
int Sea1(int l1,int l2,int r2)
{
	for(int j=l2;l2<=r2;l2++)
	{
		if(y1>=b[j]) y1=b[j];//min
		if(x2<=b[j]) x2=b[j];//max
	}
	if(a[l1]<0) {
		return a[l1]*x2;
	}else if(a[l1]>0){
		return a[l1]*y1;
	}else return z;
}
int sw(int l1,int r1,int l2)
{
for(int i=l1;l1<=r1;l1++)
	{
		if(x1<=a[i]) x1=a[i];//max
		if(y2>=a[i])  y2=a[i];//min
	//	if(a[i]==0) z=0;  
		//cout<<ay;
	}
	if(b[l2]<0) {
		return b[l2]*y2;
	}else if(b[l2]>0){
		return b[l2]*x1;
	}else return z;
}
int Search(int l1,int r1,int l2,int r2)
{
	flag1=0,flag2=0;
	bool flag3=0,flag4=0;
 x1=-0x7fffffff;
 y1=0x7ffffff;
 x2=-0x7fffffff;
 y2=0x7ffffff;
 int ay=0x7fffffff,ax=-0x7fffffff;
	for(int i=l1;l1<=r1;l1++)
	{
		if(a[i]<0){
			flag1=1;
		}
		if(a[i]>=0){
			flag3=1;
		}
		int z;
		if(x1<=a[i]) x1=a[i];//max
		if(y2>=a[i])  y2=a[i];//min
		if(ay>=a[i] && a[i]>=0)  ay=a[i];
		if(ax<=a[i]&&a[i]<0)  ax=a[i];
	//	if(a[i]==0) z=0;  
		//cout<<ay;
	}
		for(int j=l2;l2<=r2;l2++)
	{
		if(b[j]<0){
			flag2=1;
		}if(b[j]>=0){
			flag4=1;
		}
		if(y1>=b[j]) y1=b[j];//min
		
		if(x2<=b[j]) x2=b[j];//max
	}
	if((flag1==0 && flag2==0))  {
		return x1*y1;
	} 
	else if((flag3==0 && flag4==0)){
			return x1*y1;}
	else 	if(flag1==0 && flag2==1){
		return y2*y1;}
	 else if(flag1==1 && flag2==0){
		return x1*y1;
	} else if((flag1==1 && flag2==1)&&(flag3==1&& flag4==0))
	{
		return ay*y1;
	}else  if((flag1==1 && flag2==1)&&(flag3==0 && flag4==1))
	{
		 return x1*x2;
	}else  if(((flag1==1 && flag2==1)&&(flag3==1 && flag4==1))){
		return ay*x1;
	}
}
int main()
{
	ifstream fin("game.in");
	ofstream fout("game.out");
	int n,m,q;
	fin>>n>>m>>q;
	int l1,l2,r1,r2;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		fin>>b[j];
	 } 
	 for(int k=1;k<=q;k++)
	 {
	 	fin>>l1>>r1>>l2>>r2;
	 	if(l1==r1){
	 		fout<<Sea1(l1,l2,r2)<<endl;
		 }else if(l2==r2){
		 	fout<<sw(l1,r1,l2)<<endl;
		 }
	   else	fout<<Search(l1,r1,l2,r2)<<endl;
	 }
	fin.close();
	fout.close();
	return 0;
}
