#include<stdio.h>

/* insertion sort and merge sort */
int n;

void printArray(int a[]) {
    
    for(int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if(i < n - 1) printf(" ");
    }
    printf("\n");
}

int isInsertionSort(int tmp[], int chg[]) {
    int flag = 0;
    
    for(int i = 0; i < n; i++)
    {
        int temp = tmp[i];
        
        
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    int origin[n];
    int temp[n];
    int chg[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &chg[i]);
    }
    if ()    

    return 0;
}
