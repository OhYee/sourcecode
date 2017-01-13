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