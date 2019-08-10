#include <stdio.h>
#include <memory.h>

// ** PAT A 1005 Spell it right
// Given a non-negative integer N, your task is to compute the sum of all the digits of N, 
// and output every digit of the sum in English.

// Input Specification:
// Each input file contains one test case. Each case occupies one line which contains 
// an N (≤10^100).

// Output Specification:
// For each test case, output in one line the digits of the sum in English words. 
// There must be one space between two consecutive words, but no extra space at the end of a line.

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