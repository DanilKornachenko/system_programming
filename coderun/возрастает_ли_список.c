#include <stdio.h>
#include <stdbool.h>

int main()
{
    int temp = -1;
    int num = -1;
    char ch = ' ';

    bool yes = true;

    while (ch != '\n')
    {
        scanf("%d%c", &num, &ch);

        if (temp == -1)
        {
            temp = num;
        }
        else
        {
            if (num <= temp)
            {
                yes = false;
            }
            temp = num;
        }
    }

    if (yes)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}

