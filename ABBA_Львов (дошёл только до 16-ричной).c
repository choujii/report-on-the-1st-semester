#include <stdio.h>


//Перевод в 16-ричную систему
int abba(int mas[8]){
    char abba[8][8] = {'0'};
    char s[8] = {'0'};
    char alph[] = "0123456789ABCDEF";
    int x;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            x = alph[mas[i] >> (4 * j) & 0xF];
            abba[i][7 - j] = x;
         }
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            printf("%c", abba[i][j]);

        }
        printf("\n");
    }
    return 0;
}


//пример
int main(){
    int sample1[8]={-1413863686, -1146374827,-1162027246,-1442185216,184549376,11534336,655360,179026592};
    int sample2[8]={-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};
    abba(sample1);
    return 0;
}
