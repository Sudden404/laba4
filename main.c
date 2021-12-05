#include <stdio.h>
#define N 100
#define IN 1
#define OUT 0
int mystrlen(char* pC)
{
    int k = 0;

    while (*pC != 0)
    {
        k++;
        pC++;
    }
    // printf("k=%d\n",k);
    return k;
}
int change_array(char* pointer, char* pC)
{
    int k = 0,state = OUT;
    /* *pointer = '2';
    pointer +=N;
    *pointer = 3;*/
    char* str = pointer;
    while (*pC != 10)
    {
        if (*pC == ' ')
        {
            if (state == IN){
                k++;
                *str = 0;
                str = pointer+k*N;
            }
            state = OUT;
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
void replacement_digit(char* pC,char* words)
{
    char* tmp = pC;
    while (*pC != 10)
    {
        if (*pC >= '0' && *pC <= '9')
        {
            char* tmp_words = words;
            int len = mystrlen(tmp);
            char* tmp_pC = tmp + len;
            int transfer = 0;
            while (*tmp_words != *pC)//нахожу в массиве со словами нужное обозначение цифры
            {
                tmp_words++;
            }
            tmp_words++;
            while (*tmp_words < '0' || *tmp_words > '9')//считаю на сколько необходимо сдвинуть массив
            {
                tmp_words++;
                transfer++;
            }
            while (tmp_pC != pC){//сдвигаю строку
                *(tmp_pC+transfer-1) = *tmp_pC;
                //printf("tmp_pC+transfer=%c\n",*(tmp_pC+transfer));
                tmp_pC--;
            }
            tmp_words -= transfer;
            //printf("transfer=%d\n",transfer);
            while (*tmp_words < '0' || *tmp_words > '9')//перезаписываю
            {
                //printf("%p\t%p\t%c\n", pC, tmp_words, *tmp_words);
                *(pC++) = *(tmp_words++);
            }
            pC--;//тк pC остановилась на следующем символе после слова, а сдвиг будет ещё 1 после
        }
        pC++;
    }
}
int my_strcmp(char* s1,char* s2){
    if (mystrlen(s1) == mystrlen(s2)) {
        while (*s1 != 0 && *s1 == *s2) {
            s1++;
            s2++;
        }
        return *s1 - *s2;
    }
    else
        if (mystrlen(s1) < mystrlen(s2))
            return -1;
        else return 1;
}
void my_swap(char* s1, char* s2) {
    char *starts1 = s1;
    char *starts2 = s2;
    char tmp[N];
    char *tmp_s1 = tmp;
    while (*s1 != 0)
        *(tmp_s1++) = *(s1++);
    *tmp_s1 = 0;
    tmp_s1 = tmp;
    printf("\n");
    while (*s2 != 0)
        *(starts1++) = *(s2++);
    while (*tmp_s1 != 0)
        *(starts2++) = *(tmp_s1++);
    *starts2 = 0;
    *starts1 = 0;
}
void sorting(char* pointer, int words) {
    for (int i = 0; i+1 < words; i++)
        for (int j = i + 1; j < words;j++)
            if (my_strcmp(pointer + i * N, pointer + j * N) > 0)
                my_swap(pointer + i * N, pointer + j * N);

}

int main()
{
    int words;
    int j = 0,k=0;
    char str[N];
    char words_for_digits[] = {"0zero1one2two3three4four5five6six7seven8eight9nine0\0"};
    printf("Enter the string:");
    fgets(str,N,stdin);
    char exit[N][N];
    char* pC = &exit[0][0];
    char* pCstart = pC;
    replacement_digit(str,words_for_digits);
    words = change_array(&exit[0][0],str);
    for (int i = 0;i<words;i++){
        while (exit[i][j] != 0){
            printf("%c", exit[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
    }
    printf("\n");
    sorting(&exit[0][0],words);
    while (pC != pCstart+N*words){
        k++;
        while (*pC != 0){
            printf("%c",*pC);
            pC++;
        }
        printf("\n");
        pC = pCstart+N*k;
    }
    // printf("\n%c",exit[1][0]);
}
//массив двумерный с пробелами, а не только вывод
//слова в порядке возрастания длины (одинаковые - по алфавиту)
//добавить замену цифр на слова (0-9)