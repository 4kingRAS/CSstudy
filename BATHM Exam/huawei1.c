#include <stdio.h>
#include <memory.h>

int main() {
    
    int len;
    char s[128];
    char out[256][3]= {0};
    
    scanf("%d", &len);
    char c[3];
    int l = 0;
    int ll = 0;
    for (int i = 0; i < len - 1; i++)
    {
        scanf("%s", c);
        if (strlen(c) == 1)
        {
            if (c[0] == 'A')
            {
                out[l][0] = '1';
                out[l][1] = '2';
                out[l][2] = '\0';
                l++;
                out[l][0] = '3';
                out[l][1] = '4';
                out[l][2] = '\0';
                l++;
            }        
            else if (c[0] == 'B')
            {
                out[l][0] = 'A';
                out[l][1] = 'B';
                out[l][2] = '\0';
                l++;
                out[l][0] = 'C';
                out[l][1] = 'D';
                out[l][2] = '\0';
                l++;
            }
            else {
                out[l][0] = c[0];
                out[l][1] = '\0';
                l++;
            }

        }
        else
        {
            out[l][0] = c[0];
            out[l][1] = c[1];
            out[l][2] = '\0';
            l++;
        }
        
    }
    
    printf("%d ", l);
    for (int i = 0; i < l; i++)
    {
        printf("%s ", out[i]);
    }

    return 0;
}