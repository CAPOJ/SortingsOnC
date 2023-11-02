#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(const int *a, int n);
int min(const int *a, int n);
double mean(const int *a, int n);
double variance(const int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int *a = data;
    if (input(a, &n) == 0) {
        printf("n/a");
    } else {
        output(a, n);
        int max_v = max(data, n);
        int min_v = min(data, n);
        double mean_v = mean(data, n);
        double variance_v = variance(data, n);
        output_result(max_v, min_v, mean_v, variance_v);
    }
    return 0;
}
int input(int *a, int *n) {
    char dop;
    if (scanf("%d%c", n, &dop) == 2 && *n > 0 && *n <= 10 && dop == '\n') {
        char c;
        int cntr = 1;
        for (int i = 0; i < *n; i++) {
            if (scanf("%d%c", &a[i], &c) != 2) {
                return 0;
            }
            if (c == '\n') {
                break;
            } else {
                cntr++;
            }
        }
        if (cntr != *n) {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}
void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    printf("\n");
}
int max(const int *a, int n) {
    int maxi = *a;
    for (int i = 0; i < n; i++) {
        if (a[i] > maxi) {
            maxi = a[i];
        }
    }
    return maxi;
}
int min(const int *a, int n) {
    int mi = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < mi) {
            mi = a[i];
        }
    }
    return mi;
}

double mean(const int *a, int n) {
    double mn = 0;
    for (int i = 0; i < n; i++) {
        mn += a[i];
    }
    mn = mn / n;
    return mn;
}
double variance(const int *a, int n) {
    double var = 0.0;
    double dif = mean(a, n);
    for (int i = 0; i < n; i++) {
        var += ((a[i] - dif) * (a[i] - dif));
    }
    var = var / n;
    return var;
}
void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}