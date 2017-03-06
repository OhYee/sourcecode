#include <cstdio>
#include <io.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

const int WEEK = 6;
const int COURSE = 11;

string TimeTable[WEEK+1][COURSE+1];

struct Time{
    int week;
    int time;
};
struct Student{
    string name;

};

//获取目录下所有文件
void getFiles(string path, vector<string>& files )  {  
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  {  
        do{  
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if((fileinfo.attrib &  _A_SUBDIR)){
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    getFiles(p.assign(path).append("\\").append(fileinfo.name),files);  
            }else{
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}

//从目录里读入所有的课表信息
void ReadFromFile(string Path){
    ifstream f(Path);
    int a,b;
    while(f >> a >> b){

    }
}
void ReadInfo(){
    char filePath[] = "..\\info"; 
    vector<string> files;  
    getFiles(filePath,files);

    int size = files.size();
    for(int i=0;i<size;i++){
        ReadFromFile(files[i]);
    }
}

int main() {
    char filePath[] = "I:\\Portable\\Code"; 
    vector<string> files;  
    getFiles(filePath,files);  
    

    char str[30];  
    int size = files.size();  
    for (int i = 0;i < size;i++){  
        cout<<files[i].c_str()<<endl;  
    }  
    return 0; 
}