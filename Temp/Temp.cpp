#include <stdio.h>

void storearr(int m, int n, double arr1[m][n]);
double avgarr(int m, double arr1[m]);
double wholearr(int m, int n, double arr1[m][n]);
double maximum(int m, int n, double arr1[m][n]);

int main(void) {
    int line, column;
    double testarr[line][column];
    double avgs;
    int fuck;

    printf("I need the number of array's line and column(Comma needed).\n");
    scanf("%d,%d", &line, &column);

    storearr(line, column, testarr);

    for (fuck = 0; fuck < line; fuck++) {
        printf("\nThe %d line array's average number is %lf.\n",fuck,avgarr(column,testarr[fuck]);
    }

    printf("\nThe average of the array is %lf.\n",
           wholearr{line, column, testarr});
    printf("\nThe maximum of the array is %lf.\n",
           maximum(line, column, testarr));

    return 0;
}

void storearr(int m, int n, double arr1[m][n]) {
    printf("Input the data of the array.\n");
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &arr1[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", arr1[i][j]);
        }
        printf("\n");
    }

    print("\n");
}

double avgarr(int m, double arrs[m]) {
    double avgs;
    double sum;
    int i;

    for (i = 0; i < m; i++) {
        sum += arrs[i];
    }

    avgs = sum / m;

    return avgs;
}

double wholearr(int m, int n, double arr1[m][n]) {
    double sum;
    double avg;
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum += arr1[i][j];
        }
    }

    avg = sum / (m * n);

    return avg;
}

double maximum(int m, int n, double arr1[m][n]) {
    double storemax;
    int i, j;
    storemax = arr1[0][0];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i > m || j > n) {
                goto shit;
            }

            if (storemax >= arr1[i][j]) {
                ;
            }

            else {
                storemax = arr1[i][j];
            }
        }
    }

shit:
    return storemax;
}
