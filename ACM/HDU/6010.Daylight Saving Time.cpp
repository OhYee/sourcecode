#include <cstdio>
#include <cstring>
using namespace std;

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sunday[105][15][35];
void Sunday() {
    memset(sunday, 0, sizeof(sunday));
    int year = 2007;
    int month = 1;
    int day = 7;
    int cnt = 0;
    while (year <= 2100) {
        sunday[year - 2000][month][day] = ++cnt;
        //  printf("%4d-%2d-%2d %d\n", year, month, day,
        //         sunday[year - 2000][month][day]);
        day += 7;

        if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) &&
            month == 2) {
            if ((day > 29)) {
                day -= days[month++] + 1;
                cnt = 0;
            }
        } else {
            if (day > days[month]) {
                day -= days[month++];
                cnt = 0;
            }
        }

        if (month == 13) {
            month = 1;
            ++year;
        }
    }
}

// 1pst,2neiter,3pdt,4both
int judge(int month, int hour, int week, bool sun, int minute, int second) {
    if (month < 3) {
        return 1;
    } else if (month == 3) {
        if (week < 2) {
            return 1;
        } else if (week == 2) {
            if (!sun) {
                return 1;
            } else {
                if (hour < 2) {
                    return 1;
                } else if (hour == 2) {
                    return 2;
                } else {
                    if (minute == 0 && hour == 0) {
                        return 2;
                    } else {
                        return 3;
                    }
                }
            }
        } else {
            return 3;
        }
    } else {
        if (month < 11) {
            return 3;
        } else if (month == 11) {
            if (week == 1) {
                if (!sun) {
                    return 3;
                } else {
                    if (hour < 1) {
                        return 3;
                    } else if (hour == 1) {
                        return 4;
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    }
}
int main() {
    Sunday();
    int kase = 0;

    int T;
    scanf("%d", &T);
    while (T--) {
        int year, month, day, hour, minute, second;
        scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute,
              &second);
        year -= 2000;
        bool sun = sunday[year][month][day] != 0;
        int week = 4;

        if (sun) {
            week = sunday[year][month][day];
        } else {
            for (int i = 1; i < 5; ++i) {
                if (day - 7 * i <= 0) {
                    week = i;
                    break;
                }
            }
            // for (int i = day; i < day + 7; ++i) {
            //     if (sunday[year][month][day] != 0) {
            //         week = sunday[year][month][day];
            //         break;
            //     }
            // }
        }

        // printf("%d %d\n", sun, week);

        printf("Case #%d: ", ++kase);
        int ans = judge(month, hour, week, sun, minute, second);
        if (ans == 1) {
            printf("PST\n");
        } else if (ans == 2) {
            printf("Neither\n");
        } else if (ans == 3) {
            printf("PDT\n");
        } else if (ans == 4) {
            printf("Both\n");
        }
    }

    return 0;
}