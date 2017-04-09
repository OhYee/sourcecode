//*/
#define debug
#include <ctime>
//*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 10000 * 50 + 5;

//AC自动机
struct Node{
    char ch;
    int failed;
    int parent;
    int children[26];
    int end;
    Node(char _ch = 0, int _parent = -1){
        ch = _ch;
        failed = 0;
        parent = _parent;
        memset(children,0,sizeof(children));
        end = 0;
    }
};
Node Tree[maxn];
int pos;
void init(){
    Tree[pos=0] = Node();
}
void push(string s){
    size_t size = s.size();
    int p = 0;
    for(size_t i=0;i<size;i++){
        if(!Tree[p].children[s[i]-'a']){
            Tree[p].children[s[i]-'a'] = ++pos; //插入新节点
            Tree[pos] = Node(s[i],p);           //初始化
        }
        p = Tree[p].children[s[i]-'a'];
    }
    Tree[p].end++;
}
void make_failed(){
    queue<int> Q;
    while(!Q.empty())
        Q.pop();
    
    Q.push(0);
    while(!Q.empty()){
        int t = Q.front();
        Q.pop();

        int iter = Tree[Tree[t].parent].failed;
        do{
            int cousin = Tree[iter].children[Tree[t].ch-'a'];
            if(cousin && cousin != t){
                //存在相同的字符并且不是本身
                Tree[t].failed = cousin;
                break;
            }else{
                iter = Tree[Tree[iter].parent].failed;
            }
        }while(iter);

        for(int i=0;i<26;i++)
            if(Tree[t].children[i])
                Q.push(Tree[t].children[i]);
    }
}
string show_word(int p){
    string s="";
    stack<char> stk;
    while(!stk.empty())stk.pop();
    while(p){
        stk.push(Tree[p].ch);
        p = Tree[p].parent;
    }
    while(!stk.empty()){
        s += stk.top();
        stk.pop();
    }
    return s;
}

int solve(string s){
    int ans = 0;
    int size = s.size();
    int T_iter = 0;   //树
    int S_iter = 0;   //字符串
    while(S_iter<=size){
        if(Tree[T_iter].children[s[S_iter]-'a']){
            //匹配成功
            T_iter = Tree[T_iter].children[s[S_iter]-'a'];
            S_iter++; 
        }else{
            //匹配失败   
            if(!T_iter)
                S_iter++;
            T_iter = Tree[T_iter].failed;
        }
        ans+=Tree[T_iter].end;
    }
    return ans;
}

int main(){
    #ifdef debug
    freopen("in.txt", "r", stdin);
    int START = clock();
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--){
        init();
        int n;
        cin >> n;
        string s;
        for(int i=0;i<n;i++){
            cin >> s;
            push(s);
        }
        make_failed();
        cin >> s;
        cout << solve(s) << endl;
    }

    #ifdef debug
    printf("Time:%.3fs.\n", double(clock() - START) / CLOCKS_PER_SEC);
    #endif
    return 0;
}

