#include <cstdio>
#include <cstring>
int main(){
	char c[10]="\17\08";

	for(int i=0;i<10;i++)
		printf("%d %d %c\n",i, c[i],c[i]);
	printf("%s\n",c);
	printf("\n%d",strlen("\18\08"));
	printf("\n%d",strlen("\18"));
	printf("\n%d",strlen("\1"));
	printf("\n");
	printf("\41");
	printf("\18");
}