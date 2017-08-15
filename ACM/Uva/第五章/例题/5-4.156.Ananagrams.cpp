#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int read(char s[]){
    char c;
    int i=0;
    while(!(((c=getchar())>='A'&&c<='Z')||(c>='a'&&c<='z')))
        if(c=='#')
            return 0;
    while((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
        s[i++]=c;
        c=getchar();
    }
    s[i]='\0';
    return i;
}

string code(char s[]){
    int i=0;
    char s2[100];
    while(s[i]!='\0'){
        s2[i]=(s[i]>='A'&&s[i]<='Z'?s[i]-'A'+'a':s[i]);
        i++;
    }
    s2[i]='\0';
    sort(s2,s2+strlen(s2));
    return s2;
}

int main(){
    //freopen("in.txt","r",stdin);
    set<string> s;
    set<string>::iterator it;
    map<string,string> m;
    map<string,string>::iterator it_map;

    char str[100];
    while(read(str)){
        string temp=code(str);
        //cout<<str<<"  "<<temp<<endl;
        it_map=m.find(temp);
        if(it_map==m.end()){
            m.insert(pair<string,string>(temp,str));
            s.insert(temp);
        }
        else
            s.erase(temp);
    }

    vector<string> v;
    for(it=s.begin();it!=s.end();it++)
        v.push_back(m.find(*it)->second);
    sort(v.begin(),v.end());

    for(size_t i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    return 0;
}