#include <stdio.h>
#include <memory.h>

// ** PAT A 1042  shuffling machine

// status of a card deck is in the following order:

// S1, S2, ..., S13, 
// H1, H2, ..., H13, 
// C1, C2, ..., C13, 
// D1, D2, ..., D13, 
// J1, J2

// Sample Input:
// 2
// 36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 
// 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
// Sample Output:
// S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 
// D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 
// C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5

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