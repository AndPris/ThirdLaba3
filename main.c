#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, p, q, d, y1, y2, y3, x1, x2, x3;
    char ch, cond=0;

    do {
        cond = 0;
        printf("Enter coefficient a:\n");
        scanf("%f%c", &a, &ch);
        if(ch!='\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        };
    } while(cond);
    ch=' ';

    do {
        cond = 0;
        printf("Enter coefficient b:\n");
        scanf("%f%c", &b, &ch);
        if(ch!='\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        };
    } while(cond);
    ch=' ';

    do {
        cond = 0;
        printf("Enter coefficient c:\n");
        scanf("%f%c", &c, &ch);
        if(ch!='\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        };
    } while(cond);

    p = b - a*a/3;
    q = 2*a*a*a/27. - a*b/3. + c;

    d = p*p*p/27. + q*q/4.;
    if(d > 0) {
        float u, v, im;

        u = cbrt((-q/2 + sqrt(d)));
        if(u==0) {
            printf("Impossible to calculate using such method!");
            return 0;
        }
        v = -p/(3*u);

        y1 = u + v;
        y2 = y3 = -(u+v)/2;
        im = sqrt(3)*(u-v)/2;

        x1 = y1 - a/3;
        x2 = y2 - a/3;
        x3 = y3 - a/3;

        printf("x1 = %f\n", x1);
        printf("x2 = %f + i*%f\n", x2, im);
        printf("x3 = %f - i*%f\n", x3, im);

    } else if (d==0) {
        if(p==0) {
            printf("Impossible to calculate using such method!");
            return 0;
        }
        y1 = 3 * q / p;
        y2 = y3 = -3 * q / (2 * p);

        x1 = y1 - a/3;
        x2 = y2 - a/3;
        x3 = y3 - a/3;

        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        printf("x3 = %f\n", x3);
    } else {
        float r, f;

        r = sqrt(-p*p*p/27);
        if(r==0) {
            printf("Impossible to calculate using such method!");
            return 0;
        }
        f = acos(-q/(2*r));

        y1 = 2 * fabs(cbrt(r))*cos(f/3);
        y2 = 2 * fabs(cbrt(r))*cos((f + 2*M_PI)/3);
        y3 = 2 * fabs(cbrt(r))*cos((f + 4*M_PI)/3);

        x1 = y1 - a/3;
        x2 = y2 - a/3;
        x3 = y3 - a/3;

        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        printf("x3 = %f\n", x3);
    }

    return 0;
}
