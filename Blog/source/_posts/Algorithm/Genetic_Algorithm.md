---
title: 遗传算法解决TSP问题
date: 2016-12-25 14:58:37
tags: 
- 遗传算法
- TSP
categories: 算法
---
写了下遗传算法的TSP问题  

要求如下:
> * N>=8。
> * 随即生成N个城市间的连接矩阵。
> * 指定起始城市。
> * 给出每一代的最优路线和总路线长度。
> * 以代数T作为结束条件，T>=50。

<br>

> 巡回旅行商问题
> 给定一组n个城市和俩俩之间的直达距离，寻找一条闭合的旅程，使得每个城市刚好经过一次且总的旅行距离最短。
> TSP问题也称为货郎担问题，是一个古老的问题。最早可以追溯到1759年Euler提出的骑士旅行的问题。1948年，由美国兰德公司推动，TSP成为近代组合优化领域的典型难题。

<!--more-->

----


# 遗传算法  

遗传算法大概就是用自然进化中的生物来模拟数据,寻找最优解的一种算法.  
根据生物知识可以知道进化的原因是 **物竞天择,适者生存**  

生物基因会不停地进行变异,有的变异适合环境被保留下来,有的不适合环境被抛弃掉.  
这个过程会不断筛选生物个体,最终导致种群里留存的都是最适合环境的个体  

需要明确的是,遗传算法是完全随机的,很有可能无法找到 **最优解** 但是在运算范围内,能够找到的必然是一个非常好的解  
因此遗传算法是一个很好兼顾了时间和准确率的算法(运算范围选取合理的情况下,可以认为找到的就是最优解)  

例如 TSP问题,将解看成每个生物个体.  
我们的任务就是在题目要求的环境里找到最适宜的生物个体  

每一个个体都是一个解,例如染色体为 `123456` 的个体表示按照 "1 - 2 - 3 - 4 - 5 - 6 - 1" 的顺序访问所有城市  

要判断哪一个更加适宜环境,就需要一个函数进行计算.  
因此要定义一个适应度函数来计算每一个染色体对于环境的适应度情况.  
对于TSP问题而言,就是计算当前解的距离和  

生物的进化需要个体的繁衍、变异  
将两个生物体的染色体片段(基因)进行交叉互换(交换个别片段)可以得到一个新的生物个体,这个个体可能会优于其父母,也有可能劣于其父母.子代可能会发生变异,产生一个全新的染色体.  
因此可采用随机数的方法模拟染色体的交叉互换和变异.  
使用一个函数来判断某个生物体是否会被消灭(随机出不合法的染色体)  
每代都把最适合环境的个体留下来(包括父代的个体),这样迭代下去,找到的结果会越来越接近最优解  

要找到最优解,首先要确保能够尽可能广的覆盖到各种基因组合(染色体),然后要让种群数量尽可能大(以防由于最优解的一部分适应度较低直接被舍弃掉),繁衍代数尽可能高  

# 实现旅行商问题  

对于 n 个城市的TSP问题,记录城市编号 `0` ~ `n-1`   
然后用 n 个连续数字记录访问顺序(数组存储),如 `(1)(2)(3)(4)(5)` 表示 `1 - 2 - 3 - 4 - 5 - 1`  

首先初始化祖宗染色体,交配需要两个个体,因此我们可以分别正序和逆序生成两个祖宗个体.  
然后循环 T 代,每一代让种群里的个体两两结合交叉互换,插入到种群里.  
接着对每一个个体进行基因突变(按照一定得突变概率),突变后个体如果能够存活就把它插入到种群里.  
最后按照种群适应度排序,只留下前面的一部分个体.  
这样就完成了一代的生物进化.  

关于各部分的实现,根据 TSP 问题,可以采用以下办法  

- 交叉互换
  取染色体的随机片段,两段片段分别映射并交换,然后对于每个染色体的未交换部分按照映射更改  
