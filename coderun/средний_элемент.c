#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int* mass, size_t s)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (size_t i = 1; i < s; i++)
        {
            if (mass[i] > mass[i - 1])
            {
                int temp = mass[i - 1];
                mass[i - 1] = mass[i];
                mass[i] = temp;
                swap = true;
            }
        }
    }
    
}

int main() 
{
    
    int* mass = (int*)malloc(sizeof(int) * 3);
    scanf("%d %d %d", &mass[0], &mass[1], &mass[2]);
    bubble_sort(mass, 3);
    printf("%d", mass[1]);
    
    return 0;
}

