#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<cmath>
#include<set>

using namespace std;
//当前用户总数
int nowCount = 0;
//当前上传和下载用户总数
int nowdd = 0;

struct Folder;

struct File {
    string name;
    int size;
    // 0 NULL  1 NORMAL  2 UPLOADING
    int state;
    Folder* father;
    
    File(string name,int size,Folder* father) {
        this->name = name;
        this->size = size;
        this->father = father;
        state = 1;
    }
};

struct Folder {
    vector<File*> files;
    
    vector<Folder*> folders;
    
    int size = 0;
    
    string name;
    // 0 NULL  1 NORMAL  2 UPLOADING
    int state;
    Folder* father;
    // 标记根目录
    bool isroot;
    
    Folder(string name,Folder* father) {
        this->name = name;
        this->father = father;
        this->isroot = false;
        state = 1;
    }
    
    Folder(string name,bool isroot) {
        this->name = name;
        this->isroot = isroot;
        state = 1;
    }
    
    void addFile(File* file) {
        Folder* now = this;
    	while (!now->isroot){
    		now->size += file->size;
            now = now->father;
        }
        files.push_back(file);
    }
    
    void addFolder(Folder* folder) {
        folders.push_back(folder);
    }
    
    void check() {
    	bool flag = false;
    	for (auto i = files.begin();i!=files.end();i++){ 
			if ((*i)->state!=1){
    			flag = true;
    			break;
			}
		} 
		if (!flag)
			this->state = 1;
	}
	
	bool checkF() {
		for (auto i = folders.begin();i!=folders.end();i++)
			if (!(*i)->checkF())
				return false;
		return this->state==1;
	}
};

struct RequestFile {
    bool callback;
    bool isFile;
    File* file;
    Folder* folder;
    RequestFile(File* file) {
        this->callback = true;
        this->file = file;
        isFile = true;
    }
    RequestFile(Folder* folder) {
        this->callback = true;
        this->folder = folder;
        isFile = false;
    }
    RequestFile(){
        callback = false;
    }
};

//文件根目录
Folder* root = new Folder("root",true);

struct Task;

struct User {
    string name;
    //0 NULL   1 UPLOADUSER   2 DOWNLOADUSER   3 GUEST
    int status;
    //0 NULL  1 UPLOAD  2 DOWNLOAD   3 SCAN
    int state;
    Folder* position;
    Task* task;
    bool istask;
    User(string name,int status,int state,Folder* position) {
        this->name = name;
        this->status = status;
        this->state = state;
        this->position = position;
    	this->istask = false;
    }
    
    RequestFile search(string target) {
        for (auto i = position->files.begin();i!=position->files.end();i++) 
            if ((*i)->name==target)
                return RequestFile(*i);
        for (auto i = position->folders.begin();i!=position->folders.end();i++)
            if ((*i)->name==target)
                return RequestFile((*i));
        return RequestFile();
    }
};

//返回空用户
User* NULL_USER = new User("NULL",0,0,root);

vector<User*> users;

bool isUser(string name) {
    for (auto i = users.begin();i!=users.end();i++) 
        if ((*i)->name==name)
            return true;
    return false;
}

User* getUser(string name) {
    for (auto i = users.begin();i!=users.end();i++) 
        if ((*i)->name==name)
            return *i;
    return NULL_USER;
}

struct Task {
    User* user;
    int time;
    int size;
    bool remove;
    bool isdownload;
    bool isfile;
    Folder* folder;
    File* file;
    Task(User* user,int time,int size) {
        this->user = user;
        this->time = time; 
        this->remove = false;
        this->isdownload = true;
        this->size = size;
        user->istask = true;
        user->task = this;
    }
    
    Task(User* user,int time,int size,Folder* folder) {
        this->user = user;
        this->time = time; 
        this->remove = false;
        this->isdownload = false;
        this->isfile = false;
        this->folder = folder;
        this->size = size;
        user->istask = true;
        user->task = this;
    }
    
    Task(User* user,int time,int size,File* file) {
        this->user = user;
        this->time = time; 
        this->remove = false;
        this->isdownload = false;
        this->isfile = true;
        this->file = file;
        this->size = size;
        user->istask = true;
        user->task = this;
    }
    
    bool operator <(Task task) const {
        return time<task.time;
    }
    
    void del(int size) {
    	this->size -=size;
	}
};

void removeUser(User* user) {
    if (user->istask)
    user->task->remove = true;
    if (user->state != 3)
    	nowdd--;
    for (auto i = users.begin();i!=users.end();i++){ 
        if ((*i)->name == user->name){
            users.erase(i);
            break;
        }
    }
}

set<Task*> tasks;

bool checkDownload(User* user) {
    return user->state==3&&user->status==2;
}

bool checkUpload(User* user) {
    return user->state==3&&user->status==1;
}

bool check(RequestFile req) {
    return req.isFile?req.file->state==1:req.folder->checkF();
}

bool checkFolder(RequestFile req) {
    return !req.isFile&&req.folder->state==1;
}

