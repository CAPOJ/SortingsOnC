#include <math.h>
#include <stdio.h>
#define NMAX 30
int input(int *a, int *n);
int chet(int a);
double mean(const int *a, int n);
double threeSigm(double variance_v, double mean_v);
double variance(const int *a, int n);
void output_result(int checkFor_v);
int checkFor(const int *a, int n, double mean_v, double threeSigm_v);
int main() {
    int n, data[NMAX];
    int *a = data;
    if (input(a, &n) == 1) {
        double variance_v = variance(a, n);
        double mean_v = mean(a, n);
        double threeSigm_v = threeSigm(variance_v, mean_v);
        int checkFor_v = checkFor(a, n, mean_v, threeSigm_v);
        output_result(checkFor_v);
    } else {
        printf("n/a");
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
int chet(int a) {
    if (a % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
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
double threeSigm(double variance_v, double mean_v) {
    double sigm;
    sigm = mean_v + 3 * sqrt(variance_v);
    return sigm;
}
int checkFor(const int *a, int n, double mean_v, double threeSigm_v) {
    for (int i = 0; i < n; i++) {
        if (chet(a[i]) == 1 && a[i] && a[i] >= mean_v && a[i] <= threeSigm_v) {
            return a[i];
        }
    }
    return 0;
}
void output_result(int checkFor_v) { printf("%d", checkFor_v); }