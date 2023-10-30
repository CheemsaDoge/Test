//
// Created by 96454 on 2023/9/12.
//
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
template <typename T> void read(T &x) {
    x=0;
    T f=1,_ch=getchar();
    while(_ch!='-'&&!isdigit(_ch)) _ch=getchar();
    if(_ch=='-') f=-1,_ch=getchar();
    while(isdigit(_ch)) x=(x<<3)+(x<<1)+(_ch^'0'),_ch=getchar();
    x=x*f;
}
//output
#define py puts("success")
#define pn puts("unsuccess")
//user State
#define down_line 0
#define online 1
#define downloading 2
#define user_uploading 3
//user Type
#define uploadUser 1
#define downloadUser 2
//#define guest 3
//file State
#define normal 1
#define uploading 2
//file Type
#define folder 1
#define file 2
map<string,int>h_user;
int userCnt;
int fileCnt;
int _time;
int maxUserNumber,userNumber,maxServerFlux,serverFlux,maxUserFlux,userTotal,userFlux;
const int root=0;
set<int>loadAsk;
struct Users{
    int userType{},userState{},userPosition{},userId{};
    int downloadingMemory{},downloadedMemory{};
    int uploadingPosition{},uploadingMemory{},uploadedMemory{};
    string uploadingFileName;
    void clear(){
        downloadingMemory = downloadedMemory = uploadingPosition = uploadingMemory = uploadedMemory;
        uploadingFileName.clear();
    }
}users[MAXN];
struct File{
    string fileName;
    int fileFather{};
    int fileType{},fileSize{},fileState{},fileId{};
    vector<int>fileSon;
}files[MAXN];

