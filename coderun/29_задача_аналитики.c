#include <stdio.h>
#include <math.h>

int main() {
    double x1, x2, D, a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    D = b * b - 4 * a * c;
    if (D > 1e-12) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        if (x1 > x2) printf("2\n%lf %lf",x2, x1);
        else printf("2\n%lf %lf", x1, x2);
    }
    else if (fabs(D) < 1e-12) {
        x1 = -b / (2 * a);
        printf("1\n%lf", x1);
    }
    else printf("0");

    return 0;
}
