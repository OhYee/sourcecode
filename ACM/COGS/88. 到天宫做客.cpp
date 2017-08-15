#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define debug 0
#define REP(n) for(int i=0;i<n;i++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
/*
#############################################################
*/
const int maxn=10000;
int N;
struct Date{
    int Month,Day;
    bool operator < (const Date& rhs)const{
        if(Month<rhs.Month){
            return true;
        }else{
            if(Month>rhs.Month)return false;
            if(Day<rhs.Day){
                return true;
            }else{
                return false;
            }
        }
    }
};
Date date;
const int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int day(Date a,Date b){
    int m=b.Month-a.Month-1;
    int ans=0;
    if(a.Month!=b.Month){
        for(int i=a.Month+1;i<b.Month;i++){
            ans+=month[i];
        }
        ans+=b.Day;
        ans+=month[a.Month]-a.Day;
        return ans-1;
    }else{
        ans=b.Day-a.Day;
        return ans-1;
    }

}

priority_queue<Date>Q;
double reasult=0;

int main(){
    freopen("heaven.in","r",stdin);
    #if !debug
    freopen("heaven.out","w",stdout);
    #endif

    cin>>N;
    if (N==0){
        cout<<86400;
        return 0;
    }
    REP(N){
        int temp1,temp2;
        cin>>temp1>>temp2;
        Q.push((Date){temp1,temp2});
    }
    #if debug
    cout<<"数据读入完毕"<<endl;
    #endif // debug

    Q.push((Date){1,1});
    Q.push((Date){12,32});

    REP(N+1){
        Date d1,d2;
        d1=Q.top();
        Q.pop();
        d2=Q.top();
        reasult=Max(day(d2,d1),reasult);
        #if debug
        cout<<d1.Month<<":"<<d1.Day<<"   "<<d2.Month<<":"<<d2.Day<<"      "<<day(d2,d1)<<endl;
        #endif // debug
    }

    double temp=reasult*43200/183;
    int temp1=(temp-int(temp))*10;
    if(temp1>=5)temp+=1;
    cout<<int(temp);

    return 0;
}
