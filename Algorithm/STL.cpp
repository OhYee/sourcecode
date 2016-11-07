#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

int main(){

    cout<<"vector����"<<endl;
    vector<int> vec;//��������Ϊvec������������
    vector<int>::iterator it_vec;//������
    vec.clear();//����
    cout<<"��������"<<endl;
    vec.push_back(1);//��ĩβ����
    vec.push_back(3);
    it_vec=vec.end();//ָ��vec��ĩβ
    it_vec--;//��ǰ�ƶ�һλ����1��3���м䣩
    vec.insert(it_vec,2);//�ڴ˴�����2
    REP(vec.size())cout<<vec[o]<<endl;//��������
    cout<<"������һ�����ݺ�����"<<endl;
    vec.erase(vec.begin());
    it_vec=vec.begin();
    REP(vec.size()){
        cout<<*it_vec<<endl;//��������
        it_vec++;//����һλ
    }
    cout<<"#####################################"<<endl<<endl;


    cout<<"map����"<<endl;
    map<string,vector<int> > m;//���� key������Ϊstring value����Ϊint��vector �� ӳ��m
    map<string,vector<int> >::iterator it_map;//������
    cout<<"��������"<<endl;
    m.insert(pair<string,vector<int> >("aaa",vec));
    it_map=m.find("aaa");//����ָ��key��λ�ã���������
    cout<<"key:"<<it_map->first<<endl;
    cout<<"value:"<<endl;
    REP(vec.size())cout<<"   "<<vec[o]<<endl;
    cout<<"����һ�������ڵ����� find()�᷵��map��ĩβ"<<endl;
    it_map=m.find("Niconiconi~");
    if(it_map==m.end())cout<<"No Niconiconi~"<<endl;
    cout<<"#####################################"<<endl<<endl;

    cout<<"set����"<<endl;
    set<int> s;//����һ�������ͼ���
    set<int>::iterator it_set;//������
    cout<<"�����������ݲ������ظ���4"<<endl;
    s.insert(5);
    s.insert(4);
    s.insert(4);
    s.insert(2);
    s.insert(1);
    it_set=s.begin();
    while(it_set!=s.end()){
        cout<<*it_set<<endl;
        it_set++;
    }
    cout<<"����ʱ4�Զ�����һ��������������С��������"<<endl;
    cout<<"#####################################"<<endl<<endl;



    cout<<"queue����"<<endl;
    queue<string> q;//����һ���ַ����Ͷ��� q
    cout<<"��˳������"<<endl;
    q.push("L");
    q.push("O");
    q.push("V");
    q.push("E");
    q.push("L");
    q.push("I");
    q.push("V");
    q.push("E");
    q.push("!");
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    cout<<endl;
    cout<<"�����ӵ��ȳ���"<<endl;
    cout<<"#################################"<<endl<<endl;



    cout<<"priority_queue����"<<endl;
    priority_queue<string> pq;//����priority_queueһ���ַ��������ȶ���
    cout<<"�����������пɱȽϴ�С������"<<endl;
    pq.push("B");
    pq.push("A");
    pq.push("C");
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    cout<<endl;
    cout<<"Ȩֵ�����ȳ���"<<endl;
    cout<<"###############################"<<endl<<endl;

    cout<<"stack����"<<endl;
    stack<string> sta;//����һ���ַ������͵�ջ
    cout<<"������������"<<endl;
    sta.push("+");
    sta.push("+");
    sta.push("C");
        while(!sta.empty()){
        cout<<sta.top();
        sta.pop();
    }
    cout<<endl;
    cout<<"�Ƚ����ĺ�����"<<endl;
    return 0;
}


