#include <stdio.h>
#define N 100
#define IN 1
#define OUT 0

int change_array(char* pointer, char* pC)
{
    int k = 0,state = OUT;
    /* *pointer = '2';
    pointer +=N;
    *pointer = 3;*/
    char* str = pointer;
    //printf("%p\n",pointer);
   // printf("%p\n",str);
    while (*pC != 10)
    {
        if (*pC == ' ')
        {
            if (state == IN){
                k++;
                *str = 0;
                 str = pointer+k*N;
            }
        }
        else
        {
            //printf("%c",*pC);
            *(str++) = *pC;
            if (state == OUT)
                state = IN;
        }
        pC++;
    }
    *str = 0;
    if (state == IN)
        k++;
    //printf("%d",k);
    return k;
}

int main()
{
    int words;
    int b = 0,j = 0;
    char str[N];
    char digits[] = {'1','2','3','4','5','6','7','8','9',0};
    char words_for_digits[] = {"zeroonetwothreefourfivesixseveneightnine\0"};
    printf("Enter the string:");
    fgets(str,N,stdin);

    char exit[N][N];

     words = change_array(&exit[0][0],str);
    for (int i = 0;i<words;i++){
        while (exit[i][j] != 0){
            printf("%c", exit[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
    }
   // printf("\n%c",exit[1][0]);
}
//массив двумерный с пробелами, а не только вывод
//слова в порядке возрастания длины (одинаковые - по алфавиту)
//добавить замену цифр на слова (0-9)