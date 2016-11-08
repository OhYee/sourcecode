#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

//枚举类型
enum Result {
    WIN,
    TIE,
    LOST
};
enum Type {
    HOME,
    AWAY
};

//类声明
struct Date;
class Game;
class Team;
typedef list<Game>::iterator Data;

//数据库
list<Game> GameDatabase;
list<Team> TeamDatabase;

//函数声明
list<Team>::iterator GetTeam(string Name);
list<Team>::iterator GetTeam2(string Name);
list<Team>::iterator UI_ChooseTeam();
int dequals(double a,double b);
bool Input(istream &in);
void _Input(string Home,string Away,int HomeScore,int AwayScore,Date Time);
void Draw(double *s);
void Read();
void Write();
void UI_Input();
void UI_ShowMonth();
void UI_ShowSort();
void UI_ShowScore();
void UI_ShowGraph();
bool UI_Menu();
int main();

struct Date {
    int Month;
    int Day;
    Date(int Month = 1,int Day = 1) {
        this->Month = Month;
        this->Day = Day;
    }
    bool operator < (const Date &rhs)const {
        if(Month == rhs.Month)
            return Day < rhs.Day;
        else
            return Month < rhs.Month;
    }
};
class Game {
private:
    string Home;
    string Away;
    int HomeScore;
    int AwayScore;
    Date Time;
public:
    //记录比赛信息
    Game(string Home,string Away,int HomeScore,int AwayScore,Date Time) {
        this->Home = Home;
        this->Away = Away;
        this->HomeScore = HomeScore;
        this->AwayScore = AwayScore;
        this->Time = Time;
    }
    Date GetDate() {
        return Time;
    }
    int GetScore(string name) {
        if(Home == name)
            return HomeScore;
        else
            return AwayScore;
    }
    void Output(ostream &out) {
        out << Home << "\t" << Away << "\t" << HomeScore << "\t" << AwayScore << "\t" << Time.Month << "\t" << Time.Day << endl;
    }
};
class Team {
private:
    string Name;
    int HomeScore;
    int AwayScore;
    int Win;
    int Tie;
    int Lost;
    list<Data> Database;
public:
    Team(string Name) {
        this->Name = Name;
        HomeScore = 0;
        AwayScore = 0;
        Win = 0;
        Tie = 0;
        Lost = 0;
    }
    bool operator < (const Team &rhs)const {
        return HomeScore + AwayScore > rhs.HomeScore + rhs.AwayScore;
    }
    int GetTotolScore() {
        return HomeScore + AwayScore;
    }
    string GetName() {
        return Name;
    }
    void Show() {
        cout << Name << "\t" << GetTotolScore() << "\t" << Win << "\t" << Tie << "\t" << Lost << endl;
    }
    void ShowMonth(int month) {
        list<Data>::iterator it = Database.begin();
        while(it != Database.end()) {
            if((*it)->GetDate().Month == month)
                (*it)->Output(cout);
            it++;
        }
    }
    void ShowScore() {
        cout << HomeScore << "\t" << AwayScore << endl;
    }
    void ShowGraph() {
        double s[12];
        memset(s,0,sizeof(s));
        list<Data>::iterator it = Database.begin();
        while(it != Database.end()) {
            s[(*it)->GetDate().Month-1] += (*it)->GetScore(Name);
            it++;
        }
        Draw(s);
        
    }
    void WriteGame(int Score,Result result,Type type,Data data) {
        if(type == HOME)
            HomeScore += Score;
        else
            AwayScore += Score;


        if(result == WIN)
            Win++;
        else if(result == TIE)
            Tie++;
        else
            Lost++;


        list<Data>::iterator it = Database.begin();
        while(it != Database.end()) {
            if(data->GetDate() < (*it)->GetDate())
                break;
            it++;
        }
        Database.insert(it,data);
    }
};



