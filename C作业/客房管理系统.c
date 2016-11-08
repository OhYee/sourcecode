#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*==============
�궨�岿��
==============*/
//���ݽϵͰ汾C��׼
#define bool int
#define true 1
#define false 0

//����ϵ��
#define MAXSIZE 15

#define ROOM_NUMBER_SIZE 5

#define ROOM_TAOFANG 0
#define ROOM_DANREN 1
#define ROOM_SHUANGREN 2

#define NAMESIZE 15
#define IDSIZE 15

//���ݵͰ汾C��׼������ѭ������
#define REP(n) for(o=0;o<n;o++)

//�Ƚϴ�С
#define max(a,b) ((a)>(b)?(a):(b))

/*==============
�ṹ�嶨��
==============*/
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
}Time;

typedef struct {
    char Number[ROOM_NUMBER_SIZE];//������
    int Type;//��������
    int Price;//�����۸�
    bool Using;//�Ƿ�ʹ����
    char Name[NAMESIZE];//�˿�����
    char ID[IDSIZE];//�˿�����֤
    Time In;//��סʱ��
    Time Out;//�˷�ʱ��
    int PreMoney;//Ԥ������
}Room;

//����ʱ��
void TimeRead(Time *T) {
    printf("����ʱ����Ϣ��(��/��/�� Сʱ:����)\n");
    rewind(stdin);
    scanf("%d/%d/%d %d:%d",&T->year,&T->month,&T->day,&T->hour,&T->minute);
}
//����ʱ��
void TimePrint(Time *T) {
    printf("%d/%d/%d %d:%d",T->year,T->month,T->day,T->hour,T->minute);
}
//���÷�����Ϣ
void RoomSet(Room *R,char *Number,int Type,int Price,bool Using) {
    strcpy(R->Number,Number);
    R->Type = Type;
    R->Price = Price;
    R->Using = Using;
}
//�޸ķ�����Ϣ
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
//����������Ϣ
void RoomPrint(Room *R) {
    printf("%s\t",R->Number);
    switch(R->Type) {
        case ROOM_TAOFANG:
        printf("�׷�\t");
        break;
        case ROOM_SHUANGREN:
        printf("˫�˷�\t");
        break;
        case ROOM_DANREN:
        printf("���˷�\t");
        break;
        default:
        printf("���ʹ���\t");
    }
    printf("\t%d\t",R->Price);
    if(R->Using) {
        printf("\t��ס\n");
        printf("\t%s\t",R->Name);
        printf("\t%s\t\t",R->ID);
        TimePrint(&R->In);
        printf("\t");
        TimePrint(&R->Out);
        printf("\t");
        printf("%d",R->PreMoney);
    } else {
        printf("\tδ��ס");
    }
    printf("\n");
}
/*==============
ȫ�ֱ�������
==============*/

Room room[MAXSIZE];
int o;

