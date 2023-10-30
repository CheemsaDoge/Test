/*** 
 * @Author: ltt
 * @Date: 2023-01-12 18:39:52
 * @LastEditors: ltt
 * @LastEditTime: 2023-07-26 18:22:56
 * @FilePath: spj.cpp
*/
#include <bits/stdc++.h>
#include "testlib_for_lemons.h"
#define WA 0
#define AC 1
#define WRONG_FORMAT 2
using namespace std;
FILE *fin, *fout, *fstd, *fscore, *freport;

struct RET
{
	int state;
	char message[100];
	int x_1, x_2, x_3;
};

RET check();

int main(int argc, char *argv[]) {
	registerLemonChecker();
	fin = fopen("ap.in", "r");
	fout = fopen("ap.out", "r");
	// fstd = fopen(argv[2], "r");//std ans
	fscore = fopen("score.log", "w");
	freport = fopen("report.log", "w");

	RET ret = check();
	if(ret.state == AC)
	{
		fprintf(fscore, "%s", argv[1]);
		fprintf(freport, "%s", ret.message);
	}
	else if(ret.state == WA)
	{
		fprintf(fscore, "%d", 0);
		fprintf(freport, "%s\n", ret.message);
		fprintf(freport, "we found subsequence %d %d %d", ret.x_1, ret.x_2, ret.x_3);
	} else {
		fprintf(fscore, "%d", 0);
		fprintf(freport, "%s\n", ret.message);
	}
	return 0;
}

typedef unsigned long long ull;
const ull seed=233;
int n;
char a[500005];
ull ksm[500005];
struct node{
	int l,r;
	ull vl,vr;
}Tree[2000005];
void ztree(int p,int l,int r){
	Tree[p].l=l,Tree[p].r=r;
	if(l==r){
		Tree[p].vl=Tree[p].vr=(unsigned long long)a[l];
		return;
	}
	int mid=l+r>>1;
	ztree(p*2,l,mid);
	ztree(p*2+1,mid+1,r);
	Tree[p].vl=Tree[p*2].vl*ksm[r-mid]+Tree[p*2+1].vl;
	Tree[p].vr=Tree[p*2+1].vr*ksm[mid-l+1]+Tree[p*2].vr;
}
ull Getl(int p,int l,int r){
	if(l<=Tree[p].l&&Tree[p].r<=r)return Tree[p].vl;
	int mid=Tree[p].l+Tree[p].r>>1;
	ull vl=0,vr=0;
	if(l<=mid)vl=Getl(p*2,l,r);
	if(r>mid)vr=Getl(p*2+1,l,r);
	if(!vl)return vr;
	if(!vr)return vl;
	return vl*ksm[min(Tree[p*2+1].r,r)-mid]+vr;
}
ull Getr(int p,int l,int r){
	if(l<=Tree[p].l&&Tree[p].r<=r)return Tree[p].vr;
	int mid=Tree[p].l+Tree[p].r>>1;
	ull vl=0,vr=0;
	if(l<=mid)vl=Getr(p*2,l,r);
	if(r>mid)vr=Getr(p*2+1,l,r);
	if(!vl)return vr;
	if(!vr)return vl;
	return vr*ksm[mid+1-max(Tree[p*2].l,l)]+vl;
}
void update(int p,int l){
	if(Tree[p].l==Tree[p].r){
		Tree[p].vl=Tree[p].vr=(unsigned long long)a[l];
		return;
	}
	int mid=Tree[p].l+Tree[p].r>>1;
	if(l<=mid)update(p*2,l);
	else update(p*2+1,l);
	Tree[p].vl=Tree[p*2].vl*ksm[Tree[p].r-mid]+Tree[p*2+1].vl;
	Tree[p].vr=Tree[p*2+1].vr*ksm[mid-Tree[p].l+1]+Tree[p*2].vr;
}

RET check(){
	fscanf(fin, "%d", &n) == 0;
	ksm[0]=1;
	for(int i=1;i<=n;i++)a[i]='0',ksm[i]=ksm[i-1]*seed;
	ztree(1,1,n);
	for(int i=1;i<=n;i++){
		int x;
		if (fscanf(fout, "%d", &x) <= 0) 
			return RET{WRONG_FORMAT, "wrong format: You have less than n outputs"};
		if (x <= 0 || x > n) return RET{WRONG_FORMAT, "wrong format: The elements are in the interval [1,n]"};
		if (a[x] == '1') return RET{WRONG_FORMAT, "wrong format: The output contains repeated elements"};
		if(x==1||x==n){
			a[x]='1';
			update(1,x);
			continue;
		}
		int lenl=x-1,lenr=n-x;
		if(lenl<lenr)lenr=lenl;
		else lenl=lenr;
		ull vl=Getl(1,x-lenl,x-1);
		ull vr=Getr(1,x+1,x+lenr);
		a[x]='1';
		update(1,x);
		if(vl!=vr) {
			for (int j=1; j<=lenl; ++j) {
				if (a[x-j] != a[x+j]) {
					return RET{WA, "wrong answer", x-j, x, x+j};
				}
			}
		}
	}
	return RET{AC, "Accepted"};
}
