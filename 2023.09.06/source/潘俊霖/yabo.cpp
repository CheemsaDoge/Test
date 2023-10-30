/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
#define rint register int
#define fu(i,a,b,d,c) for(rint i=a;i<=(b)&&c;i+=d)
#define fd(i,a,b,d,c) for(rint i=a;i>=(b)&&c;i-=d)
using namespace std;
inline int read(){
	char c=0,f=1;int num=0;
	while((c<'0'||c>'9')&&(c!='-'))((c=getchar())=='-')&&(f=-f);
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+(c^48),c=getchar();
	return num*f;
}template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
const int dx[9]={0,-1,0,0,1,0,0,0,0},dy[9]={0,0,1,0,0,0,0,0,-1};
int L,R,n,m,K,Limit,P,TimeLimit,curTime,mouseCnt;
int pipes[55][55];
struct Point{
	int x,y;
};
#define N 1
#define E 2
#define S 4
#define W 8
#define XY 1
#define XX 2
struct Weapon{
	int x,y,type,setTime,occurTime;
	bool operator<(const Weapon b)const{return occurTime<b.occurTime;}
	Weapon(){x=y=type=setTime=occurTime=0;}
};
vector <Weapon> weapons;
class Mice{
	public:
		int age,sex,isProducing,towards,facingCross,x,y,stopTime,produceTime;
		void move() {
			int f=towards;
			if(pipes[x][y]&f){
				x+=dx[f];
				y+=dy[f];
				return;
			}
			if(f==1||f==4){
				if((pipes[x][y]&2)&&(pipes[x][y]&8)){
					towards=facingCross&1?(f==1?2:8):(f==1?8:2);
					facingCross++;
				}
				else if(pipes[x][y]&8)towards=8;
				else if(pipes[x][y]&2)towards=2;
				else towards=8;
			}
			if(f==8||f==2){
				if((pipes[x][y]&4)&&(pipes[x][y]&1)){
					towards=facingCross&1?(f==2?4:1):(f==2?1:4);
					facingCross++;
				}
				else if(pipes[x][y]&1)towards=1;
				else if(pipes[x][y]&4)towards=4;
				else towards=1;
			}
		}
	private:
		bool ismakinglove;
};

