#include <stdio.h>
#include <math.h>

#define MAX 199999

int main()
{

    int c = 1;
    int n = 0;
    int s = 0;
    int e = 0;
    scanf("%d %d", &s, &e);
    
    for(int i = 2; i <= MAX; i++)
    {
        int j = 2;
        
        if (s == 1 && i == 2) 
        {
            printf("%d ", 2);
            if (e == 1)
                return 0;
            else
                continue;
        }
        
        for(j = 2; j <= (int)sqrt(i); j++)
        {          
            if (i % j == 0) {
                j = 0;
                break;
            }
        }
        
        if (j != 0) {
            n++;
            if (n >= s) {
                if (n == e) 
                {
                    printf("%d", i);
                    return 0;
                }
                if (c == 10) 
                {
                    printf("%d\n", i);
                    c = 0;
                }
                else
                    printf("%d ", i);
                c++;
            }           
        }
    }   
}