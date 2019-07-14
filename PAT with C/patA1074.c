#include <stdio.h>
#include <memory.h>

#define MAXN 100001
 
struct node {
    int data;
    int next;
};

int main(void) {
    struct node list[MAXN];
    int first, n, k;
    int addr, data, next;

    memset(list, 0, MAXN * sizeof(struct node));
    scanf("%d %d %d", &first, &n, &k);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", &addr, &data, &next);
        list[addr].data = data;
        list[addr].next = next;
    }

    int p = first;
    int c = 0;  //calc valid node   with -1 end( maybe multiple -1)
    while (p != -1)
    {
        p = list[p].next;
        c++;
    }
    
    n = c; // count of valid nodes
    c = 0;
    p = first;
    int head = first;
    int last = first;
    int suff = first;
    int cur = first;
    for (int i = 0; i < n / k; i++) // every k node
    {
        p = suff;
        while (c < k) // two pointer cur p reverse link
        {
            cur = suff;
            suff = list[cur].next;
            if (c > 0)
            {
                if (c == k - 1)// the k th one
                {
                    if (i == 0) 
                    { 
                        head = cur;
                        list[first].next = suff;
                        first = suff;
                    } 
                    else
                    {
                        list[last].next = cur;
                        last = first;
                        list[first].next = (suff == -1) ? -1 : suff;
                        first = suff;
                    }
                }
                list[cur].next = p;
                p = cur;
            }
            c++;
        }
        c = 0;
    }
    
    while (head != -1)
    {
        if (list[head].next == -1)
        {
            printf("%05d %d %d\n", head, list[head].data, -1);
        }
        else 
        {
            printf("%05d %d %05d\n", head, list[head].data, list[head].next);
        }
        head = list[head].next;
    }
    
    return 0;
}