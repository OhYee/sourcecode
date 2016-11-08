#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define Max 100
#define I_want_to_konw for(double j=-5;j<5;j+=0.5)
#define Do_you_love_me for(double i=-6;i<5;i+=0.25)
#define You_Love_Me (17*pow(i,2)+16*abs(i)*j+17*pow(j,2)<=225)
#define I_Love_You printf("*")
#define I_Still_Love_You printf(" ")
#define Then printf("\n")
#define My_heart 0
;

class LOVE{
    private:
        static const int Likeability=Max;
    public:
        void Show_My_Love(){
            I_want_to_konw{
                Do_you_love_me{
                    if(You_Love_Me){
                        I_Love_You;
                    }else{
                        I_Still_Love_You;
                    }
                }
                Then;
            }
        }
};

int main(){
    LOVE CX;
    CX.Show_My_Love();
    return My_heart;
}