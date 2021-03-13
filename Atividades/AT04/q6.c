#include<stdio.h>

typedef struct{
    char _1;
    char _2;
    char _3;
}letras;

letras ler3letras(){
    letras letras;
    printf("digite a letra 1 \n");
    scanf("%c", &letras._1);
    getchar();
    printf("digite a letra 2 \n");
    scanf("%c", &letras._2);
    getchar();
    printf("digite a letra 3 \n");
    scanf("%c", &letras._3);
    getchar();
    return letras;
}

void main(){
    letras letras;
    letras = ler3letras();
    printf("%c", letras._1);
    printf("%c", letras._2);
    printf("%c", letras._3);
}