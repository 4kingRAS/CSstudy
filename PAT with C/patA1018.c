#include <stdio.h>
#include <memory.h>

#define MAX 11

void swap(char* a, char* b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

int main(void) {
    char s1[MAX];
    char s2[MAX]; 
    char s[MAX];
    char a;
    char b;
    scanf("%s %c %s %c", s1, &a, s2, &b);
    memset(s, '\0', MAX * sizeof(char));

    int c1 = 0;
    int c2 = 0;  
    int len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == a) c1++;
        if (s2[i] == b) c2++;
    }

    int c = (c1 > c2) ? c1 : c2;
    if (c == 0 || (a == '0'&& b == '0'))
    {
        printf("%d\n", 0);
        return 0;
    }

    
    
    a -= '0';
    b -= '0';
    int co = 0;
    for (int i = 0; i < c; i++) // 倒序输出
    {
        if (c1 != 0 && c2 != 0)
        {
            if (a + b + co > 9) 
            { 
                s[i] = a + b + co - 10 + '0';
                co = 1;
            }
            else 
            {
                s[i] = a + b + co + '0';
                co = 0;
            }
            c1--;
            c2--;
        }
        else
        {
            
            s[i] = (c1 > c2) ? a : b;
            if (s[i] + co > 9) 
            {
                s[i] = '0';
                co = 1;
            }
            else
            {
                s[i] += (co + '0');
                co = 0;
            } 
        }
    }
    if (co == 1) s[c] = '1';

    c = strlen(s);
    for (int i = 0; i < strlen(s)/2; i++)
    {
        c--;
        swap(&s[c], &s[i]);
    }
    
    printf("%s\n", s);
    return 0;
}