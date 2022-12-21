#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n) {
    double f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 10, x;
    double eps;
    double cosx, sinx, tgx, ctgx;
    double sum = 0;

    printf("Выберите действие:\n1. Число членов разложение N > 10\n2. Точность вычислений eps > 0.\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            while(n <= 10) {
                printf("Введите число членов разложения N > 10: ");
                scanf("%d", &n);
            }
            printf("Введите угол x в радианах: ");
            scanf("%d", &x);
            for (int i = 1; i <= n; i++) {
                sum += pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
                printf("n = %d\tcos(%d) = %f\t\n", i, x, sum);
            }
            cosx = sum;
            sinx = sqrt(1 - pow(cosx, 2));
            tgx = sinx / cosx;
            ctgx = cosx / sinx;
            printf("\nsin(%d) = %f\ntg(%d) = %f\nctg(%d) = %f\n", x, sinx, x, tgx, x, ctgx);
            break;

        case 2:
            while(eps <= 0) {
                printf("Введите точность вычислений eps > 0: ");
                scanf("%lf", &eps);
            }
            printf("Введите угол x в радианах: ");
            scanf("%d", &x);
            for (int i = 1; i <= n; i++) {
                sum += pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
                printf("n = %d\tcos(%d) = %f\t\n", i, x, sum);
                if (fabs(cos(x) - sum) < eps) {
                    break;
                }
            }
            cosx = sum;
            sinx = sqrt(1 - pow(cosx, 2));
            tgx = sinx / cosx;
            ctgx = cosx / sinx;
            printf("\nsin(%d) = %f\ntg(%d) = %f\nctg(%d) = %f\n", x, sinx, x, tgx, x, ctgx);
            break;
        default:
            printf("Неверный ввод.\n");
            break;
    }
    return 0;
}