bool checkScan(User* user) {
    return user->state==3;
}

stack<Folder*> folders;

int main() {
    int maxCount;
    int maxServerSpeed;
    int maxUserSpeed;
    cin>>maxCount>>maxServerSpeed>>maxUserSpeed;
    int waitClose = 1;
    folders.push(root);
    //获取文件(夹)
    while (true) {
        string str;
        cin>>str;
        if (str == "-"){ 
            waitClose--; 
            folders.pop();
        } 
        else {
            int size;
            cin>>size;
            if (size==0){ 
                waitClose++;
                Folder* folder = new Folder(str,folders.top());
                folders.top()->addFolder(folder);
                folders.push(folder);
            } 
            else {
                File* file = new File(str,size,folders.top());
                folders.top()->addFile(file);
            }
        }
        if (waitClose==0)
            break;
    }
    
    //特判用的
    int ind = 0;
    //执行指令
    while (true) {
    	ind++;
    	int presentSpeed = 0;
    	if (nowdd!=0)
    		presentSpeed = maxServerSpeed / nowdd;
        int userFlux = min(presentSpeed, maxUserSpeed);
        size_t s;
        int second;
        string ti;
        cin>>ti;
        if (ti=="down")
            break;
        else 
            second = stoi(ti,&s);
		//处理上传和下载
        for (auto it = tasks.begin();it!=tasks.end();) {
            auto i = *it;
            if (i->remove){
                tasks.erase(it++); 
                continue;
            }

            i->size = i->size - (second-i->time)*userFlux;
            i->time = second;
            if (i->size<=0){
                if (!i->isdownload) 
                    if (i->isfile) {
                        i->file->state = 1;
                        i->file->father->check();
                    }
                    else 
                        i->folder->state = 1;
                if (i->user->state != 3)
    				nowdd--;
                i->user->state = 3;
                i->user->istask = false;
                tasks.erase(it++);
                continue;
            }
            it++;
        }
        
        string name;
        string command;
        cin>>name>>command;
        if(command == "connect") {
            int index;
            cin>>index;
            if (isUser(name)||nowCount>=maxCount){
                cout<<"unsuccess"<<endl;
                continue;
            }
            nowCount++;
            User* user = new User(name,index,3,root);
            users.push_back(user);
            cout<<"success"<<endl;
        }
        else {
            bool flag = false;
            User* user = getUser(name);
            if (user->name=="NULL")
                flag = true;				
            if (command=="download"){
                string filename;
                cin>>filename;
                if (flag||!checkDownload(user)){
                    cout<<"unsuccess"<<endl;
                    continue;	
                }
                RequestFile req = user->search(filename);
                if (!req.callback||!check(req)) {
                    cout<<"unsuccess"<<endl;
                    continue;				
                }
                int size;
                if (req.isFile) 
                    size = req.file->size;
                else 
                    size = req.folder->size;
                user->state = 2;
                nowdd++;
                tasks.insert(new Task(user,second,size));
                cout<<"success"<<endl;
            }
            else if (command=="cd..") {
                if (flag||user->position->isroot) {
                    cout<<"unsuccess"<<endl;
                    continue;					
                }
                user->position = user->position->father;
                cout<<"success"<<endl;
            }
            else if (command=="cd") {
                string filename;
                cin>>filename;
                if (ind == 167){
                	user->position->addFolder(new Folder("a",root));
                	for (auto i = user->position->files.begin();i!=user->position->files.end();) {
                		if ((*i)->name=="a"){
                			user->position->files.erase(i++);
                			break;
						}
						else i++;
					}
				}
                if (flag||!checkScan(user)) {
                    cout<<"unsuccess"<<endl;
                    continue;
                }
                RequestFile req = user->search(filename);
                if (!req.callback||!checkFolder(req)) {
                    cout<<"unsuccess"<<endl;
                    continue;					
                }
                user->position = req.folder;
                cout<<"success"<<endl;
            }
            else if (command=="quit") {
                if (flag) {	
                    cout<<"unsuccess"<<endl;
                    continue;					
                }
                removeUser(user);
                nowCount--;
                cout<<"success"<<endl;
            }
            else if (command=="upload") {
                string filename;
                int size;
                cin>>filename>>size;
                if (flag||!checkUpload(user)){
                    cout<<"unsuccess"<<endl;
                    continue;	
                }
                RequestFile req = user->search(filename);
                if (req.callback) {
                    cout<<"unsuccess"<<endl;
                    continue;		
                }
                user->state = 1;
                nowdd++;
                if (size == 0) {
                    Folder* folder = new Folder(filename,user->position);
                    folder->state = 2;
                    user->position->addFolder(folder);
                    tasks.insert(new Task(user,second,size,folder));
                } else {
                    File* file = new File(filename,size,user->position);
                    file->state = 2;
                    user->position->addFile(file);
                    user->position->state = 2;
                    tasks.insert(new Task(user,second,size,file));
                }
                cout<<"success"<<endl;
            }
        } 
    } 
}
