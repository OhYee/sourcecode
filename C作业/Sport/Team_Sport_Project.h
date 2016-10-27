#pragma once

#include <list>
#include <map>
#include <cstring>
using namespace std;

const int SCORE[2][6] = {{0,7,5,3,2,1},{0,5,3,2,0,0}};

class Team;
class School;
class Project;

typedef list<Team>::iterator	ptrTeam;
typedef list<School>::iterator	ptrSchool;
typedef list<Project>::iterator	ptrProject;

list<Team>		TeamList;
list<School>	SchoolList;
list<Project>	ProjectList;

map<string,int> SchoolNameToNumber;
map<int,string> SchoolNumberToName;
map<string,int> ProjectNameToNumber;
map<int,string> ProjectNumberToName;

class Team {
private:
	//在project项目获得第Grade名的School学校的male的编号为Number队
	int Number;
	ptrSchool School;
	ptrProject Project;
	int Grade;

public:
	Team(int,int,int);
	int GetScore();//获得这支小队的分数
	bool isMale();//返回是否是男队
	void Delete();//删除队伍信息
	bool operator == (const int n)const;
};
class School {
private:
	//编号为 Number 名称为 Name 有 Team 队伍的学校
	int Number;
	string Name;

public:
	list<ptrTeam> Team;

	School(int,string);
	int GetScore();//获取该学校总分
	void Delete();//删除学校
	bool operator == (const int)const;//判断编号是否相同

									 //返回一个学校的指针
	inline static ptrSchool SearchSchool(int num) {
		ptrSchool it;
		it = find(SchoolList.begin(),SchoolList.end(),num);
		return it;
	}

	//判断一个学校是否已存在
	inline static bool hasSchool(int num) {
		return !!SchoolNumberToName.count(num);
	}

	//新建一个学校
	static bool NewSchool(int num,string name) {
		if(hasSchool(num))
			return false;
		SchoolList.push_back(School(num,name));

		SchoolNumberToName.insert(make_pair(num,name));
		SchoolNameToNumber.insert(make_pair(name,num));

		return true;
	}

	//删除一个学校
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
	//编号为 Number 名称为 Name 的 Three 人 Male 比赛，参赛队伍有 Team
	int Number;
	string Name;
	bool Three;
	bool Male;


public:
	list<ptrTeam> Team;

	Project(int,string,bool,bool);
	bool isMale();
	int GetScore(int);//获取排名 grade 的队伍在这项比赛中的得分
	void Delete();//删除项目
	bool operator == (const int)const;//判断编号是否相同

	//返回一个项目的指针
	inline static ptrProject SearchProject(int num) {
		ptrProject it;
		it = find(ProjectList.begin(),ProjectList.end(),num);
		return it;
	}

	//判断一个项目是否已存在
	inline static bool hasProject(int num) {
		return !!ProjectNumberToName.count(num);
	}

	//新建一个项目
	static bool NewProject(int num,string name,bool Three,bool Male) {
		if(hasProject(num))
			return false;
		ProjectList.push_back(Project(num,name,Three,Male));

		ProjectNumberToName.insert(make_pair(num,name));
		ProjectNameToNumber.insert(make_pair(name,num));

		return true;
	}

	//删除一个项目
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

//获得这支小队的分数
int Team::GetScore() {
	return Project->GetScore(Grade);
}

//返回是否是男队
bool Team::isMale() {
	return Project->isMale();
}

//删除队伍信息
void Team::Delete() {
	list<ptrTeam>::iterator itTeam;
	ptrTeam itTeam2 = find(TeamList.begin(),TeamList.end(),Number);

	//删除对应项目里该队伍记录
	itTeam = find(Project->Team.begin(),Project->Team.end(),itTeam2);
	Project->Team.erase(itTeam);
	//删除对应学校里该队伍记录
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

//获取该学校总分
int School::GetScore() {
	int sum = 0;

	list<ptrTeam>::iterator it = Team.begin();
	while(it != Team.end()) {
		sum += (*it)->GetScore();
		it++;
	}

	return sum;
}

//删除学校
void School::Delete() {
	list<ptrTeam>::iterator itTeam = Team.begin(),itTeam2;
	while(itTeam != Team.end()) {
		itTeam2 = itTeam++;//防止在Team的删除函数里清除School的列表导致迭代器无法后移
		(*itTeam2)->Delete();
	}

	SchoolNumberToName.erase(Number);
	SchoolNameToNumber.erase(Name);

	ptrSchool itSchool = SearchSchool(Number);
	SchoolList.erase(itSchool);
}

//判断编号是否相同
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

//获取排名 grade 的队伍在这项比赛中的得分
int Project::GetScore(int grade) {
	return SCORE[Three][grade];
}

//删除项目
void Project::Delete() {
	list<ptrTeam>::iterator itTeam = Team.begin(),itTeam2;
	while(itTeam != Team.end()) {
		itTeam2 = itTeam++;//防止在Team的删除函数里清除Project的列表导致迭代器无法后移
		(*itTeam2)->Delete();
	}

	ProjectNumberToName.erase(Number);
	ProjectNameToNumber.erase(Name);

	ptrProject itProject = SearchProject(Number);
	ProjectList.erase(itProject);
}

//判断编号是否相同
bool Project::operator == (const int n)const {
	return n == Number;
}