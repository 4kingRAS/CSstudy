#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ** PAT A 1028 List Sorting

// 字符串，数字，特定数字格式 的排序
// ascend, non-desc, non-desc
#define MAXN 100001
int type;
 
struct stu
{
    int no;
    char s[9];
    int g;
};

int cmp(const void *a, const void *b)
{
    // default ascend , >:1, =:0 , <:-1
    const struct stu *p = a;
    const struct stu *q = b;
    switch (type)
    {
    case 1:
        return p->no - q->no;
    case 2:
        {
            char a[9];
            char b[9];
            strcpy(a, p->s);
            strcpy(b, q->s);
            int la = strlen(a);
            int lb = strlen(b);
            for (int i = 0; (i < la|| i < lb); i++)
            {
                if (a[i] == b[i])
                {
                    continue;
                }
                else
                {
                    return a[i] - b[i];
                }
            }

            if (la == lb) 
            {
                return p->no - q->no;
            }
            else
            {
                return la - lb;
            }
        }  
    default://case 3
        {
            if (p->g == q->g)
            {
                return p->no - q->no;
            }
            else
            {
                return p->g - q->g;
            }
        }
    }
}

int main(void) {
    int n;
    
    scanf("%d %d", &n, &type);

    struct stu a[n];
    int no, g;
    char str[9];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &no, str, &g); //scanf 读字符串会补\0
        a[i].no = no;
        strcpy(a[i].s, str);
        a[i].g = g;
    }
    qsort(a, n, sizeof(a[0]), cmp);
    
    for(int i = 0; i < n; ++i) 
    {
        printf("%06d %s %d\n", a[i].no, a[i].s, a[i].g);
    }

    return 0;
}