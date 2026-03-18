#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NUM 100000

int main()
{
    bool numbers[MAX_NUM] = {0};

    int d = -1;
    char ch = ' ';
    int countUnique = 0;

    while (ch != '\n')
    {
        scanf("%d%c", &d, &ch);
        if (numbers[d] == false)
        {
            numbers[d] = true;
            countUnique++;
        }
    }

    printf("%d", countUnique);


    return 0;
}

