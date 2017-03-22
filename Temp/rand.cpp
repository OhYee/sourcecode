//随机排序

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm >
using namespace std;

const int maxn = 1000000;

//随机生成 0~n-1 的随机数
int random(int n){
    return rand() % n;
}

struct Node{
    string name;
    int n;
    Node(string a){
        name = a;
    }
    void Random(){
        n = random(maxn);
    }
    bool operator < (const Node &rhs)const{
        return n < rhs.n;
    }
};

vector<Node> List;

int main(){
    srand((int)time(NULL));

    List.clear();
    freopen("list.txt","r",stdin);

    string name;
    while(cin >> name){
        List.push_back(name);
    }

    int size = List.size();

    for(int i=0;i<size;i++)
        List[i].Random();
    sort(List.begin(),List.end());
    for(int i=0;i<size;i++)
        cout << i << ":" <<List[i].name << endl;

    
    return 0;
}