> 例如，对下面两个父个体的表示，随机地选择两个交叉点“/”
>   P1：（1 2 3 / 4 5 6 7 / 8 9）  P2：（4 5 2 / 1 8 7 6 / 9 3）
> 首先，两个交叉点之间的中间段交换，得到：
>   o1：（x x x / 1 8 7 6 / x x）  o2：（x x x / 4 5 6 7 / x x ）
> 其中x表示暂时未定义码，得到中间段的映射关系。，有：
>   1----4，8----5，7----6，6----7
> 对子个体1，2中的x部分，分别保留从其父个体中继承未选定城市码，得到
>   o1：（ x 2 3 / 1 8 7 6 / x 9 ）   o2：（ x x 2 / 4 5 6 7 / 9 3 ） 
> 最后，根据中间段的映射关系，对于上面子个体1的第一个x，使用最初父码1，由1----4
交换得到第一个x为4，类似地子个体1的第二个x，使用最初父码8，由8----5交换得到子个体1的第二个x为5。类似地进行操作，最终得到的子个体为：
>   o1：（ 4 2 3 / 1 8 7 6 / 5 9 ）  o2：（ 1 8 2 / 4 5 6 7 / 9 3 ）
- 基因突变
  随机取两个基因,交换他们的值
- 适应度
  计算相邻基因的距离(如果相同则逐位比较大小,确保相同的相邻)  
- 适者生存
  种群排序后,去除掉相同的个体,然后删除掉超出最大种群个数的个体  
  其中,删除重复个体可以采用如下代码  
  ```cpp 删除重复个体
  sort(P.begin(),P.end());
  P.erase(unique(P.begin(),P.end()),P.end());
  ```


