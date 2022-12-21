/* Вычислить функцию cos(x), представленную в виде ряда Маклорена
 * с заданной точностью eps>0 или с числом членов разложения n>10.
 * cosx=∑_(n=1)^∞▒(-1)^n * x^2n/(2n)!
 * Используя полученный результат, вычислить все функции заданного угла
 * sin(x), tg(x), ctg(x) и вывести их на экран.
 */

#include <stdio.h>
#include <math.h>

int main()
{
    int n = 10, x;
    double eps;
    double cosx, sinx, tgx, ctgx;
    double sum = 0;
    double fact = 1;

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

            for(int i = 1; i <= n; i++) {
                fact *= 2 * i * (2 * i - 1);
                sum += pow(-1, i) * pow(x, 2 * i) / fact;
                printf("cosx = %lf\tn = %d\n", sum, i);
            }
            break;
        case 2:
            while(eps <= 0) {
                printf("Введите точность вычислений eps > 0: ");
                scanf("%lf", &eps);
            }
            printf("Введите угол x в радианах: ");
            scanf("%d", &x);

            for(int i = 1; fabs(pow(-1, i) * pow(x, 2 * i) / fact) > eps; i++) {
                fact *= 2 * i * (2 * i - 1);
                sum += pow(-1, i) * pow(x, 2 * i) / fact;
                printf("cosx = %lf\n", sum);
            }
            break;
        default:
            printf("Неверный ввод.\n");
            break;
    }

    return 0;
}
