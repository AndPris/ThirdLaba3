#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, p, q, d, x1, x2, x3;

    printf("a:\n");
    scanf("%f", &a);
    printf("b:\n");
    scanf("%f", &b);
    printf("c:\n");
    scanf("%f", &c);

    p = b - a*a/3;
    q = 2*a*a*a/27 - a*b/3 + c;

    d = p*p*p/27 + q*q/4;

    if(d > 0) {
        float u, v, re, im;

        u = pow(-q/2 + sqrt(d), 1.0/3);
        v = -p/(3*u);

        x1 = u + v - a/3;
        re = -(u+v)/2 - a/3;
        im = sqrt(3)*(u-v)/2;

        printf("x1 = %f\n", x1);
        printf("x2 = %f + i*%f\n", re, im);
        printf("x3 = %f - i*%f\n", re, im);

    } else if (d==0) {
        x1 = 3 * q / p - a/3;
        x2 = x3 = -3 * q / (2 * p) - a/3;

        printf("x1 = %f\n", x1);
        printf("x2 = x3 = %f\n", x2);
    } else {
        float r, f;

        r = sqrt(-p*p*p/27);
        f = acos(-q/(2*r));

        x1 = 2 * abs(pow(r, 1.0/3))*cos(f/3) - a/3;
        x2 = 2 * abs(pow(r, 1.0/3))*cos((f + 2*M_PI)/3) - a/3;
        x3 = 2 * abs(pow(r, 1.0/3))*cos((f + 4*M_PI)/3) - a/3;

        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        printf("x3 = %f\n", x3);
    }

    return 0;
}
