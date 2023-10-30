#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
#define N 200005
#define M 100005
#define INF 0x7fffffff
char str[N];
char s[3][M];
int p[N];
 
int KMP(char* s1,char* s2)
{
    int n = strlen(s1);
    int m = strlen(s2);
    int j= -1;
    p[0]=-1;
    for(int i=1;i<m;i++)
    {
        while(j>=0&&s2[i]!=s2[j+1]) j=p[j];
        if(s2[i]==s2[j+1]) j++;
        p[i] = j;
    }
    j = -1;
    for(int i=0;i<n;i++)
    {
        if(j==m-1) return 0;
        while(j>=0&&s1[i]!=s2[j+1]) j=p[j];
        if(s1[i]==s2[j+1]) j++;
    }
    return m-1-j;
}
int combine(char* s1,char* s2,char* s3)
{
    int ret;
    ret = KMP(s1,s2);
    str[0] = '\0';
    strcat(str,s1);
    strcat(str,s2+strlen(s2)-ret);
    ret = KMP(str,s3);
    return ret+strlen(str);
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
    int ret ,ans = INF;
    scanf("%s%s%s",s[0],s[1],s[2]);
	ret = combine(s[0],s[1],s[2]);
	if(ret < ans) ans = ret;
	ret = combine(s[0],s[2],s[1]);
	if(ret < ans) ans = ret;
	ret = combine(s[1],s[0],s[2]);
	if(ret < ans) ans = ret;
	ret = combine(s[1],s[2],s[0]);
	if(ret < ans) ans = ret;
	ret = combine(s[2],s[0],s[1]);
	if(ret < ans) ans = ret;
	ret = combine(s[2],s[1],s[0]);
	if(ret < ans)  ans = ret;
// 	cout << strlen(s[0]) + strlen(s[1]) + strlen(s[2]) << endl;
	printf("%d\n",ans);
	return 0;
}
