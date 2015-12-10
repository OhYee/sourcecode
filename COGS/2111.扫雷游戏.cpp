/*
            By:OhYee
            Email:oyohyee@oyohyee.com
            QQ:896817156

*/

/*
                                    !                              !!
                                                           !!!!!!!!!!
                                                         !!!!     !
                                   ! !                    !!II!!!  !!
                       !!      !!!!   !!!!!!!!              !!IIIII!!
                  !              !!!!!!!!!       !!IILLLLLII! !!!!III!
               !!!!!!!!   !    !!!          !! !LOLLLLIII!!I!   !   !I
               !!I!!!!     !!!!         !!!! !LLI!ILLOOLLI
               !I!!!                        LOI    LVVVO!LVI
             ! !!!!                      ! LV!     LVVVVOLI!!!!!!!!!
            !! !!! !!!!!!!                 IO   IOOVVVOI!  !!!!!!!!!
              !!                            !    !IIII!    !!!!!!!!
                !!!!!!!!!!!!!!!!!!!!
                !!!!!!!!!!!!
               !!!                                                  !
               !!!                                          !!!!
                !!            !!!!!!           !!!       !IOVVVVOOLI!
                !!  !!      !LVVLI!                    ! !VVVVVOOOOLLI
                !!! !      !VVL!IILII                !!  OVVOLLIIIIIII
               !! !       !VV!IVEEEVLLI                IVVVLIIIIIIIIII
                !!!!      LV! !!LEEVIOL             !LOVVVLIIIIIIIIIII
                 !!!!     OV    IVVOVL              IVVVVOIIIIIIIIIIII
                   III    OV! !OVVOOO   !!!!        !IOVVVLIIIIIIIIIII
                    !II!! !VVI  !III! !!!!!!!          ILOOLIIIIIILLI!
                      !!! !!LOL!                          !!!!!I!!!!!

            Ÿt§§°°ø…ê€§§°°•®•Í•¡•´
            BUGÕÀ…¢
            •È•÷•È•§•÷°°LOVELIVE!
*/


//#######################################################################

#include <cstdio>
using namespace std;

const int maxn=105;
int n,m;
int map[maxn][maxn];
char temp;

int main(){
  freopen("2015mine.in","r",stdin);
  freopen("2015mine.out","w",stdout);

  scanf("%d%d",&n,&m);
  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
      map[i][j]=0;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("\n%c",&temp);
      //printf("\n (%d,%d) %c",i,j,temp);
      if(temp=='*'){
        map[i][j]=-99;
        for(int x=-1;x<=1;x++){
          for(int y=-1;y<=1;y++){
            if(!(x==0&&y==0)){
              //printf("(%d,%d)",i+x,j+y);
              map[i+x][j+y]++;
            }
          }
        }
       }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%c",map[i][j]<0?'*':(char)(map[i][j]+'0'));
    }
    printf("\n");
  }

  return 0; 
}