#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*==============
宏定义部分
==============*/
//兼容较低版本C标准
#define bool int
#define true 1
#define false 0

//各项系数
#define MAXSIZE 15

#define ROOM_NUMBER_SIZE 5

#define ROOM_TAOFANG 0
#define ROOM_DANREN 1
#define ROOM_SHUANGREN 2

#define NAMESIZE 15
#define IDSIZE 15

//兼容低版本C标准并简化循环语句
#define REP(n) for(o=0;o<n;o++)

//比较大小
#define max(a,b) ((a)>(b)?(a):(b))

/*==============
结构体定义
==============*/
typedef struct {
	int year;
	int month;
	int day;
	int hour;
	int minute;
}Time;

typedef struct {
	char Number[ROOM_NUMBER_SIZE];//房间号
	int Type;//房间类型
	int Price;//房间价格
	bool Using;//是否使用中
	char Name[NAMESIZE];//顾客姓名
	char ID[IDSIZE];//顾客身份证
	Time In;//入住时间
	Time Out;//退房时间
	int PreMoney;//预付费用
}Room;

//读入时间
void TimeRead(Time *T) {
	printf("输入时间信息：(年/月/日 小时:分钟)\n");
	rewind(stdin);
	scanf("%d/%d/%d %d:%d",&T->year,&T->month,&T->day,&T->hour,&T->minute);
}
//输出时间
void TimePrint(Time *T) {
	printf("%d/%d/%d %d:%d",T->year,T->month,T->day,T->hour,T->minute);
}
//设置房间信息
void RoomSet(Room *R,char *Number,int Type,int Price,bool Using) {
	strcpy(R->Number,Number);
	R->Type = Type;
	R->Price = Price;
	R->Using = Using;
}
//修改房间信息
void RoomReset(Room *R,bool Using,char *Name = "",char *ID = "",Time *In = NULL,Time *Out = NULL,int PreMoney = 0) {
	R->Using = Using;
	strcpy(R->Name,Name);
	strcpy(R->ID,ID);
	if(In)
		memcpy(&R->In,In,sizeof(In));
	if(Out)
		memcpy(&R->Out,Out,sizeof(Out));
	R->PreMoney = PreMoney;
}
//输出房间信息
void RoomPrint(Room *R) {
	printf("%s\t",R->Number);
	switch(R->Type) {
		case ROOM_TAOFANG:
		printf("套房\t");
		break;
		case ROOM_SHUANGREN:
		printf("双人房\t");
		break;
		case ROOM_DANREN:
		printf("单人房\t");
		break;
		default:
		printf("类型错误\t");
	}
	printf("\t%d\t",R->Price);
	if(R->Using) {
		printf("\t入住\n");
		printf("\t%s\t",R->Name);
		printf("\t%s\t\t",R->ID);
		TimePrint(&R->In);
		printf("\t");
		TimePrint(&R->Out);
		printf("\t");
		printf("%d",R->PreMoney);
	} else {
		printf("\t未入住");
	}
	printf("\n");
}
/*==============
全局变量定义
==============*/

Room room[MAXSIZE];
int o;

//初始化房间
void Init() {
	REP(MAXSIZE) {
		int floor = o / 5 + 1;
		int n = (o) % 5 + 1;
		char Number[ROOM_NUMBER_SIZE];
		int Type;
		int Price;
		bool Using = false;

		Number[0] = floor + '0';
		Number[1] = '0';
		Number[2] = n + '0';
		Number[3] = '\0';

		if(floor == 1) {
			Type = ROOM_DANREN;
			Price = 50;
		}
		if(floor == 2) {
			Type = ROOM_SHUANGREN;
			Price = 70;
		}
		if(floor == 3) {
			Type = ROOM_TAOFANG;
			Price = 100;
		}

		RoomSet(&room[o],Number,Type,Price,Using);
	}
}
//录入客人信息
void PeopleIn(int n,char *Name,char *ID,Time *In,Time *Out,int PreMoney) {
	RoomReset(&room[n],true,Name,ID,In,Out,PreMoney);
}
//客人退房
int PeopleOut(int n) {
	int money = room[n].PreMoney - room[n].Price;
	RoomReset(&room[n],false);
	return money;
}
//按照房间号搜索 返回序号，不存在返回-1
int Search_Room_Number(char *Number) {
	REP(MAXSIZE) {
		if(strcmp(room[o].Number,Number) == 0)
			return o;
	}
	return -1;
}
//按照姓名搜索 返回序号，不存在返回-1
int Search_Room_Name(char *Name) {
	REP(MAXSIZE) {
		if(strcmp(room[o].Name,Name) == 0)
			return o;
	}
	return -1;
}
//搜索房间，不存在返回-1
int Search() {
	char command;
	printf("输入查找的信息(1.按照房间号查找 2.按照顾客姓名查找)：");
	scanf("%c",&command);
	if(command == '1') {
		char Number[ROOM_NUMBER_SIZE];
		printf("\n输入房间号:");
		scanf("%s",Number);
		return Search_Room_Number(Number);
	}
	if(command == '2') {
		char Name[NAMESIZE];
		printf("\n输入顾客姓名:");
		scanf("%s",Name);
		return Search_Room_Name(Name);

	}
	printf("指令有误\n");
	return -1;
}

