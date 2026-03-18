#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, check, left = 0, res = 0, res_p = 0;
    char *str;
    int alph[30] = { 0 };

    scanf("%d %d\n", &n, &m);
    str = (char *)malloc(n * sizeof(char));

    for(int i = 0; i < n; ++i){
        scanf("%c", &str[i]);
        check = (int) str[i] - 'a';
        ++alph[check];

        while(alph[check] > m) {
            --alph[((int) str[left] - 'a')];
            ++left;
        }

        if(res < (i - left + 1)){
            res = i - left + 1;
            res_p = left;
        }
    }

    printf("%d %d\n", res, res_p + 1);

    free(str);
    return 0;
}


