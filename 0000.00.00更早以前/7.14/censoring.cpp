#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
char s[100001],ori[100001];
int n,tot,w,top;
int trie[100001][26],fail[100001],heap[100001],sign[100001];
int isend[100001];
void insert(char *s){
    int now=0,len=strlen(s);
    for(int i=0;i<len;i++){
        int x=s[i]-'a';
        if(!trie[now][x])trie[now][x]=++tot;
        now=trie[now][x];
    }
    isend[now]=len;
}
void makefail(){
    queue<int> q;
    for(int i=0;i<26;i++)
    if(trie[0][i])q.push(trie[0][i]);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=0;i<26;i++){
            if(!trie[now][i]){
                trie[now][i]=trie[fail[now]][i];
                continue;
            }        
            fail[trie[now][i]]=trie[fail[now]][i];
            q.push(trie[now][i]);
        }
    }
}
void solve(char *s){
    int now=0,len=strlen(s),i=0;
    w=0;
    while(i<len){
        int x=s[i]-'a';
        now=trie[now][x];
        sign[++top]=now;
        heap[top]=i;
        if(isend[now]){
            top-=isend[now];
            if(!top) now=0;
            else now=sign[top];
        }
        i++;
    }
}
int main()
{
	freopen("censoring.in","r",stdin);
	freopen("censoring.out","w",stdout);
    scanf("%s",s);
    scanf("%d",&n);
    int len=strlen(s);
    for(int i=1;i<=n;i++){
        scanf("%s",ori);
        insert(ori);
    }
    makefail();
    solve(s);
    for(int i=1;i<=top;i++)
    printf("%c",s[heap[i]]);
    return 0;
}