//��ʼ������
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
//¼��������Ϣ
void PeopleIn(int n,char *Name,char *ID,Time *In,Time *Out,int PreMoney) {
    RoomReset(&room[n],true,Name,ID,In,Out,PreMoney);
}
//�����˷�
int PeopleOut(int n) {
    int money = room[n].PreMoney - room[n].Price;
    RoomReset(&room[n],false);
    return money;
}
//���շ��������� �������ţ������ڷ���-1
int Search_Room_Number(char *Number) {
    REP(MAXSIZE) {
        if(strcmp(room[o].Number,Number) == 0)
            return o;
    }
    return -1;
}
//������������ �������ţ������ڷ���-1
int Search_Room_Name(char *Name) {
    REP(MAXSIZE) {
        if(strcmp(room[o].Name,Name) == 0)
            return o;
    }
    return -1;
}
//�������䣬�����ڷ���-1
int Search() {
    char command;
    printf("�������ҵ���Ϣ(1.���շ����Ų��� 2.���չ˿���������)��");
    scanf("%c",&command);
    if(command == '1') {
        char Number[ROOM_NUMBER_SIZE];
        printf("\n���뷿����:");
        scanf("%s",Number);
        return Search_Room_Number(Number);
    }
    if(command == '2') {
        char Name[NAMESIZE];
        printf("\n�����˿�����:");
        scanf("%s",Name);
        return Search_Room_Name(Name);

    }
    printf("ָ������\n");
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
    printf("������Ϣ¼��:\n");
    printf("���뷿���ţ�");
    scanf("%s",Number);
    n = Search_Room_Number(Number);
    if(n == -1) {
        printf("���䲻����\n");
        printf("¼��ʧ��\n");
        return;
    }
    if(room[n].Using) {
        printf("��������ʹ����\n");
        printf("¼��ʧ��\n");
        return;
    }
    printf("\n������������:");
    scanf("%s",Name);
    printf("\n������������֤:");
    scanf("%s",ID);
    printf("\n������סʱ��:");
    TimeRead(&In);
    printf("\n�����˷�ʱ��:");
    TimeRead(&Out);
    printf("\n����Ԥ������:");
    scanf("%d",&PreMoney);
    PeopleIn(n,Name,ID,&In,&Out,PreMoney);
}
void UI_PeopleOut() {
    int n;
    char Number[ROOM_NUMBER_SIZE];
    int money;
    printf("�����˷�:\n");
    printf("���뷿���ţ�");
    scanf("%s",Number);
    n = Search_Room_Number(Number);
    if(n == -1) {
        printf("���䲻����\n");
        printf("�˷�ʧ��\n");
        return;
    }
    if(!room[n].Using) {
        printf("����δʹ��\n");
        printf("�˷�ʧ��\n");
        return;
    }
    money = PeopleOut(n);
    printf("�˷��ɹ����ҿ�%dԪ\n",money);
}
void UI_Empty() {
    printf("�շ�����\n");
    printf("������\t��������\t�����۸�\t�Ƿ���ס");
    REP(MAXSIZE) {
        if(!room[o].Using)
            RoomPrint(&room[o]);
    }
}

void UI_ShowAll() {
    printf("������\t��������\t�����۸�\t�Ƿ���ס\n\t(�˿�����\t�˿�����֤\t��סʱ��\t�˷�ʱ��\tԤ������)\n");
    REP(MAXSIZE)
        RoomPrint(&room[o]);
}

void UI_Search() {
    int n = Search();
    if(n == -1) {
        printf("����\n");
    } else {
        printf("������\t��������\t�����۸�\t�Ƿ���ס\n\t(�˿�����\t�˿�����֤\t��סʱ��\t�˷�ʱ��\tԤ������)\n");
        RoomPrint(&room[n]);
    }
}

void UI_Change() {
    int n;
    char Number[ROOM_NUMBER_SIZE];
    int Type;
    int Price;
    printf("�޸Ŀͷ���Ϣ��");
    printf("��������Ҫ�޸ĵķ���:\n");
    n = Search();
    if(n == -1) {
        printf("����\n");
        return;
    }
    printf("\n�����µķ�����:");
    scanf("%s",Number);
    printf("\n�����µķ�������(%d.�׷� %d.���˼� %d.˫�˼�):",ROOM_TAOFANG,ROOM_DANREN,ROOM_SHUANGREN);
    scanf("%d",&Type);
    printf("\n�����µķ����۸�:");
    scanf("%d",&Price);
    RoomSet(&room[o],Number,Type,Price,room[o].Using);
}

bool UI_Menu() {
    char command;
    system("cls");
    printf("1.��ʾ���з�������Ϣ\n");
    printf("2.������ס\n");
    printf("3.�����˷�\n");
    printf("4.��������\n");
    printf("5.��ʾ�շ�\n");
    printf("6.�޸ķ�����Ϣ\n");
    printf("7.�˳�\n");
    printf("��������:");
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
        printf("����\n");
    }
    system("pause");
    return true;
}

int main() {
    Init();
    while(UI_Menu());
    return 0;
}



