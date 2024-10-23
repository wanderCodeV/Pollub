#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x = 0.1;
    float expA = 10 * cos(x) - 0.1 * pow(x, 2) + sin(x) + sqrt(4 * pow(x, 2) + 7);
    float expB = log10(x+5) + exp(x+1) - fabs(tan(x) + 1);

    float angle = 90;
     angle *= M_PI / 180;
    float expC = (pow(sin(angle), 2) + 0.5) / (cos(pow(angle, 4)) + pow(tan(pow(angle, 2)), 4));
    float expD = sqrt(fabs(5*sin(pow(angle, 5))+1)/(3.5*pow(sin(angle)+cos(angle), 2)));

    printf("%f %f %f %f", expA, expB, expC, expD);

}
