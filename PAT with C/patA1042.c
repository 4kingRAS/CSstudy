#include <stdio.h>
#include <memory.h>

// shuffling machine

/*
*   "S" stands for "Spade", "H" for"Heart", 
*   "C" for "Club", "D" for"Diamond", and "J" for "Joker". 
*/

#define MAX 55

char s[5] = {'S', 'H', 'C', 'D', 'J'};

int main(void) {
    int rpe;
    int sh[MAX];
    int card[MAX];
    scanf("%d", &rpe);

    for (int i = 0; i < MAX - 1; i++)
    {
        scanf("%d", &sh[i]);
        card[i] = i + 1;
    }
    
    int temp[MAX];
    for (int i = 0; i < rpe; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            temp[sh[j] - 1] = card[j];
        }
        for (int j = 0; j < MAX - 1; j++)
        {
            card[j] = temp[j];
        }
    }

    for (int i = 0; i < MAX - 1; i++)
    {
        int a = card[i] - 1;
        printf("%c%d", s[a / 13], (a % 13) + 1);
        if (i != MAX - 2) printf(" ");
    }
    return 0;
}