vector<Mice>mice;
void produceNewMouse(int x,int y){
	Mice tmp;
	tmp.x=x,tmp.y=y,tmp.age=0;
	if((pipes[x][y]&N)){
		tmp.towards=N,tmp.sex=XY;
		mice.push_back(tmp);
	}
	if((pipes[x][y]&E)){
		tmp.towards=E,tmp.sex=XX;
		mice.push_back(tmp);
	}
	if((pipes[x][y]&S)){
		tmp.towards=S,tmp.sex=XY;
		mice.push_back(tmp);
	}
	if((pipes[x][y]&W)){
		tmp.towards=W,tmp.sex=XX;
		mice.push_back(tmp);
	}
}
void Datain()
{
	L=read(),R=read(),n=read(),m=read();
	fu(i,1,n,1,1)fu(j,1,m,1,1)pipes[i][j]=read();
	K=read();
	for(int i=1;i<=K;i++)
	{
		char tmpsex,t;
		Mice tmp;
		scanf("%d %d %c %c",&tmp.x,&tmp.y,&t,&tmpsex);
		if(t=='N')tmp.towards=N;
		if(t=='E')tmp.towards=E;
		if(t=='S')tmp.towards=S;
		if(t=='W')tmp.towards=W;
		tmp.sex=(tmpsex=='X'?1:2);
		tmp.age=114514;
		tmp.facingCross=0;
		tmp.isProducing=false;
		tmp.produceTime=0;
		tmp.stopTime=0;
		mice.push_back(tmp);
	}
	P=read(),Limit=read();
	Weapon A;
	for(int i=1;i<=P;i++)
	{
		A.type=read();A.setTime=read();A.x=read();A.y=read();
		A.occurTime=A.setTime;
		if(A.type==3) A.occurTime+=3;
		weapons.push_back(A);
	}
	sort(weapons.begin(),weapons.end());
	TimeLimit=read();
}
void dfsBomb(int x,int y,int dir,int lastlength){
	if(lastlength>L)return;
	for(int i=0;i<(int)mice.size();){
		if(mice[i].x==x&&mice[i].y==y) mice.erase(mice.begin()+i);
		else i++;
	}
	if(pipes[x][y]&dir)	dfsBomb(x+dx[dir],y+dy[dir],dir,lastlength+1);
}
void runBomb(int x,int y)
{
	if(pipes[x][y]&1) dfsBomb(x,y,1,1);
	if(pipes[x][y]&2) dfsBomb(x,y,1,2);
	if(pipes[x][y]&4) dfsBomb(x,y,1,4);
	if(pipes[x][y]&8) dfsBomb(x,y,1,8);
}
double dist(int x1,int y1,int x2,int y2) {return sqrt(1.00*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));}
void runRay(int x,int y)
{
	for(int i=0;i<(int)mice.size();i++)
	{
		if(dist(x,y,mice[i].x,mice[i].y)<=double(R)){
			mice[i].stopTime+=3,mice[i].produceTime+=3;
		}
	}
}
void runTimeBomb(int x,int y)
{
	for(int i=0;i<(int)mice.size();)
		if(x==mice[i].x&&mice[i].y==y) mice.erase(mice.begin()+i);
		else i++;
}
void runSwBomb(int x,int y)
{
	for(int i=0;i<(int)mice.size();i++)
		if(x==mice[i].x&&mice[i].y==y)
			mice[i].sex=3-mice[i].sex;
}
int _n;
void RunWeapons()
{
	while(_n<(int)weapons.size()&&weapons[_n].occurTime==curTime){
		Weapon A=weapons[_n];
		if(A.type==1) runBomb(A.x,A.y);
		else if(A.type==2) runRay(A.x,A.y);
		else if(A.type==3) runTimeBomb(A.x,A.y);
		else if(A.type==4) runSwBomb(A.x,A.y);
		_n++;
	}
}
void mouseProduce(Mice& mouse){
	if(mouse.stopTime||mouse.produceTime||mouse.isProducing||!(mouse.age>=5))return;
	int atMyPos=0;
	for(int i=0;i<(int)mice.size();i++)if(mice[i].x==mouse.x&&mice[i].y==mouse.y)atMyPos++;
	if(atMyPos!=2)return;
	for(int i=0;i<(int)mice.size();i++)
	if(mice[i].x==mouse.x&&mice[i].y==mouse.y&&!mice[i].stopTime&&!mice[i].isProducing&&mice[i].sex!=mouse.sex&&mice[i].age>=5&&!mice[i].produceTime){
		mouse.produceTime=mice[i].produceTime=curTime+2,mouse.stopTime=mice[i].stopTime+=3;
		if(mouse.sex==2)mouse.isProducing=1;
		else mice[i].isProducing=1;
		break;
	}
}
void checkOver(){
	if((int)mice.size()>Limit){
		printf("-1");
		exit(0);
	}
}
int main()
{
	freopen("yabo.in","r",stdin);
	freopen("yabo.out","w",stdout);
	Datain();
	checkOver();
	for(curTime = 0; curTime <= TimeLimit;curTime++){
		RunWeapons();
		for(int i=0;i<(int)mice.size();i++)mouseProduce(mice[i]);
		for(int i=0;i<(int)mice.size();i++){
			if(mice[i].produceTime==curTime&&mice[i].isProducing){
				produceNewMouse(mice[i].x,mice[i].y);
				mice[i].isProducing=0;
			}
		}
		checkOver();
		for(int i=0;i<(int)mice.size();i++){
			if(mice[i].stopTime)mice[i].stopTime--;
			else mice[i].age++,mice[i].produceTime=0,mice[i].move();
		}
	}
	printf("%d",mice.size());
	return 0;
}
