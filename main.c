#include <stdio.h>
#include <math.h>

double factorial(int n) {
    double f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

double func(int i, int x) {
    double a = pow(-1, i);
    double b = pow(x, 2 * i + 1);
    double c = factorial(2 * i + 1);
    return a * b / c;
}

double fsinx(double cosx) {
    return sqrt(1 - cosx * cosx);
}

double ftgx(double sinx, double cosx) {
    return sinx / cosx;
}

double fctgx(double sinx, double cosx) {
    return cosx / sinx;
}

int main()
{
    printf("Select an action:\n1. The number of expansion terms N > 10\n 2. The accuracy of eps calculations > 0.\n");
    int choice;
    scanf("%d", &choice);

    double sum = 0, cosx, sinx, tgx, ctgx;
    int x = 0;

    switch (choice) {
        case 1:
        {
            printf("Enter the number of expansion members N > 10: ");
            int N;
            scanf("%d", &N);
            while(N <= 10) {
                printf("Enter the number of expansion members N > 10: ");
                scanf("%d", &N);
            }
            printf("Enter the angle x in radians: ");

            scanf("%d", &x);
            for (int i = 0; i <= N; i++) {
                sum += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);

                printf("Step %d: cos(%d) = %f\n", i, x, sum);
            }
            break;
        }


        case 2:
            printf("Enter the calculation accuracy eps > 0: ");
            double eps = 0;
            scanf("%lf", &eps);
            while(eps <= 0) {
                printf("Enter the calculation accuracy eps > 0: ");
                scanf("%lf", &eps);
            }
            printf("Enter the angle x in radians: ");
            scanf("%d", &x);

            for (int i = 0; fabs(func(i, x)) > eps; i++) {
                sum += func(i, x);

                printf("Step %d: cos(%d) = %f\n", i, x, sum);
            }

        default:
            break;
    }

    cosx = sum;
    sinx = fsinx(cosx);
    tgx = ftgx(sinx, cosx);
    ctgx = fctgx(sinx, cosx);

    printf("cos(%d) = %f\n", x, cosx);
    printf("sin(%d) = %f\n", x, sinx);
    printf("tg(%d) = %f\n", x, tgx);
    printf("ctg(%d) = %f\n", x, ctgx);


    return 0;
}