//函数
list<Team>::iterator GetTeam(string Name) {
    list<Team>::iterator it = TeamDatabase.begin();
    while(it != TeamDatabase.end()) {
        if(it->GetName() == Name)
            break;
        it++;
    }
    if(it == TeamDatabase.end()) {
        TeamDatabase.push_front(Team(Name));
        it = TeamDatabase.begin();
    }
    return it;
}
list<Team>::iterator GetTeam2(string Name) {
    list<Team>::iterator it = TeamDatabase.begin();
    while(it != TeamDatabase.end()) {
        if(it->GetName() == Name)
            break;
        it++;
    }
    return it;
}
void _Input(string Home,string Away,int HomeScore,int AwayScore,Date Time) {
    Data it_Game;
    list<Team>::iterator it_Team;

    //写入数据库
    GameDatabase.push_front(Game(Home,Away,HomeScore,AwayScore,Time));
    it_Game = GameDatabase.begin();

    //队伍写入
    //主场
    Result res;
    if(HomeScore == AwayScore)
        res = TIE;
    else if(HomeScore > AwayScore)
        res = WIN;
    else
        res = LOST;

    it_Team = GetTeam(Home);
    it_Team->WriteGame(HomeScore,res,HOME,it_Game);
    //客场
    if(res != TIE) {
        if(res == WIN)
            res = LOST;
        else
            res = WIN;
    }
    it_Team = GetTeam(Away);
    it_Team->WriteGame(AwayScore,res,AWAY,it_Game);
}
bool Input(istream &in) {
    string Home;
    string Away;
    int HomeScore;
    int AwayScore;
    Date Time;

    if(!(in >> Home >> Away >> HomeScore >> AwayScore >> Time.Month >> Time.Day))
        return false;

    _Input(Home,Away,HomeScore,AwayScore,Time);
    return true;
}
void Read() {
    ifstream f("Database.db");
    while(Input(f));
    f.close();
}
void Write() {
    ofstream f("Database.db");
    list<Game>::iterator it_Game = GameDatabase.begin();
    while(it_Game != GameDatabase.end()) {
        it_Game->Output(f);
        it_Game++;
    }
    f.close();
}
int dequals(double a,double b) {
    return fabs(a - b) < 0.000001;
}
void Draw(double *s) {
    const int height = 20;

    int Max = 0;
    for(int i = 0;i < 12;i++)
        Max = max(Max,(int)(s[i] + 0.5));
    for(int i = 0;i < 12;i++)
        s[i] /= Max;

    for(int i = height;i >= 0;i--) {
        printf("%.1f\t\t",(double)Max * i / height);
        for(int j = 0;j < 12;j++) {
            if(dequals(s[j],(double)i / height))
                putchar('*');
            else
                putchar(' ');
            putchar('\t');
        }
        putchar('\n');
    }
    putchar('\t');
    putchar('\t');
    for(int j = 0;j < 12;j++)
        cout << j + 1 << "\t";

    putchar('\n');

}

//UI函数
list<Team>::iterator UI_ChooseTeam() {
    cout << "Input the name of the team." << endl;
    string name;
    cin >> name;
    list<Team>::iterator it = GetTeam2(name);
    return it;
}
void UI_Input() {
    cout << "Input the information of the games" << endl;
    cout << "Input according the form below:" << endl;
    cout << "The name of the home team" << endl;
    cout << "The name of the away team" << endl;
    cout << "The score of the home team" << endl;
    cout << "The score of the away team" << endl;
    cout << "The date of the game" << endl;
    Input(cin);
    cout << "Success!" << endl;
}
void UI_ShowMonth() {
    list<Team>::iterator it = UI_ChooseTeam();
    if(it == TeamDatabase.end()) {
        cout << "Wrong!!" << endl;
        return;
    }

    cout << "Input the month." << endl;
    int month;
    cin >> month;

    cout << "Home\tAway\tHScore\tAScore\tMonth\tDay\n";
    it->ShowMonth(month);
}
void UI_ShowSort() {
    TeamDatabase.sort();
    list<Team>::iterator it = TeamDatabase.begin();
    int Rank = 1;
    cout << "Rank    Name    Score    Win    Tie    Lost" << endl;
    while(it != TeamDatabase.end()) {
        cout << Rank++ << "\t";
        it->Show();
        it++;
    }
}
void UI_ShowScore() {
    list<Team>::iterator it = UI_ChooseTeam();
    if(it == TeamDatabase.end()) {
        cout << "Wrong!!" << endl;
        return;
    }
    cout << "HScore\tAScore\n";
    it->ShowScore();
}
void UI_ShowGraph() {
    list<Team>::iterator it = UI_ChooseTeam();
    if(it == TeamDatabase.end()) {
        cout << "Wrong!!" << endl;
        return;
    }
    it->ShowGraph();
}
bool UI_Menu() {
    char command;
    system("cls");
    printf("1.Input the game\n");
    printf("2.Show the team that sorted with score\n");
    printf("3.Show the team in month\n");
    printf("4.Show the team's score\n");
    printf("5.Show the graph\n");
    printf("6.Exit\n");
    printf("Please input:");
    rewind(stdin);
    scanf("%c",&command);
    rewind(stdin);
    system("cls");
    switch(command) {
        case '1':
        UI_Input();
        break;
        case '2':
        UI_ShowSort();
        break;
        case '3':
        UI_ShowMonth();
        break;
        case '4':
        UI_ShowScore();
        break;
        case '5':
        UI_ShowGraph();
        break;
        case '6':
        return false;
        default:
        printf("Wrong\n");
    }
    system("pause");
    return true;
}

int main() {
    system("mode con cols=120 lines=30  ");
    Read();
    while(UI_Menu());
    Write();
    return 0;
}