# 完整代码
```cpp 遗传算法解决TSP问题
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100;
const double eps = 1e-10; //浮点误差

/* ================= */
int N;                             //城市数量
int M;                             //开始城市
int Distance[maxn][maxn];          //各城市之间的距离
int T = 100;                        //循环代数
unsigned int P_SIZE = 50;          //种群大小
double Mutation_Probability = 0.6;   //变异的概率

//随机
//生成0~n的随机数
int Random(int n) {
    if(n == 0)
        return 0;
    else
        return rand() % (n + 1);
}
//生成概率
double Probability() {
    double ans = (double)Random(100) / 100.0;
    //cout << ans << endl;
    return ans;
}

//适应度
//计算一条染色体的适应度 距离越短,适应度越高
int Fitness(int *gene) {
    int dis = Distance[gene[N - 1]][gene[0]];
    for(int i = 0; i < N - 1; i++)
        dis += Distance[gene[i]][gene[i + 1]];
    return dis;
}

//长度为N个基因的染色体
struct Chromosome {
    int *Gene;      //基因序列
    int fitness; //该染色体的适应度

    Chromosome(int *gene = NULL) {
        Gene = new int[N];
        if(gene != NULL) {
            memcpy(Gene,gene,sizeof(int) * N);
            fitness = Fitness(Gene);

            //cout << "New Chromosome ";
            //p();

        }
    }

    bool operator<(const Chromosome &rhs) const { //适应度好的保留下来
        if(fitness == rhs.fitness)
            for(int i = 0;i < N;i++)
                if(Gene[i] != rhs.Gene[i])
                    return Gene[i]<rhs.Gene[i];
        return fitness < rhs.fitness;
    }
    bool operator==(const Chromosome &rhs)const {
        return memcmp(Gene,rhs.Gene,sizeof(int)*N)==0;
    }
    //变异 返回变异后的染色体
    Chromosome Mutation() {
        //随机交换两个基因
        int t1 = Random(N - 1);
        int t2 = Random(N - 1);
        int *gene = new int[N];
        memcpy(gene,Gene,sizeof(int)*N);
        swap(gene[t1],gene[t2]);
        Chromosome Chrom = Chromosome(gene);
        delete gene;
        //cout << "Mutation" << endl;
        //p();
        //Chrom.p();
        return Chrom;
    }
    //交叉 交叉两个染色体
    static void Crossover(Chromosome chrom1,Chromosome chrom2,
        Chromosome &child1,Chromosome &child2) {
        // 选取交叉区间 0 [1-x) [x,y] (y,N-1]
        int y = Random(N - 1) + 1;
        int x = Random(y - 1) + 1;
        //cout << "[0,0] [1," << x << ") [" << x << "," << y << "] (" << y << "," << N - 1 << "]" << endl;
        int *gene1 = new int[N];
        int *gene2 = new int[N];
        memcpy(gene1,chrom1.Gene,sizeof(int)*N);
        memcpy(gene2,chrom2.Gene,sizeof(int)*N);

        map<int,int> m1;
        map<int,int> m2;
        for(int i = x; i <= y; i++) {
            m1.insert(make_pair(gene1[i],gene2[i]));
            m1.insert(make_pair(gene2[i],gene1[i]));
            int temp = gene1[i];
            gene1[i] = gene2[i];
            gene2[i] = temp;
        }

        for(int i = 0; i <= N - 1; i++) {
            if(i < x || i > y) {
                if(m2.count(gene1[i]))
                    gene1[i] = m2[gene1[i]];
                if(m1.count(gene2[i]))
                    gene2[i] = m1[gene2[i]];
            }
        }

        child1 = Chromosome(gene1);
        child2 = Chromosome(gene2);
        delete gene1;
        delete gene2;

        //cout << "Crossover:" << endl;
        //chrom1.p();
        //chrom2.p();
        //child1.p();
        //child2.p();
        //cout << endl;
    }
    //该个体是否能存活
    bool Alive() {
        if(Gene[0] != M)
            return false;
        bool *flag = new bool[N];
        memset(flag,false,sizeof(bool)*N);
        for(int i = 0; i < N; i++)
            if(flag[Gene[i]])
                return false;
            else
                flag[Gene[i]] = true;
        delete flag;
        return true;
    }

    //输出
    void p() {
        for(int i = 0; i < N; i++) {
            cout << Gene[i] << " ";
        }
        cout << ": " << " Dis:"<<fitness<<endl;
    }
};

//初始化
void Init() {
    srand((int)time(NULL));
}

Chromosome GA() {
    //初始化
    Init();
    vector<Chromosome> P; //种群
    P.clear();

    //生成初始种群(两个祖宗)
    int *gene = new int[N];

    for(int i = 0; i < N; i++)
        gene[i] = i;
    swap(gene[M],gene[0]);
    P.push_back(Chromosome(gene));

    for(int i = 0; i < N; i++)
        gene[i] = N - i - 1;
    swap(gene[N - M - 1],gene[0]);
    P.push_back(Chromosome(gene));

    sort(P.begin(),P.end());

    for(int i = 0; i <= T; i++) {
        //第i代
        cout << "T:" << i << endl;

        //输出该代信息
        int size = P.size();
        for(int j = 0; j < size; j++)
            P[j].p();

        cout << "Output finish" << endl;

        if(i!=T){
            //本代个体交配
            for(int x = 0; x < size; x++)
                for(int y = x + 1; y < size; y++) {
                    Chromosome child1;
                    Chromosome child2;
                    Chromosome::Crossover(P[x],P[y],child1,child2);
                    if(child1.Alive())
                        P.push_back(child1);
                    if(child2.Alive())
                        P.push_back(child2);
                }

            cout << "Crossover Finish" << endl;

            //变异
            size = P.size();
            for(int x = 0; x < size; x++) {
                if(Probability() <= eps + Mutation_Probability) {
                    Chromosome temp;
                    temp = P[x].Mutation();
                    if(temp.Alive() )
                        P.push_back(temp);
                }
            }

            //适者生存
            sort(P.begin(),P.end());
            P.erase(unique(P.begin(),P.end()),P.end());

            if(P.size() > P_SIZE)
                cout << "Kill " << P.size() - P_SIZE << endl;
            while(P.size() > P_SIZE)
                P.pop_back();

            cout << endl;
        }
    }
    delete gene;

    return P[0];
}

int main() {
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    /*
    Sample Input
    3
    0
    0 17 81
    17 0 62
    81 62 0

    8
    3
    0  17 81 21 43 12 56 76
    17 0  62 22 67 45 78 13
    81 62 0  98 11 65 27 62 
    21 22 98 0  27 88 52 18
    43 67 11 27 0  76 13 72
    12 45 65 88 76 0  47 33
    56 78 27 52 13 47 0  11
    76 13 62 18 72 33 11 0
    */
    cout << "Input the number of the cities:";
    cin >> N;
    cout << "Input the begin city(0~n-1):";
    cin >> M;
    cout << "Input the distance between two city(include city x with x):"
        << endl;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> Distance[i][j];

    cout << "Distance:" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << Distance[i][j] << " ";
        cout << endl;
    }

    Chromosome Chrom = GA();
    cout << "The best answer is:";
    for(int i = 0; i < N; i++) {
        cout << Chrom.Gene[i] << " ";
    }
    int dis = Distance[Chrom.Gene[N - 1]][Chrom.Gene[0]];
    for(int i = 0; i < N - 1; i++)
        dis += Distance[Chrom.Gene[i]][Chrom.Gene[i + 1]];
    cout << "  Distance: " << dis << endl;
    return 0;
}   
```