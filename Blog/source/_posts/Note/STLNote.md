---
title: STL笔记
date: 2015-07-27 17:22:00
tags:
- 映射(map)
- 集合(set)
- 队列(queue)
- 栈(stack)
- 向量(vector)
categories: 笔记
---

## STL方面的笔记 
以下为vector queue map set stack的基本用法 
可编译结合注释查看

<!--more-->

``` cpp
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define REP(n) for(int o=0;o<n;o++)

int main(){

    cout<<"vector功能"<<endl;
    vector<int> vec;//声明名称为vec的整数型向量
    vector<int>::iterator it_vec;//迭代器
    vec.clear();//清空
    cout<<"插入数据"<<endl;
    vec.push_back(1);//在末尾插入
    vec.push_back(3);
    it_vec=vec.end();//指向vec的末尾
    it_vec--;//向前移动一位（既1和3的中间）
    vec.insert(it_vec,2);//在此处插入2
    REP(vec.size())cout<<vec[o]<<endl;//访问数据
    cout<<"清除第一个数据后输出"<<endl;
    vec.erase(vec.begin());
    it_vec=vec.begin();
    REP(vec.size()){
        cout<<*it_vec<<endl;//访问数据
        it_vec++;//向后一位
    }
    cout<<"#####################################"<<endl<<endl;


    cout<<"map功能"<<endl;
    map<string,vector<int> > m;//声明 key的类型为string value类型为int型vector 的 映射m
    map<string,vector<int> >::iterator it_map;//迭代器
    cout<<"插入数据"<<endl;
    m.insert(pair<string,vector<int> >("aaa",vec));
    it_map=m.find("aaa");//或者指定key的位置（迭代器）
    cout<<"key:"<<it_map->first<<endl;
    cout<<"value:"<<endl;
    REP(vec.size())cout<<"   "<<vec[o]<<endl;
    cout<<"查找一个不存在的数据 find()会返回map的末尾"<<endl;
    it_map=m.find("Niconiconi~");
    if(it_map==m.end())cout<<"No Niconiconi~"<<endl;
    cout<<"#####################################"<<endl<<endl;

    cout<<"set功能"<<endl;
    set<int> s;//声明一个整数型集合
    set<int>::iterator it_set;//迭代器
    cout<<"倒叙插入数据并且有重复的4"<<endl;
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
    cout<<"输出时4自动保留一个，并且数据由小到大输出"<<endl;
    cout<<"#####################################"<<endl<<endl;



    cout<<"queue功能"<<endl;
    queue<string> q;//声明一个字符串型队列 q
    cout<<"按顺序插入"<<endl;
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
    cout<<"先入队的先出来"<<endl;
    cout<<"#################################"<<endl<<endl;



    cout<<"priority_queue功能"<<endl;
    priority_queue<string> pq;//声明priority_queue一个字符串型优先队列
    cout<<"乱序插入具有可比较大小的数据"<<endl;
    pq.push("B");
    pq.push("A");
    pq.push("C");
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    cout<<endl;
    cout<<"权值大的先出来"<<endl;
    cout<<"###############################"<<endl<<endl;

    cout<<"stack功能"<<endl;
    stack<string> sta;//声明一个字符串类型的栈
    cout<<"倒序插入数据"<<endl;
    sta.push("+");
    sta.push("+");
    sta.push("C");
        while(!sta.empty()){
        cout<<sta.top();
        sta.pop();
    }
    cout<<endl;
    cout<<"先进入的后出来"<<endl;
    return 0;
}
```

编译结果
    vector功能 
    插入数据 
    1 
    2 
    3 
    清除第一个数据后输出 
    2 
    3

    #
    map功能 
    插入数据 
    key:aaa 
    value: 
    2 
    3 
    查找一个不存在的数据 find()会返回map的末尾 
    No Niconiconi~

    #
    set功能 
    倒叙插入数据并且有重复的4 
    1 
    2 
    4 
    5 
    输出时4自动保留一个，并且数据由小到大输出

    #
    queue功能 
    按顺序插入 
    LOVELIVE! 
    先入队的先出来

    #
    priority_queue功能 
    乱序插入具有可比较大小的数据 
    CBA 
    权值大的先出来

    #
    stack功能 
    倒序插入数据 
    C++ 
    先进入的后出来
 