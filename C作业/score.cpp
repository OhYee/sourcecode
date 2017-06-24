#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSE_NUMBER 5
#define MAX_STUDENT_NUMBER 32
#define COURSE_NAME_LENGTH 20
#define STUDENT_NAME_LENGTH 20
#define STUDENT_ID_LENGTH 20

using namespace std;

struct COURSE {
    char name[COURSE_NAME_LENGTH];
    int score;
    COURSE() { score = 0; }
};

struct STUDENT {
  public:
    char name[STUDENT_NAME_LENGTH];
    int id;
    COURSE course[MAX_COURSE_NUMBER];
    //大外1,大外2,电分,VB,C

    STUDENT() {
        strcpy(course[0].name, "大学外语1");
        strcpy(course[1].name, "大学外语2");
        strcpy(course[2].name, "电路分析");
        strcpy(course[3].name, "VB程序设计");
        strcpy(course[4].name, "C程序设计");
    }
    double getavg() {
        double sum = 0;
        for (int i = 0; i < MAX_COURSE_NUMBER; i++)
            sum += course[i].score;
        return sum / MAX_COURSE_NUMBER;
    }
    void show() {
        printf("%s\t%d", name, id);
        for (int i = 0; i < MAX_COURSE_NUMBER; i++)
            printf("\t%s(%d)", course[i].name, course[i].score);
        printf("\t%.2f\n", getavg());
    }
};

//选择排序
void Swap(STUDENT &a,STUDENT &b) {
    STUDENT temp;
    memcpy(&temp,&a,sizeof(a));
    memcpy(&a,&b,sizeof(b));
    memcpy(&b,&temp,sizeof(temp));
}
void SelectSort(STUDENT a[],int n) {
    for(int i = 0;i < n - 1;i++) {
        STUDENT Min;
        memcpy(&Min,&a[i+1],sizeof(Min));
        int pos = i + 1;
        for(int j = i;j < n;j++) {
            if(Min.id > a[j].id) {
                memcpy(&Min,&a[j],sizeof(Min));
                pos = j;
            }
        }
        Swap(a[i],a[pos]);
    }
}
int lower_bound(STUDENT *arr, int size, int key) {
    int half;
    int mid;
    int first = 0;
    while (size > 0) {
        half = size >> 1;
        mid = first + half;
        if (arr[mid].id < key) {
            first = mid + 1;
            size = size - half - 1;
        } else {
            size = half;
        }
    }
    return first;
}

STUDENT student_list[MAX_STUDENT_NUMBER];
int student_num;

void Init() { student_num = 0; }

bool Insert(char *_name, int _id) {
    if (student_num == MAX_STUDENT_NUMBER)
        return false;
    strcpy(student_list[student_num].name, _name);
    student_list[student_num].id = _id;
    student_num++;
    SelectSort(student_list, student_num);
    return true;
}

int SearchStudent(int _id) {
    int pos = lower_bound(student_list, student_num, _id);
    if (pos == student_num)
        return -1;
    else
        return pos;
}

bool Del(int _id) {
    int pos = SearchStudent(_id);
    if (pos == -1)
        return false;
    student_num--;
    for (int i = pos; i < student_num; i++)
        memcpy(&student_list[i], &student_list[i + 1], sizeof(student_list[i]));
    return true;
}

void setScore(int _pos, int Cour, int score) {
    student_list[_pos].course[Cour].score = score;
}

void showAll() {
    for (int i = 0; i < student_num; i++) {
        student_list[i].show();
    }
}

int main() {
    char s[100];
    int id, k, score;
    while (1) {
        scanf("%s",s);
        if (s[0] == 'i') {
            scanf("%s%d", s, &id);
            printf("%d\n", Insert(s, id));
        } else if (s[0] == 'd') {
            scanf("%d", &id);
            printf("%d\n", Del(id));
        } else if (s[0] == 's') {
            scanf("%d%d%d", &id, &k, &score);
            printf("%d\n", id = SearchStudent(id));
            if (id) {
                setScore(id, k, score);
            }
        } else if (s[0] == 'a') {
            showAll();
        }
    }

    return 0;
}
