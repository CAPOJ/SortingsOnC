#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int *a = data;
    if (input(a, &n) == 0) {
        printf("n/a\n");
    } else {
        squaring(a, n);
        output(a, n);
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
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}
