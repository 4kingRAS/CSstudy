#include <stdio.h>
#include <memory.h>

#define MAXN 100002

int main(void) {
    char s[MAXN];
    unsigned char p[MAXN];
    unsigned char t[MAXN];
    memset(s, 0, MAXN * sizeof(char));
    memset(p, 0, MAXN * sizeof(char));
    memset(t, 0, MAXN * sizeof(char));

    gets(s);
    int len = strlen(s);

    int lastP, lastT, c = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'A')
        {
            c++;
            p[c] = lastP + p[c - 1];
            if (c > 1) { t[c - 1] = lastT; }
            lastT = 0;
        }
        
        if (s[i] == 'P') { lastP++; }
        if (s[i] == 'T') { lastT++; }
    }
    t[c] = lastT;

    int sum = 0;
    for (int i = 1; i <= c; i++)
    {
        sum += (p[i] * t[i]) % 1000000007;
    }
    
    printf("%d\n", sum);
    return 0;
}