#include <cstdio>
using namespace std;

#define REP(n) for(int o;o<n;o++)

char map[5][5];
int kase=0;

void Do();
void Exchange(char &a,char &b);

int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while((map[0][0]=getchar())!='Z'){
		Do();
		while(getchar()!='\n');
	}
	return 0;
}

void Do(){
	//printf("%c\n",map[0][0]);
	int x=0,y=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i==0&&j==0)continue;
			scanf("%c",&map[i][j]);
			if(map[i][j]==' '){
				x=i;
				y=j;
			}
		}
		getchar();
	}

	/*
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}
	*/


	printf("Puzzle #%d:\n",++kase);
	char c;
	while((c=getchar())!='0'){
		if(c=='A'){//Above
			if(x==0){
				printf("This puzzle has no final configuration.\n\n");
				return;
			}
			Exchange(map[x][y],map[x-1][y]);
			x--;
		}
		if(c=='B'){//Below
			if(x==4){
				printf("This puzzle has no final configuration.\n\n");
				return;
			}
			Exchange(map[x][y],map[x+1][y]);
			x++;
		}
		if(c=='L'){//Left
			if(y==0){
				printf("This puzzle has no final configuration.\n\n");
				return;
			}
			Exchange(map[x][y],map[x][y-1]);
			y--;
		}
		if(c=='R'){//Above
			if(y==4){
				printf("This puzzle has no final configuration.\n\n");
				return;
			}
			Exchange(map[x][y],map[x][y+1]);
			y++;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Exchange(char &a,char &b){
	char c;
	c=a;
	a=b;
	b=c;
}