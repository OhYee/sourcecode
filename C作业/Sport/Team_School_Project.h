#pragma once

#include <map>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;

const int SCORE[2][6] = {{0,7,5,3,2,1},{0,5,3,2,0,0}};

class Team;
class School;
class Project;

typedef list<Team>::iterator    ptrTeam;
typedef list<School>::iterator    ptrSchool;
typedef list<Project>::iterator    ptrProject;

list<Team>        TeamList;
list<School>    SchoolList;
list<Project>    ProjectList;

map<string,int> SchoolNameToNumber;
map<int,string> SchoolNumberToName;
map<string,int> ProjectNameToNumber;
map<int,string> ProjectNumberToName;

class Team {
private:
    //��project��Ŀ���õ�Grade����SchoolѧУ��male�ı���ΪNumber��
    int Number;
    ptrSchool School;
    ptrProject Project;
    int Grade;

public:
    Team(int,int,int);
    int GetScore();//������֧С�ӵķ���
    bool isMale();//�����Ƿ����ж�
    void Delete();//ɾ��������Ϣ
    bool operator == (const int n)const;

    static bool NewTeam(int num,string name) {
        if(hasSchool(num))
            return false;
        SchoolList.push_back(School(num,name));

        SchoolNumberToName.insert(make_pair(num,name));
        SchoolNameToNumber.insert(make_pair(name,num));

        return true;
    }
};
class School {
private:
    //����Ϊ Number ����Ϊ Name �� Team ������ѧУ
    int Number;
    string Name;

public:
    list<ptrTeam> Team;

    School(int,string);
    int GetScore();//��ȡ��ѧУ�ܷ�
    void Delete();//ɾ��ѧУ
    bool operator == (const int)const;//�жϱ����Ƿ���ͬ

                                     //����һ��ѧУ��ָ��
    inline static ptrSchool SearchSchool(int num) {
        ptrSchool it;
        it = find(SchoolList.begin(),SchoolList.end(),num);
        return it;
    }

    //�ж�һ��ѧУ�Ƿ��Ѵ���
    inline static bool hasSchool(int num) {
        return !!SchoolNumberToName.count(num);
    }

    //�½�һ��ѧУ
    static bool NewSchool(int num,string name) {
        if(hasSchool(num))
            return false;
        SchoolList.push_back(School(num,name));

        SchoolNumberToName.insert(make_pair(num,name));
        SchoolNameToNumber.insert(make_pair(name,num));

        return true;
    }

    //ɾ��һ��ѧУ
    static bool DeleteSchool(int num) {
        ptrSchool itSchool = SearchSchool(num);
        if(itSchool == SchoolList.end())
            return false;

        itSchool->Delete();

        return true;
    }
};
class Project {
private:
    //����Ϊ Number ����Ϊ Name �� Three �� Male ���������������� Team
    int Number;
    string Name;
    bool Three;
    bool Male;


public:
    list<ptrTeam> Team;

    Project(int,string,bool,bool);
    bool isMale();
    int GetScore(int);//��ȡ���� grade �Ķ��������������еĵ÷�
    void Delete();//ɾ����Ŀ
    bool operator == (const int)const;//�жϱ����Ƿ���ͬ

    //����һ����Ŀ��ָ��
    inline static ptrProject SearchProject(int num) {
        ptrProject it;
        it = find(ProjectList.begin(),ProjectList.end(),num);
        return it;
    }

    //�ж�һ����Ŀ�Ƿ��Ѵ���
    inline static bool hasProject(int num) {
        return !!ProjectNumberToName.count(num);
    }

    //�½�һ����Ŀ
    static bool NewProject(int num,string name,bool Three,bool Male) {
        if(hasProject(num))
            return false;
        ProjectList.push_back(Project(num,name,Three,Male));

        ProjectNumberToName.insert(make_pair(num,name));
        ProjectNameToNumber.insert(make_pair(name,num));

        return true;
    }

    //ɾ��һ����Ŀ
    static bool DeleteProject(int num) {
        ptrProject itProject = SearchProject(num);
        if(itProject == ProjectList.end())
            return false;

        itProject->Delete();

        return true;
    }
};

//============================================
//================= Team =====================
//============================================

Team::Team(int SchoolNumber,int ProjectNumber,int Grade) {
    School = School::SearchSchool(SchoolNumber);
    Project = Project::SearchProject(ProjectNumber);
    this->Grade = Grade;
}

//������֧С�ӵķ���
int Team::GetScore() {
    return Project->GetScore(Grade);
}

//�����Ƿ����ж�
bool Team::isMale() {
    return Project->isMale();
}

//ɾ��������Ϣ
void Team::Delete() {
    list<ptrTeam>::iterator itTeam;
    ptrTeam itTeam2 = find(TeamList.begin(),TeamList.end(),Number);

    //ɾ����Ӧ��Ŀ���ö�����¼
    itTeam = find(Project->Team.begin(),Project->Team.end(),itTeam2);
    Project->Team.erase(itTeam);
    //ɾ����ӦѧУ���ö�����¼
    itTeam = find(School->Team.begin(),School->Team.end(),itTeam2);
    School->Team.erase(itTeam);

    TeamList.erase(itTeam2);
}

bool Team::operator == (const int n)const {
    return Number == n;
}

//============================================
//================ School ====================
//============================================

School::School(int number,string name) {
    this->Number = number;
    this->Name = name;
    this->Team.clear();
}

//��ȡ��ѧУ�ܷ�
int School::GetScore() {
    int sum = 0;

    list<ptrTeam>::iterator it = Team.begin();
    while(it != Team.end()) {
        sum += (*it)->GetScore();
        it++;
    }

    return sum;
}

//ɾ��ѧУ
void School::Delete() {
    list<ptrTeam>::iterator itTeam = Team.begin(),itTeam2;
    while(itTeam != Team.end()) {
        itTeam2 = itTeam++;//��ֹ��Team��ɾ������������School���б����µ������޷�����
        (*itTeam2)->Delete();
    }

    SchoolNumberToName.erase(Number);
    SchoolNameToNumber.erase(Name);

    ptrSchool itSchool = SearchSchool(Number);
    SchoolList.erase(itSchool);
}

//�жϱ����Ƿ���ͬ
bool School::operator == (const int n)const {
    return n == Number;
}


//============================================
//================ Project ===================
//============================================

Project::Project(int number,string name,bool Three,bool Male) {
    this->Number = number;
    this->Name = name;
    this->Three = Three;
    this->Male = Male;
    this->Team.clear();
}

bool Project::isMale() {
    return Male;
}

//��ȡ���� grade �Ķ��������������еĵ÷�
int Project::GetScore(int grade) {
    return SCORE[Three][grade];
}

//ɾ����Ŀ
void Project::Delete() {
    list<ptrTeam>::iterator itTeam = Team.begin(),itTeam2;
    while(itTeam != Team.end()) {
        itTeam2 = itTeam++;//��ֹ��Team��ɾ������������Project���б����µ������޷�����
        (*itTeam2)->Delete();
    }

    ProjectNumberToName.erase(Number);
    ProjectNameToNumber.erase(Name);

    ptrProject itProject = SearchProject(Number);
    ProjectList.erase(itProject);
}

//�жϱ����Ƿ���ͬ
bool Project::operator == (const int n)const {
    return n == Number;
}