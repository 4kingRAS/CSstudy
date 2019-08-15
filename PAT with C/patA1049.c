#include <stdio.h>
#include <stdlib.h>

// ** PAT A 1049 counting ones

// The task is simple: given any positive integer N, you are supposed to count the 
// total number of 1's in the decimal form of the integers from 1 to N. 
// For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

// Input Specification:
// Each input file contains one test case which gives the positive N (≤2^30)

// Output Specification:
// For each test case, print the number of 1's in one line.


int main(void) {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int a = 1;  //power
    while (n / a != 0)
    {
        int num = n / a;
        int lo = n % a;
        int cur = num % 10;
        int hi = num / 10;

        if (cur == 0)
        {
            sum += hi * a;
        }
        else
        {
            sum += (cur == 1) ?  (hi * a + lo + 1) : ((hi+1) * a);
        }
        a *= 10;
    }
    printf("%d\n", sum);

    return 0;
}