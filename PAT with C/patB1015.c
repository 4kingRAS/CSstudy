#include <stdio.h>
#include <stdlib.h>

#define MAXN 100001
 
struct stu
{
    int no;
    int m;
    int t;
    int cg;
};

int cmp(const void *a ,const void *b)
{
    // default ascend , > 1 = 0 < -1
    const struct stu *p = a;
    const struct stu *q = b;
    
    if (p->cg == q->cg)
    {
        if((p->m + p->t) == (q->m + q->t))
        {
            return (p->m == q->m) ?  (p->no - q->no) : 0 - (p->m - q->m);
        }
        return 0 - (p->m + p->t - q->m - q->t);
    }
    return 0 - (p->cg - q->cg);
}

int main(void) {
    int n, low, high;
    
    scanf("%d %d %d", &n, &low, &high);

    struct stu a[n];
    int no, m, t;
    int count = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &no, &m, &t);
        a[i].no = no;
        a[i].t = t;
        a[i].m = m;

        if (m < low || t < low)
        {
            a[i].cg = 0;
            count--;
        }
        else
        {
           if (m < high) 
           { 
               a[i].cg = (m >= t) ? 2 : 1; 
           }     
           else 
           { 
               a[i].cg = (t < high) ? 3 : 4; 
           }
        }
    }
    qsort(a, n, sizeof(a[0]), cmp);
    
    printf("%d\n", count);
    for(int i = 0; i < count; ++i) 
    {
        printf("%08d %d %d\n", a[i].no, a[i].m, a[i].t);
    }

    return 0;
}