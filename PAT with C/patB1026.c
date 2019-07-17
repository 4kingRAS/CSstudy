#include <stdio.h>
#include <math.h>

int main(void) {
    int c1 = 0;
    int c2 = 0;
    scanf("%d %d", &c1, &c2);

    int h = (c2 - c1) / 360000;
    int m = ((c2 - c1) / 6000) - h*60;
    double s = ((c2 - c1) / 100.00) - h*3600 - m*60;
    int ss = round(s);

    printf("%02d:%02d:%02d\n", h, m, ss);
    return 0;
}