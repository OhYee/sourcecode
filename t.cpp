//DataStructure Test
//数据结构
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *name = "Bill";
char *id = "E01010001" ;

//typedef enum{true, false} Status;
//实现KMP算法中的next函数，参考课本pp83：get_next函数
void Next(char T[], int next[])
{
	int i = 1;
	int j = 0;
	next[0] = 0;
	next[1] = 0;
	while(i<strlen(T))
	{
		//请在下面补充代码
		if(j==0||T[i]==T[j]){
			++i;
			++j;
			if(T[i]!=T[j])
				next[i]=j;
			else
				next[i]=next[j]+1;
		}else{
			j=next[j];
		}
	}
}
//KMP字符串匹配算法
int Find(char S[], char T[], int next[])
{
	//S为目标串，n表示目标串长度
	//T为模式串，m表示模式串长度
	//next是Next函数
	//本函数实现在S中查找T,返回T在S中出现的位置。如果没有找到，返回0；
	//注意：串中的一个字符下标从1开始算。下标为0的部分不算。
	//要求使用next实现快速匹配
	//请在下面补充代码
	
	int n = strlen(S) - 1 ;
	int m = strlen(T) - 1 ;
	
	int i=0,j=0;
	while(i<=n && j<=m)
	{
		if(j==0||S[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			j=next[j];
		}
	}

	if(i!=n+1)
	{
		return i-m;
	}
	else
	{
		return 0;
	}
}

int main(int argc,char* argv[])
{
	printf("\n%s, %s\n",name,id);
	int i;
	int score = 0;
	int error = 0;	
	printf("\n================================\n串(共10分)\n");
	char* pat = "1abcaabbabcabaacbacba";
	int next[60];
	Next(pat,next);
	for(i = 1;i<strlen(pat);i++)
	{
		printf("%d",next[i]);
	}
	error = 0;
	if(next[next[5]]!=next[next[6]]) error = 1;
	if(next[next[9]]!=next[next[10]]) error = 1;
	if(next[next[11]]!=next[next[10]]) error = 1;
	if(error==1) printf("错误\n"); else {printf("正确\n");score += 5;}

	error = 0;
	char *S1 = "1abcaaabcaabbabcabaacbacbaabcccabc";
	int index1 = Find(S1,pat,next);
	char *S2 = "1abcaaabcacbbabcabaacbacbaabcccabc";
	int index2 = Find(S2,pat,next);
	if(index1!=6 || index2!=0) error = 1;
	if(error==1) printf("错误\n"); else {printf("正确\n");score += 5;}
	
	printf("\n%s,%s,总分=%d\n\n",name,id,score);
	return 1;
}
