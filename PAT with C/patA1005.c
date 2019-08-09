#include <stdio.h>
#include <memory.h>

#define MAX 101

char d[10][10] = {"zero", "one", "two", "three", "four", "five",
                "six", "seven", "eight", "nine"};

int main(void) {
    
    int s[5] = { 0 }; // digit
    char c;

    int sum = 0;
    while (scanf("%c", &c))
    {
        if (c == '\n') break;
        sum += c - '0';
    }
    
    if (sum == 0)
    {
        printf("zero");
        return 0;
    }
    
    int x = 0;
    while (sum != 0)
    {
        s[x] = sum % 10; // 100 % 10 = 0
        sum = sum / 10;
        x++;
    }

    for (int i = x - 1; i >= 0; i--)
    {
        printf("%s", d[s[i]]);
        if (i != 0) printf(" "); 
    }

    return 0;
}