bool connect(const string& name,int A)
{
    if(h_user.find(name)==h_user.end())
    {
        if(userNumber>=maxUserNumber) return false;
        h_user[name]=++userCnt;
        users[userCnt].userState=down_line;
    }
    int _id=h_user[name];
    if(users[h_user[name]].userState == down_line)
    {
        if(userNumber>=maxUserNumber) return false;
        userNumber++;
        users[_id].userId=_id;
        users[_id].userType=A;
        users[_id].userPosition=root;
        users[_id].userState=online;
        return true;
    }
    return false;
}
void updateFileState(int fileId)
{
	int faId=files[fileId].fileFather;
	
}
int queryFileState(int fileId)
{
    return files[fileId].fileState==uploading?uploading:files[files[fileId].fileFather].fileId!=root?queryFileState(files[files[fileId].fileFather].fileId):normal;
}
bool quit(const string& name)
{
    if(h_user.find(name)==h_user.end()) return false;
    int _id=h_user[name];
    if(users[_id].userState == down_line) return false;
    if(users[_id].userState==downloading) userTotal--;
    if(users[_id].userState==user_uploading)
    {
        userTotal--;
		if(files[users[_id].uploadingPosition].fileFather!=root)
			updateFileState(users[_id].uploadingPosition);
    }
    if(users[_id].userState==user_uploading||users[_id].userState==downloading)
    {
        loadAsk.erase(_id);
    }
    users[_id].clear();
    users[_id].userState=down_line;
    users[_id].userPosition=0;
    userNumber--;
    return true;
}
bool cd(const string& userName,const string& folderName)
{
    if(h_user.find(userName)==h_user.end()) return false;
    int userId=users[h_user[userName]].userId;
    if(users[userId].userState == down_line) return false;
    int position=users[userId].userPosition;
    int _fileNum=(int)files[position].fileSon.size();
    for(int i=0;i<_fileNum;i++)
        if(files[files[position].fileSon[i]].fileName==folderName)
        {
            if(files[files[position].fileSon[i]].fileType==file) return false;
            users[userId].userPosition=files[files[position].fileSon[i]].fileId;
            return true;
        }
    return false;
}
bool cdBack(const string& userName)
{
    if(h_user.find(userName)==h_user.end()) return false;
    int userId=users[h_user[userName]].userId;
    if(users[userId].userState == down_line) return false;
    int position=users[userId].userPosition;
    if(position==root) return false;
    users[userId].userPosition=files[position].fileFather;
    return true;
}
bool download(const string& userName,const string& fileName)
{
    if(h_user.find(userName)==h_user.end()) return false;
    int userId=users[h_user[userName]].userId;
    if(users[userId].userState!=online) return false;
    if(users[userId].userType!=downloadUser) return false;
    int position=users[userId].userPosition;
    int _fileNum=(int)files[position].fileSon.size();
    for(int i=0;i<_fileNum;i++)
        if(files[files[position].fileSon[i]].fileName==fileName)
        {
            if(files[files[position].fileSon[i]].fileState==uploading) return false;
            userTotal++;
            users[userId].userState=downloading;
            users[userId].downloadingMemory=files[files[position].fileSon[i]].fileSize;
            users[userId].downloadedMemory=0;
            if(!loadAsk.count(userId)) loadAsk.insert(userId);
            return true;
        }
    return false;
}
void updateSize(int fileId,int added)
{
    files[files[fileId].fileFather].fileSize+=added;
    if(files[files[fileId].fileFather].fileFather!=root) updateSize(files[fileId].fileFather,added);
    else return;
}
void newFile(int userId)
{
    userTotal--;
    files[++fileCnt].fileFather=users[userId].uploadingPosition;
    files[fileCnt].fileId=fileCnt;
    files[fileCnt].fileName=users[userId].uploadingFileName;
    files[fileCnt].fileSize=users[userId].uploadingMemory;
    files[fileCnt].fileSon.clear();
    files[fileCnt].fileState=normal;
    files[fileCnt].fileType=files[fileCnt].fileSize?file:folder;
    files[users[userId].uploadingPosition].fileSon.push_back(fileCnt);
    if(files[fileCnt].fileSize!=0) updateSize(fileCnt,files[fileCnt].fileSize);
    updateFileState(fileCnt);
    users[userId].userState=online;
    users[userId].uploadingMemory=0;
    users[userId].uploadingFileName.clear();
    users[userId].uploadingPosition=0;
    users[userId].uploadedMemory=0;
}
bool upload(const string& userName,const string& fileName,int _fileSize)
{
    if(h_user.find(userName)==h_user.end()) return false;
    int userId=users[h_user[userName]].userId;
    if(users[userId].userState!=online) return false;
    if(users[userId].userType!=uploadUser) return false;
    if(files[users[userId].userPosition].fileState==uploading||queryFileState(users[userId].userPosition)==uploading) return false;
    int position=users[userId].userPosition;
    int _fileNum=(int)files[position].fileSon.size();
    for(int i=0;i<_fileNum;i++)
        if(files[files[position].fileSon[i]].fileName==fileName) return false;
    userTotal++;
//			cout<<"fuck CCf"<<userTotal<<endl;
    users[userId].userState=user_uploading;
    users[userId].uploadingMemory=_fileSize;
    users[userId].uploadingFileName=fileName;
    users[userId].uploadingPosition=position;
    users[userId].uploadedMemory=0;
    files[position].fileState=uploading;
    updateFileState(position);
	if(!loadAsk.count(userId)) loadAsk.insert(userId);
	if(_fileSize==0) newFile(userId);
    return true;
}
//int maxUserNumber,userNumber,maxServerFlux,serverFlux,maxUserFlux,userTotal,root;
vector<int>tmpp;
void runServer(){
    tmpp.clear();
    serverFlux=maxServerFlux/userTotal;
    userFlux=min(maxUserFlux,serverFlux);
    for(int it : loadAsk)
    {
        int userId=it;
        if(users[userId].userState==user_uploading)
        {
            users[userId].uploadedMemory+=userFlux;
            if(users[userId].uploadedMemory>=users[userId].uploadingMemory)
            {
                newFile(userId);
                tmpp.push_back(it);
            }
        }
        else
        {
            users[userId].downloadedMemory+=userFlux;
            if(users[userId].downloadedMemory>=users[userId].downloadingMemory)
            {
                userTotal--;
                users[userId].downloadedMemory=0;
                users[userId].downloadingMemory=0;
                users[userId].userState=online;
                users[userId].uploadingMemory=0;
                users[userId].uploadingFileName.clear();
                users[userId].uploadingPosition=0;
                users[userId].uploadedMemory=0;
                tmpp.push_back(it);
            }
        }
    }
    for(int i : tmpp)
        loadAsk.erase(i);
}
stack<int>folders;
int main() {
    read(maxUserNumber);
    read(maxServerFlux);
    read(maxUserFlux);
    int waitClose=1;
    folders.push(root);
    files[0].fileType=folder;
    files[0].fileId=0;
    files[0].fileState=normal;
    files[0].fileName="root";
    files[0].fileFather=-1;
    while(true) {
        string str;
        cin>>str;
        if(waitClose>0)
        {
            if (str == "-"){
                for(int i=0;i<(int)files[folders.top()].fileSon.size();i++)
                    files[folders.top()].fileSize+=files[files[folders.top()].fileSon[i]].fileSize;
                waitClose--;
                folders.pop();
            }
            else {
                int size;read(size);
                if (size==0){
                    files[++fileCnt].fileFather=folders.top();
                    files[folders.top()].fileSon.push_back(fileCnt);
                    files[fileCnt].fileId=fileCnt;
                    files[fileCnt].fileName=str;
                    files[fileCnt].fileState=normal;
                    files[fileCnt].fileType=folder;
                    waitClose++;
                    folders.push(fileCnt);
                }
                else {
                    files[++fileCnt].fileFather=folders.top();
                    files[folders.top()].fileSon.push_back(fileCnt);
                    files[fileCnt].fileId=fileCnt;
                    files[fileCnt].fileName=str;
                    files[fileCnt].fileState=normal;
                    files[fileCnt].fileType=file;
                    files[fileCnt].fileSize=size;
                }
            }
        }
        if (waitClose==0)
            break;
    }
    string name;
    string op;
    string fileName;
    string INtime;
    bool tp=false;
    bool ne=false;
    int ttime=0;
    for(_time=0;;)
    {
        if(!tp){
            ne=true;
            cin>>INtime;
            if(INtime=="down")
                return 0;
        }
        if(ne)
        {
            ttime=0;
            for(char i : INtime)
                ttime=(ttime<<3)+(ttime<<1)+i-'0';
            ne=false;
        }
        if(ttime!=_time)
        {
            tp=true;
            if(userTotal>=1) runServer();
            else _time=ttime-1;
            _time++;
        }
        if(ttime==_time)
        {
            tp=false;
            cin>>name>>op;
            if(op=="connect")
            {
                int A;
                read(A);
                if(connect(name,A)) py;
                else pn;

            }
            else if(op=="quit")
            {
                if(quit(name)) py;
                else pn;
            }
            else if(op=="cd")
            {
                string folderName;
                cin>>folderName;
                if(cd(name,folderName)) py;
                else pn;
            }
            else if(op=="cd..")
            {
                if(cdBack(name)) py;
                else pn;
            }
            else if(op=="download")
            {
                string _fileName;
                cin>>_fileName;
                if(download(name,_fileName)) py;
                else pn;
            }
            else if(op=="upload")
            {
                string _fileName;
                int _size;
                cin>>_fileName;
                read(_size);
                if(upload(name,_fileName,_size)) py;
                else pn;
            }
        }
    }
}

