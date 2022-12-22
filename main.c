/* Вычислить функцию cos(x), представленную в виде ряда Маклорена с заданной точностью eps > 0 или
 * с заданным числом членов разложения N>10.
 * cos⁡x=∑_(n=0)^∞▒〖-1〗^n   x^(2n+1)/(2n+1)!
 * Используя полученный результат вычислить: sin(x) tg(x) ctg(x).
 * После каждого шага выводить текущее значение функции и текущее значение шага.
 */


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
    printf("Select an action:\n1. The number of expansion terms N > 10\n 2. The accuracy of eps calculations > 0.\n");
    int choice;
    scanf("%d", &choice);

    double sum, cosx, sinx, tgx, ctgx;

    switch (choice) {
        case 1:
            printf("Enter the number of expansion members N > 10: ");
            int N;
            scanf("%d", &N);
            while(N <= 10) {
                printf("Enter the number of expansion members N > 10: ");
                scanf("%d", &N);
            }
            printf("Enter the angle x in radians: ");
            int x;
            scanf("%d", &x);
            for (int i = 0; i <= N; i++) {
                sum += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);

                printf("Step %d: cos(%d) = %f\n", i, x, sum);
            }

            cosx = sum;
            sinx = sqrt(1 - pow(cosx, 2));
            tgx = sinx / cosx;
            ctgx = cosx / sinx;
            printf("cos(%d) = %f\n", x, cosx);
            printf("sin(%d) = %f\n", x, sinx);
            printf("tg(%d) = %f\n", x, tgx);
            printf("ctg(%d) = %f\n", x, ctgx);
            break;

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

            for (int i = 0; fabs(pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1)) > eps; i++) {
                sum += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);

                printf("Step %d: cos(%d) = %f\n", i, x, sum);
            }

            cosx = sum;
            sinx = sqrt(1 - pow(cosx, 2));
            tgx = sinx / cosx;
            ctgx = cosx / sinx;

            printf("cos(%d) = %f\n", x, cosx);
            printf("sin(%d) = %f\n", x, sinx);
            printf("tg(%d) = %f\n", x, tgx);
            printf("ctg(%d) = %f\n", x, ctgx);
        default:
            printf("Invalid input.\n");
            break;
    }



    return 0;
}
