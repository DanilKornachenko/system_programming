#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* mass = (int*)calloc(0, sizeof(int));
    size_t size = 1;

    char ch = ' ';

    while(ch != '\n')
    {
        int d = 0;
        scanf("%d%c", &d, &ch);
        size++;
        mass = (int*)realloc(mass, sizeof(int) * size);
        mass[size-2] = d;
    }

    int answer = 0;

    for (int i = 1; i < size-2; i++)
    {
        if (mass[i -1] < mass[i] && mass[i] > mass[i+1])
        {
            //printf("%d", mass[i]);
            answer++;
        }
    }

    printf("%d", answer);

    return 0;
}