void UI_PeopleIn() {
	char Number[ROOM_NUMBER_SIZE];
	char Name[NAMESIZE];
	char ID[IDSIZE];
	Time In;
	Time Out;
	int PreMoney;
	int n;
	printf("客人信息录入:\n");
	printf("输入房间号：");
	scanf("%s",Number);
	n = Search_Room_Number(Number);
	if(n == -1) {
		printf("房间不存在\n");
		printf("录入失败\n");
		return;
	}
	if(room[n].Using) {
		printf("房间正在使用中\n");
		printf("录入失败\n");
		return;
	}
	printf("\n输入客人姓名:");
	scanf("%s",Name);
	printf("\n输入客人身份证:");
	scanf("%s",ID);
	printf("\n输入入住时间:");
	TimeRead(&In);
	printf("\n输入退房时间:");
	TimeRead(&Out);
	printf("\n输入预留金额:");
	scanf("%d",&PreMoney);
	PeopleIn(n,Name,ID,&In,&Out,PreMoney);
}
void UI_PeopleOut() {
	int n;
	char Number[ROOM_NUMBER_SIZE];
	int money;
	printf("客人退房:\n");
	printf("输入房间号：");
	scanf("%s",Number);
	n = Search_Room_Number(Number);
	if(n == -1) {
		printf("房间不存在\n");
		printf("退房失败\n");
		return;
	}
	if(!room[n].Using) {
		printf("房间未使用\n");
		printf("退房失败\n");
		return;
	}
	money = PeopleOut(n);
	printf("退房成功，找款%d元\n",money);
}
void UI_Empty() {
	printf("空房情况\n");
	printf("房间号\t房间类型\t房间价格\t是否入住");
	REP(MAXSIZE) {
		if(!room[o].Using)
			RoomPrint(&room[o]);
	}
}

void UI_ShowAll() {
	printf("房间号\t房间类型\t房间价格\t是否入住\n\t(顾客姓名\t顾客身份证\t入住时间\t退房时间\t预付金额)\n");
	REP(MAXSIZE)
		RoomPrint(&room[o]);
}

void UI_Search() {
	int n = Search();
	if(n == -1) {
		printf("错误\n");
	} else {
		printf("房间号\t房间类型\t房间价格\t是否入住\n\t(顾客姓名\t顾客身份证\t入住时间\t退房时间\t预付金额)\n");
		RoomPrint(&room[n]);
	}
}

void UI_Change() {
	int n;
	char Number[ROOM_NUMBER_SIZE];
	int Type;
	int Price;
	printf("修改客房信息：");
	printf("先搜索到要修改的房间:\n");
	n = Search();
	if(n == -1) {
		printf("错误\n");
		return;
	}
	printf("\n输入新的房间号:");
	scanf("%s",Number);
	printf("\n输入新的房间类型(%d.套房 %d.单人间 %d.双人间):",ROOM_TAOFANG,ROOM_DANREN,ROOM_SHUANGREN);
	scanf("%d",&Type);
	printf("\n输入新的房间价格:");
	scanf("%d",&Price);
	RoomSet(&room[o],Number,Type,Price,room[o].Using);
}

bool UI_Menu() {
	char command;
	system("cls");
	printf("1.显示所有房间的信息\n");
	printf("2.客人入住\n");
	printf("3.客人退房\n");
	printf("4.搜索房间\n");
	printf("5.显示空房\n");
	printf("6.修改房间信息\n");
	printf("7.退出\n");
	printf("输入操作:");
	rewind(stdin);
	scanf("%c",&command);
	rewind(stdin);
	system("cls");
	switch(command) {
		case '1':
		UI_ShowAll();
		break;
		case '2':
		UI_PeopleIn();
		break;
		case '3':
		UI_PeopleOut();
		break;
		case '4':
		UI_Search();
		break;
		case '5':
		UI_Empty();
		break;
		case '6':
		UI_Change();
		break;
		case '7':
		return false;
		default:
		printf("错误\n");
	}
	system("pause");
	return true;
}

int main() {
	Init();
	while(UI_Menu());
	return 0;
}



